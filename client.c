/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:24 by diatco            #+#    #+#             */
/*   Updated: 2024/04/19 15:46:54 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

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

    // int		i;
	// int		s_pid;
	// char	*octet;

	// i = 0;
	// if (argc != 3)
	// {
	// 	printf("You did something wrong...\n");
	// 	return (1);
	// }
	// s_pid = ft_atoi(argv[1]);
	// if (s_pid <= 0)
	// {
	// 	printf("What about the PID");
	// 	return (1);
	// }
	// octet = argv[2];
	// while (*octet)
	// {
	// 	sig_killer(s_pid, *octet);
	// 	octet++;
	// }
	// sig_killer (s_pid, '\0');
	// return (0);
}
