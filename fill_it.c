/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaegar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:22:17 by orhaegar          #+#    #+#             */
/*   Updated: 2019/02/19 19:24:44 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		mv_dl(t_crd *f, t_crd *b, unsigned short border)
{
	short i;

	i = 0;
	while (i < 4)
		if (f->y[i] < border)
		{
			f->x[i] = b->x[i];
			++f->y[i++];
		}
		else
			return (1);
	return (0);
}

int		mv_r(t_crd *f, unsigned short border)
{
	short i;

	i = -1;
	while (++i < 4)
		if (f->x[i] < border)
			++f->x[i];
		else
			return (1);
	return (0);
}

int		mv(t_crd *f, t_crd *b, unsigned short border)
{
	if (mv_r(f, border))
		if (mv_dl(f, b, border))
			return (0);
	return (1);
}

int		detect_collision(t_crd *lst, t_crd *b)
{
	short i;
	short j;
	
	while (lst)
	{
		i = 0;
		while (i < 4)
		{
			j = -1;
			while (++j < 4)
				if ((lst->x[i] == b->x[j]) && (lst->y[i] == b->y[j]))
					return (1);
			++i;
		}
		lst = lst->next;
	}
	return (0);
}

int	append_figure(t_crd *new, t_crd **lst)
{
	short i;

	while (*lst)
		lst = &(*lst)->next;
	if (!(*lst = (t_crd *)malloc(sizeof(t_crd))))
		return (1);
	i = 0;
	while (i < 4)
	{
		(*lst)->x[i] = new->x[i];
		(*lst)->y[i] = new->y[i];
		++i;
	}
	(*lst)->next = NULL;
	return (0);
}

int	del_last(t_crd **ss)
{
	if (*ss == NULL)
		return (1);
	while ((*ss)->next)
		ss = &(*ss)->next;
	free(*ss);
	*ss = NULL;
	return (0);
}

t_crd	*fill_it(t_crd *base, t_crd *ss, unsigned short border)
{
	t_crd	tmp;
	int			flag;

	if (base)
		tmp = *base;
	else
		return (ss);
	flag = 1;
	while (flag)
	{
		if (detect_collision(ss, &tmp))
			flag = mv(&tmp, base, border);
		else
		{
			append_figure(&tmp, &ss);
			if (fill_it(base->next, ss, border) == NULL)
			{
				del_last(&ss);
				flag = mv(&tmp, base, border);
			}
			else
				return (ss);
		}
	}
	return (NULL);
}
