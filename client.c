/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:24 by diatco            #+#    #+#             */
/*   Updated: 2024/04/22 15:01:15 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write(1, "Invalid PID.\n", 13);
			return (1);
		}
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
