/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 08:22:47 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/01/24 16:34:19 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H

#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"


#include <stdio.h> // Забудешь удалить, убью!




int 		main_check(int argc, char **argv);
void		message_error(int a);
char		**square(int count);
char		***create_array_figurs(char **argv, int count);



#endif
