/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:13:36 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/15 08:10:35 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int	count_figurs;
	int	root;

	count_figurs = main_check(argc, argv);
	root = root_area(count_figurs);
	read_figurs(argv);

}
