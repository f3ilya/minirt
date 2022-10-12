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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*strd;
	char	*strs;
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	strs = (char *) src;
	strd = dest;
	if (dest > src)
	{
		while (n -- > 0)
			strd[n] = strs[n];
	}
	else
	{
		while (i < n)
		{
			strd[i] = strs[i];
			i ++;
		}
	}
	return (dest);
}
