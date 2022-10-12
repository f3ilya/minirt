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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstl;

	i = 0;
	dstl = ft_strlen(dst);
	if (dstsize < dstl)
		return (ft_strlen(src) + dstsize);
	while (src[i] && i + 1 + dstl < dstsize)
	{
		dst[dstl + i] = src[i];
		i ++;
	}
	dst[dstl + i] = '\0';
	return (ft_strlen(src) + dstl);
}
