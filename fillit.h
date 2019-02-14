/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 08:22:47 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/14 07:10:56 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H

#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"


#include <stdio.h> // Забудешь удалить, убью!

typedef struct	s_coordinates
{
	unsigned short x[4];
	unsigned short y[4];
	struct s_coordinates	*next;
} t_crd;


int 		main_check(int argc, char **argv);
void		message_error(int a, char c); // удали символ ошибки!
int			root_area(int count);
void		read_figurs(char **argv);




#endif
