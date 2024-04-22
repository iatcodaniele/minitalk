/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:10 by diatco            #+#    #+#             */
/*   Updated: 2024/04/22 14:52:22 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>
# include <stdio.h>

unsigned int	size(int nb);
int				ft_atoi(const char *str);
int				ft_strlen(const char *str);
char			*ft_itoa(int nbr);

#endif
