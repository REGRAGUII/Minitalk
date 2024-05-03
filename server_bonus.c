/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:45:01 by yregragu          #+#    #+#             */
/*   Updated: 2024/05/03 22:32:07 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <unistd.h>


void ft_putnbr(int nbr)
{
	char c;

	if (9 < nbr)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int handel_pid(int *pid, int info_pid)
{
	if (*pid == 0)
		*pid = info_pid;
	if (*pid != info_pid)
	{
		if (kill(*pid, 0) == -1)
		{
			*pid = 0;
			return (1);
		}
		else
			kill(info_pid, SIGUSR2);
	}
	return (0);
}

void message_handler(int signum, siginfo_t *info, void *pointer)
{
	static int count;
	static char c;
	static int pid;

	(void)pointer;
	if (handel_pid(&pid, info->si_pid))
		count = 0;
	c = (c << 1) | (signum == SIGUSR1);
	count++;
	if (count % 8 == 0)
	{
		if (!c)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
			pid = 0;
		}
		else
			write(1, &c, 1);
		count = 0;
		c = '\0';
	}
	kill(info->si_pid, SIGUSR1);
}

int main(int ac, char **av)
{
	struct sigaction signal;
	int pid;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		ft_putnbr(pid);
		write(1, "\n", 1);
		signal.sa_flags = SA_SIGINFO;
		signal.sa_sigaction = message_handler;
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);

		while (1)
		{
			pause();
		}
		return (0);
	}
	return (1);
}