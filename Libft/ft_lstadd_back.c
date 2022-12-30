/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:49:38 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/28 11:13:10 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			p = ft_lstlast(*lst);
			p->next = new;
		}
	}
}
