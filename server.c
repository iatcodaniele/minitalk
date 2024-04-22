/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:15 by diatco            #+#    #+#             */
/*   Updated: 2024/04/22 14:51:49 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	sig_handler(int signum)
{
	static int	c;
	static int	bit;

	if (signum == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	char				*pid_str;

	pid = getpid();
	pid_str = ft_itoa(pid);
	write(1, "Server PID: ", 12);
	write(1, pid_str, ft_strlen(pid_str));
	write(1, "\nWaiting for message...\n", 25);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		;
	return (0);
}
