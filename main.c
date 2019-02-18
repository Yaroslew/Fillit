/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:13:36 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/16 15:46:40 by pcorlys-         ###   ########.fr       */
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
//	copy = copy_lst(head);
//	head = name_your_function(head, copy, root);
	while (head == NULL)
	{
		root++;
//		head = name_your_function(head, copy, root);
	}
	create_area(head, root);
	free_lst(&head);

}
