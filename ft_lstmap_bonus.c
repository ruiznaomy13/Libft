/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:28:10 by ncastell          #+#    #+#             */
/*   Updated: 2024/01/24 17:00:52 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*nod;
	void	*p;

	new = 0;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		p = (f)(lst->content);
		nod = ft_lstnew(p);
		if (!nod)
		{
			ft_lstclear(&new, del);
			free(p);
			return (NULL);
		}
		ft_lstadd_back(&new, nod);
		lst = lst->next;
	}
	return (new);
}
