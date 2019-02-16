/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:10:32 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/16 15:05:20 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_lst(t_crd **lst)
{
	t_crd	*copy;
	t_crd	*head;

	head = *lst;
	while (head)
	{
		copy = head->next;
		if (copy != NULL)
			free(head->next);
		head->next = NULL;
		free(head);
		head = copy;
	}
}
