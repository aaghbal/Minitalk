/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:07:27 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/21 16:59:56 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)(haystack));
	while (haystack[i] != '\0')
	{
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j] == '\0')
				return (((char *)haystack + i));
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		j = 0;
		i++;
	}
	return (NULL);
}
