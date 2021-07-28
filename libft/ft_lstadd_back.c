/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 01:14:57 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 17:04:01 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*el;

	el = NULL;
	if (lst && new)
	{
		if (*lst)
		{
			el = ft_lstlast(*lst);
			el->next = new;
			new->next = NULL;
		}
		else
		{
			*lst = new;
			new->next = NULL;
		}
	}
}
