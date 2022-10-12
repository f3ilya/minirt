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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = ft_strlen(s);
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (0);
	if (start > ft_strlen(s))
		dest[0] = 0;
	else
		ft_strlcpy(dest, (char *) s + start, len + 1);
	return (dest);
}
