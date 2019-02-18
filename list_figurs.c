/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_figurs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 08:02:54 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/16 14:28:43 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		sort_tetraminos_ver(char **temp)
{
	int 		q;
	int 		flag;
	char 		*raz;

	q = 0;
	flag = 0;
	raz = *temp;
	if (raz[0] != '#' && raz[1] != '#' && raz[2] != '#' && raz[3] != '#')
		while (raz[q])
		{
			if (raz[q] == '#')
			{
				raz[q] = '.';
				raz[q - 5] = '#';
				flag++;
			}
			q++;
		}
	if (flag)
		sort_tetraminos_ver(temp);
}

static void		sort_tetraminos_hor(char **temp)
{
	int 		q;
	int 		flag;
	char 		*raz;

	q = 0;
	flag = 0;
	raz = *temp;
	if (raz[0] != '#' && raz[5] != '#' && raz[10] != '#' && raz[15] != '#')
		while (raz[q])
		{
			if (raz[q] == '#')
			{
				raz[q] = '.';
				raz[q - 1] = '#';
				flag++;
			}
			q++;
		}
	if (flag)
		sort_tetraminos_hor(temp);
}
static void	record(t_crd *node, char *temp)
{
	int 	q;
	int 	r;
	int 	t;
	int		z;

	q = 0;
	r = 0;
	t = 0;
	z = 0;
	while (temp[q])
	{
		if (temp[q] == '\n')
		{
			r++;
			z += 5;
		}
		if (temp[q] == '#')
		{
			node->x[t] = q - z;
			node->y[t] = r;
			t++;
		}
		q++;
	}
	node->next = NULL;
}

static t_crd	*create_lst(t_crd *head, char *temp)
{
	t_crd		*copy;

	if (head == NULL)
	{
		head = malloc(sizeof(t_crd));
		head->next = NULL;
		record(head, temp);
		return (head);
	}
	copy = head;
	while (copy->next != NULL)
		copy = copy->next;
	copy->next = malloc(sizeof(t_crd));
	copy = copy->next;
	copy->next = NULL;
	record(copy, temp);

	return (head);
}

t_crd 		*read_figurs(char **argv)
{
	int		fd;
	char 	*temp;
	t_crd 	*head;

	head = NULL;
	temp = ft_strnew(21);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, temp, 21))
	{
		sort_tetraminos_ver(&temp);
		sort_tetraminos_hor(&temp);
		head = create_lst(head, temp);
	}
	ft_strdel(&temp);
	close(fd);
	return (head);
}