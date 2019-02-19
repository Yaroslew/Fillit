/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:13:36 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/19 19:32:58 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int				count_figurs;
	unsigned short	root;
	t_crd			*head;
	t_crd			*copy;

	count_figurs = main_check(argc, argv);
	head = read_figurs(argv);
	root = root_area(count_figurs, head) - 1;
	copy = NULL;
	while (copy == NULL)
	{
		copy = fill_it(head, copy, root);
		root++;
	}
	create_area(copy, root);
	free_lst(&copy);
	free_lst(&head);
}
