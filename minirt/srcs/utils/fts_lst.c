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

#include "minirt.h"

t_lobj	*lobj_new(void *obj, int type)
{
	t_lobj	*new;

	new = malloc(sizeof (t_lobj));
	if (!new)
		return (NULL);
	if (obj)
		new->obj = obj;
	new->type = type;
	new->next = NULL;
	return (new);
}

void	lobj_free(t_lobj **lobj)
{
	t_lobj	*temp;
	t_lobj	*add;

	temp = *lobj;
	while (temp)
	{
		free(temp->obj);
		add = temp->next;
		free(temp);
		temp = add;
	}
	*lobj = NULL;
}

void	lobj_add_back(t_lobj **alst, t_lobj *new)
{
	t_lobj	*temp;

	temp = *alst;
	if (!*alst)
		*alst = new;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = new;
			break ;
		}
		temp = temp->next;
	}
}
