/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:13:36 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/16 12:00:55 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int	count_figurs;
	int	root;
	t_crd	*head;
	t_crd	*copy;

	count_figurs = main_check(argc, argv);
	root = root_area(count_figurs);
	head = read_figurs(argv);
	copy = head;
	// твоя функция ниже.
	head = name_your_function(head, copy, root);
	while (head == NULL)
	{
		root++;
		head = name_your_function(head, copy, root);
	}




}
