/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:47:38 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/01/26 17:23:36 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char **s1, char *s2, size_t num)
{
	size_t	q;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	q = ft_strlen(*s1);
	res = ft_memalloc(q + num);
	if (res == NULL)
		return (NULL);
	res = ft_strcpy(res, *s1);
	res = ft_strncat(res, s2, num);
	ft_strdel(s1);
	return (res);
}
