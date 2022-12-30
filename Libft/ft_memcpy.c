/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:23:13 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/18 15:22:07 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p_dest;
	char	*p_src;
	size_t	i;

	p_dest = dst;
	p_src = (char *)src;
	i = 0;
	if (!p_dest && !p_src)
		return (0);
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dst);
}
