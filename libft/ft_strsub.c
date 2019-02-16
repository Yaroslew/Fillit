/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 07:33:58 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/01/01 23:31:22 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	q;

	if (!s)
		return (NULL);
	q = 0;
	res = ft_memalloc(len);
	if (res == NULL)
		return (NULL);
	while (s[start] && q < len)
	{
		res[q] = s[start];
		q++;
		start++;
	}
	if (q != len)
		return (NULL);
	return (res);
}
