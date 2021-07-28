/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 02:14:40 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 17:04:07 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	ptr = NULL;
	if ((*del) && lst && *lst)
	{
		while (lst && *lst)
		{
			ptr = (*lst)->next;
			ft_lstdelone(*lst, (*del));
			*lst = ptr;
		}
	}
}
