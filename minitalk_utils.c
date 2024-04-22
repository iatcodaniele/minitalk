/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:06 by diatco            #+#    #+#             */
/*   Updated: 2024/04/22 14:52:25 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;
	char	*str_c;

	i = 0;
	res = 0;
	sign = 1;
	str_c = (char *)str;
	while (((str_c[i] != '\0') && (str_c[i] >= 9 && str_c[i] <= 13))
		|| (str_c[i] == 32))
	{
		i++;
	}
	if (str_c[i] == '-' || str_c[i] == '+')
	{
		if (str_c[i++] == '-')
			sign *= -1;
	}
	while (str_c[i] && (str_c[i] >= '0' && str_c[i] <= '9'))
	{
		res = res * 10;
		res = res + (str_c[i++] - 48);
	}
	return (res * sign);
}

unsigned int	size(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	unsigned int		i;
	char				*number;
	unsigned int		n;

	i = size(nbr);
	number = malloc(sizeof(char) * (i + 1));
	if (!number)
		return (NULL);
	if (nbr < 0)
	{
		number[0] = '-';
		n = -nbr;
	}
	else
		n = nbr;
	if (nbr == 0)
		number[0] = 48;
	number[i] = '\0';
	while (n != 0)
	{
		number[i - 1] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (number);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
