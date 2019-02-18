/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 07:23:49 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/18 15:43:44 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int check_lst(t_crd *head)
{
	int 	flag;

	flag = 0;
	while (head)
	{
		if (head->y[0] == 0 &&  head->y[1] == 0 && head->y[2] == 0 && head->y[3] == 0)
			flag++;
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
	if (root < 4 && flag != 0)
		root = 4;
	return (root);
}
