/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:25:30 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/26 14:31:30 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ds;
	const char	*sr;
	char		*d;
	const char	*s;

	ds = dst;
	sr = src;
	if (!ds && !sr)
		return (0);
	if (ds < sr)
		ft_memcpy(ds, sr, len);
	else
	{
		d = ds + (len - 1);
		s = sr + (len - 1);
		while (len != 0)
		{
			*d-- = *s--;
			len--;
		}
	}
	return (dst);
}
