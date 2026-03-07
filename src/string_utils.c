/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanuel- <cmanuel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:34:33 by cmanuel-          #+#    #+#             */
/*   Updated: 2025/08/09 18:20:53 by cmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (!s1 || !s2 || n <= 0)
		return (-1);
	while (*s1 == *s2 && *s1 && n--)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

double	ft_atodbl(char *s)
{
	double	result;
	double	divisor;
	int		sign;

	result = 0;
	divisor = 0.1;
	sign = 1;
	while ((*s >= 0 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s != '.' && *s)
		result = (result * 10.0) + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s)
	{
		result = result + (*s++ - 48) * divisor;
		divisor *= 0.1;
	}
	return (sign * result);
}
