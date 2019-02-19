/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:13:36 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/19 18:33:37 by pcorlys-         ###   ########.fr       */
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
	head = read_figurs(argv);
	root = root_area(count_figurs, head);
	copy = fill_it(head, copy = NULL, (unsigned short)root - 1);
	while (copy == NULL)
	{
		root++;
		copy = fill_it(head, copy, (unsigned short)root - 1);
	}
	create_area(head, root);
	free_lst(&head);

}
