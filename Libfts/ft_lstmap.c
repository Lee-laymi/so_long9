/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:19:45 by skrairab          #+#    #+#             */
/*   Updated: 2022/04/07 00:19:22 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*end;
	t_list	*start;

	if (lst == NULL || f == NULL)
		return (NULL);
	start = 0;
	while (lst)
	{
		end = ft_lstnew(f(lst->content));
		if (end == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, end);
		lst = lst->next;
	}
	return (start);
}
