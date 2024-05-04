/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:07:44 by yregragu          #+#    #+#             */
/*   Updated: 2024/05/04 14:47:02 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	x;
	int	n;

	x = 0;
	n = 0;
	while (str[x] >= '0' && str[x] <= '9')
	{
		n = n * 10 + str[x] - '0';
		x++;
	}
	if (str[x])
		return (0);
	return (n);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static char	*g_message;

void	send_bit(int pid)
{
	static size_t	i;
	static size_t	len;
	static int		bit;

	len = ft_strlen(g_message);
	if (i <= len)
	{
		if ((g_message[i] >> (7 - bit)) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		if (bit % 8 == 0)
		{
			i++;
			bit = 0;
		}
	}
}

void	handler(int signum, siginfo_t *info, void *pointer)
{
	(void)pointer;
	if (SIGUSR1 == signum)
		send_bit(info->si_pid);
	else if (SIGUSR2 == signum)
		exit(1);
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	signal;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		g_message = av[2];
		if (pid == 0 || kill(pid, 0) == -1)
		{
			write(1, "wrong pid\n", 9);
			exit(1);
		}
		signal.sa_flags = SA_SIGINFO;
		signal.sa_sigaction = handler;
		sigemptyset(&signal.sa_mask);
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		send_bit(pid);
		while (1)
			pause();
		return (0);
	}
	return (1);
}
