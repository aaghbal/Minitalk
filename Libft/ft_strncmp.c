/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:52:44 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/20 18:52:28 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (s1[i] != '\0' && s1[i] != '\0'))
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
		return (1);
	if (((unsigned char *)s1)[i] < ((unsigned char *)s2)[i])
		return (-1);
	return (0);
}
