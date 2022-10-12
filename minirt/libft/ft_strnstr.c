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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlel;

	i = 0;
	needlel = ft_strlen(needle);
	if (len < needlel)
		return (0);
	if (needlel == 0)
		return ((char *) haystack);
	while (haystack[i] && i <= len - needlel && len > 0)
	{
		if (ft_strncmp(haystack + i, needle, needlel) == 0)
			return ((char *) haystack + i);
		i ++;
	}
	return (NULL);
}
