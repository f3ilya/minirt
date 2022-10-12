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
#include "struct.h"

t_pt	*init_pt(t_pt *point, char *input)
{
	char	**coord;

	coord = ft_split(input, ',');
	if (!coord)
		return (NULL);
	point->x = ft_atoi_double(coord[0]);
	point->y = ft_atoi_double(coord[1]);
	point->z = ft_atoi_double(coord[2]);
	ft_free_char_tab(coord);
	return (point);
}

int	*init_color(int color[3], char *input)
{
	char	**rgb;
	int		i;

	rgb = ft_split(input, ',');
	if (!rgb)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		color[i] = ft_positive_atoi(rgb[i]);
		i++;
	}
	ft_free_char_tab(rgb);
	return (color);
}
