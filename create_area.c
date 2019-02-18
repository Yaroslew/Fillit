/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_area.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:01:11 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/16 14:03:54 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char 	**reading_lst(t_crd *head, char **res)
{
	char 		ch;

	ch = 'A';
	while (head)
	{
		res[head->y[0]][head->x[0]] = ch;
		res[head->y[1]][head->x[1]] = ch;
		res[head->y[2]][head->x[2]] = ch;
		res[head->y[3]][head->x[3]] = ch;
		ch++;
		head = head->next;
	}
	return (res);
}

static void 	writing(char **res)
{
	int			q;

	q = 0;
	while (res[q])
	{
		ft_putstr(res[q]);
		ft_putchar('\n');
		q++;
	}
}

void			create_area(t_crd *head, int root)
{
	char		**res;
	int			q;

	q = 0;
	res = (char**)malloc(sizeof(char*) * (root + 1));
	res[root] = NULL;
	while (q != root)
	{
		res[q] = ft_strnew(root);
		res[q] = ft_memset((void*)res[q], 46, root);
		q++;
	}
	res = reading_lst(head, res);
	writing(res);
	q = 0;
	while (q != root)
	{
		ft_strdel(&res[q]);
		q++;
	}
	free(res);
	res = NULL;
}
