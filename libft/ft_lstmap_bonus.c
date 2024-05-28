/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:58:54 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/21 14:16:45 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*changed_list;
	t_list	*changed_elem;

	changed_list = NULL;
	while (lst)
	{
		changed_elem = ft_lstnew(f(lst->content));
		if (!changed_elem)
		{
			ft_lstclear(&changed_list, del);
			return (NULL);
		}
		ft_lstadd_back(&changed_list, changed_elem);
		lst = lst->next;
	}
	return (changed_list);
}
