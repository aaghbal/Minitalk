/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:04:01 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/19 10:58:32 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d;
	size_t	s;
	size_t	c;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	c = d;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (c >= dstsize)
		return (ft_strlen(src) + dstsize);
	while ((c < dstsize - 1) && src[i] != '\0')
	{
		dst[c] = src[i];
		c++;
		i++;
	}
	dst[c] = '\0';
	return (d + s);
}
