/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 07:08:42 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/19 20:44:10 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	paragraphs(char *temp, int buff)
{
	int		q;
	int		count;

	q = 0;
	count = 0;
	if (temp[4] != '\n' || temp[9] != '\n' || temp[14] != '\n'
		|| temp[19] != '\n')
		message_error(1);
	if (buff == 21 && temp[20] != '\n')
		message_error(1);
	while (temp[q])
	{
		if (temp[q] != '.' && temp[q] != '#' && temp[q] != '\n')
			message_error(1);
		if (temp[q] == '\n')
			count++;
		q++;
	}
	if (count != 4 && count != 5)
		message_error(1);
}

static void	tetraminos(char *temp)
{
	int		q;
	int		count;
	int		connect;

	q = 0;
	count = 0;
	connect = 0;
	while (temp[q])
	{
		if (temp[q] == '#')
		{
			count++;
			if (temp[q - 5] == '#')
				connect++;
			if (temp[q + 5] == '#')
				connect++;
			if (temp[q + 1] == '#')
				connect++;
			if (temp[q - 1] == '#')
				connect++;
		}
		q++;
	}
	if (connect < 6 || connect > 8 || count != 4)
		message_error(1);
}

static int	reader(int fd, char *temp)
{
	int		buff;
	int		check;
	int		count;

	buff = 1;
	count = 0;
	while (buff)
	{
		check = buff;
		if ((buff = read(fd, temp, 21)) > 0)
			count++;
		else if (buff < 0)
			message_error(1);
		else if (buff == 0)
			return (count);
		paragraphs(temp, buff);
		tetraminos(temp);
	}
	if (check != 20 || check == 1)
		message_error(1);
	if (count > 26)
		message_error(1);
	return (count);
}

int			main_check(int argc, char **argv)
{
	int		fd;
	char	*temp;
	int		count;

	if (argc != 2)
		message_error(0);
	fd = open(argv[1], O_RDONLY);
	if (!(temp = ft_strnew(21)))
		return (-1);
	count = reader(fd, temp);
	free(temp);
	close(fd);
	return (count);
}
