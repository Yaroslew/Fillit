/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 08:22:47 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/19 20:52:50 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H

#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct				s_coordinates
{
	unsigned short 			x[4];
	unsigned short 			y[4];
	struct s_coordinates	*next;
} 							t_crd;

int 		main_check(int argc, char **argv);
void		message_error(int a);
int			root_area(int count, t_crd *head);
t_crd		*read_figurs(char **argv);
void		create_area(t_crd *head, int root);
void		free_lst(t_crd **lst);
t_crd		*fill_it(t_crd *base, t_crd *ss, unsigned short border);

#endif
