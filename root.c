/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 07:23:49 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/18 16:06:41 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int check_lst(t_crd *head)
{
	int 	flag;

	flag = 0;
	while (head)
	{
		if ((head->y[1] == head->y[2] && (head->y[1] == head->y[0] || head->y[1] == head->y[3])
		|| (head->x[1] == head->x[2] && (head->x[1] == head->x[0] || head->x[1] == head->x[3]))))
			flag = 2;
		if ((head->y[0] == head->y[1] &&  head->y[1] == head->y[2]
		&& head->y[2] == head->y[3]) || (head->x[0] == head->x[1]
		&& head->x[1] == head->x[2] && head->x[2] == head->x[3]))
			flag = 1;
		head = head->next;
	}
	return (flag);
}

int		root_area(int count, t_crd *head)
{
	int		sum;
	int		root;
	int		flag;

	flag = check_lst(head);
	root = 2;
	sum = count * 4;
	while ((root * root) < sum)
		root++;
	if (root < 4 && flag == 1)
		root = 4;
	if (root < 4 && flag == 2)
		root = 3;
	return (root);
}
