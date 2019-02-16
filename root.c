/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 07:23:49 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/01/23 08:06:12 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		root_area(int count)
{
	int		sum;
	int		root;

	root = 2;
	sum = count * 4;
	while ((root * root) < sum)
		root++;
	return (root);
}
