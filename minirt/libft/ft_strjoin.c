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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	size_t	dst_size;
	size_t	i;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	dst_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(sizeof(char) * dst_size);
	if (!dst)
		return (NULL);
	i = 0;
	while (*s1)
		dst[i++] = *(s1++);
	while (*s2)
		dst[i++] = *(s2++);
	dst[i] = '\0';
	return (dst);
}
