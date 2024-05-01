/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:40:49 by yregragu          #+#    #+#             */
/*   Updated: 2024/05/02 00:55:17 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


int ft_atoi(char *str)
{
	int x;
	int n;
	
	x = 0;
	n = 0;
	while (str[x] >= '0' && str [x] <= '9')
	{
		n = n * 10 + str[x] - '0';
		x++;
	}
	if (str[x])
		return (0);
	return (n); 
}

size_t ft_strlen(char *str)
{
	size_t i;
	
	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return(i);
}

char *message;

void send(int pid)
{
	static size_t	i;
	static size_t	len;
	static int	bit;

	bit = 0;
	len = ft_strlen(message);
	if (i < len)
	{
		if ((message[i] >> (7 - bit)) & 1)
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
	if(pointer)
		pointer = NULL;
	if (SIGUSR1 == signum)
		send(info->si_pid);
	else if(SIGUSR2 == signum)
		exit(1);
}

int main(int ac, char **av)
{
	int	pid;
	struct sigaction	signal;
	
	if (ac == 3)
	{
		pid = ft_atoi(av[2]);
		message = av[3];
	
		signal.sa_flags = SA_SIGINFO;		//special to affect behavior of signal   //sa_mask : additional set of signals to be blocked during execution of signal catching function
		signal.sa_sigaction = handler;		//apointer to a signal catching function 
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		send(pid);
		
		while(1)
		{
			pause();		
		}
		return(0);
	}
	return(1);
	
}