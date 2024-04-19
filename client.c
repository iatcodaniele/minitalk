/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:24 by diatco            #+#    #+#             */
/*   Updated: 2024/04/19 13:51:20 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(900);
		bit++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (*av[2] != '\0')
		{
			send_bits(pid, *av[2]);
			av[2]++;
		}
		send_bits(pid, '\n');
	}
	else
	{
		write(1, "Wrong format.\n", 14);
		write(1, "Try: ./client <PID> <MESSAGE>\n", 30);
		return (1);
	}
	return (0);
}
