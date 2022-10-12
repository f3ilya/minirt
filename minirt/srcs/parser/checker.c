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

int	is_number_param_valid(int expected, char **params)
{
	return (expected == ft_strlen_char_tab(params));
}

int	is_double_correct(const char *nb)
{
	int	i;
	int	first_pt;

	i = 0;
	first_pt = 1;
	while (nb[i])
	{
		if ((nb[i] == '-' || nb[i] == '+'))
		{
			if (i != 0)
				return (0);
		}
		else if (nb[i] == '.')
		{
			if (first_pt)
				first_pt = 0;
			else
				return (0);
		}
		else if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (!(i > 15 && (first_pt || i > 16)));
}

int	is_coords_valid(char *to_split)
{
	char	**coord;
	int		ret;
	int		i;

	coord = ft_split(to_split, ',');
	if (!coord)
		return (0);
	ret = 1;
	if (ft_char_cpt(to_split, ',') != 2 || ft_strlen_char_tab(coord) != 3)
		ret = 0;
	i = 0;
	while (ret && coord[i])
	{
		if (!is_double_correct(coord[i++]))
			ret = 0;
	}
	ft_free_char_tab(coord);
	return (ret);
}

int	is_normalized_vector(char *to_split)
{
	char	**coord;
	int		ret;
	int		i;

	coord = ft_split(to_split, ',');
	if (!coord)
		return (0);
	ret = 1;
	if (ft_char_cpt(to_split, ',') != 2 || ft_strlen_char_tab(coord) != 3)
		ret = 0;
	i = 0;
	while (ret && coord[i])
	{
		if (!is_double_correct(coord[i])
			|| ft_atoi_double(coord[i]) < -1
			|| ft_atoi_double(coord[i]) > 1)
			ret = 0;
		i++;
	}
	ft_free_char_tab(coord);
	return (ret);
}

int	is_color_valid(char *to_split)
{
	char	**color;
	int		value;
	int		ret;
	int		i;

	color = ft_split(to_split, ',');
	if (!color)
		return (0);
	ret = 1;
	if (ft_char_cpt(to_split, ',') != 2 || ft_strlen_char_tab(color) != 3)
		ret = 0;
	i = 0;
	while (ret && color[i])
	{
		value = ft_positive_atoi(color[i++]);
		if (value < 0 || value > 255)
			ret = 0;
	}
	ft_free_char_tab(color);
	return (ret);
}
