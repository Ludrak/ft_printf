/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:08:49 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/04 18:49:42 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*aux;
	t_list	*aux2;

	if (!lst || !del)
		return ;
	current = *lst;
	aux = current;
	while (current)
	{
		aux2 = current;
		del(current->content);
		current = current->next;
		free(aux2);
	}
	aux->next = NULL;
}
