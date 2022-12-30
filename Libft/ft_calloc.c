/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:43:38 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/25 11:12:30 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	p = malloc(size * count);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size * count);
	return (p);
}
