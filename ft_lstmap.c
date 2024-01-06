/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:38:52 by maweiss           #+#    #+#             */
/*   Updated: 2023/12/07 11:38:54 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*flst;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	flst = NULL;
	while (lst)
	{
		nlst = ft_lstnew((lst->content));
		if (nlst == NULL)
		{
			ft_lstclear(&flst, (*del));
			return (NULL);
		}
		nlst->content = (*f)(nlst->content);
		ft_lstadd_back(&flst, nlst);
		lst = lst->next;
	}
	return (flst);
}
