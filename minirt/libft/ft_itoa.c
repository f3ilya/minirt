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
#include <stdio.h>

static int	ft_intlen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		i = 1;
	else
	{
		while (n != 0)
		{
			n = n / 10;
			i ++;
		}
	}
	return (i);
}

static char	*ft_make_empty_str(int n, int i)
{
	int		s;
	char	*dest;

	s = 0;
	if (n < 0)
		s = 1;
	dest = malloc(sizeof (char) * (s + i + 1));
	if (!dest)
		return (0);
	dest [s + i] = 0;
	return (dest);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	int		s;
	char	*dest;

	i = ft_intlen(n);
	s = 0;
	nb = n;
	dest = ft_make_empty_str(n, i);
	if (!dest)
		return (0);
	if (n < 0)
	{
		dest[0] = '-';
		s = 1;
		nb = -nb;
		i ++;
	}
	while (i > s)
	{
		dest[i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i --;
	}
	return (dest);
}
