/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:15 by diatco            #+#    #+#             */
/*   Updated: 2024/04/19 13:39:56 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signum)
{
	static int	i;
	static int	bit;

	i = 0;
	bit = 0;
	if (signum == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				pid;
	char				*pid_str;

	sa.sa_handler = sig_handler;
	(void)av;
	if (ac != 1)
	{
		write(1, "Error: wrong format.\n", 21);
		write(1, "Try: ./server\n", 14);
	}
	pid = getpid();
	pid_str = ft_itoa(pid);
	write(1, "Server PID: ", 12);
	write(1, pid_str, strlen(pid_str));
	write(1, "\nWaiting for message...\n", 25);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
