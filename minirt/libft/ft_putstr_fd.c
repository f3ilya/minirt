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

#include <unistd.h>

void	ft_putstr_fd(const char *s, const int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}
