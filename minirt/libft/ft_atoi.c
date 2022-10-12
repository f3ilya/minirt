/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:12:05 by                   #+#    #+#             */
/*   Updated: 2021/12/25 18:53:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	int		sign;
	long	dest;

	i = 0;
	sign = 1;
	dest = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i ++;
	}
	while (ft_isdigit(str[i]))
	{
		dest = dest * 10 + str[i] - '0';
		i ++;
	}
	return ((int)sign * dest);
}

int	ft_positive_atoi(const char *nptr)
{
	long		nb;

	nb = 0;
	while (*nptr && ft_isdigit(*nptr))
	{
		nb = (nb * 10) + (*nptr - '0');
		nptr++;
	}
	if (*nptr)
		return (-1);
	return ((int)nb);
}

int	atoi_double_sign(const char *str)
{
	int		sign;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	return (sign);
}

double	ft_atoi_double(const char *str)
{
	int		sign;
	double	nb;
	int		cpt_pt;

	sign = atoi_double_sign(str);
	if (*str == '+' || *str == '-')
		str++;
	nb = 0;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	if (*str == '.')
	{
		cpt_pt = 1;
		while (ft_isdigit(*(++str)))
		{
			nb = nb * 10 + *str - '0';
			cpt_pt *= 10;
		}
		nb /= cpt_pt;
	}
	return (sign * nb);
}
