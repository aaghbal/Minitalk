/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:09:03 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/30 14:23:44 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (len != 0 && ft_strlen(s) > start && ft_strlen(s) != 0)
	{
		if (len > ft_strlen(s))
			p = ft_calloc((ft_strlen(s) - start) + 1, sizeof(char));
		else
			p = ft_calloc(len + 1, sizeof(char));
		if (p == NULL)
			return (NULL);
		i = start;
		j = 0;
		while (len != 0 && s[i] != '\0')
		{
			p[j++] = s[i++];
			len--;
		}
		p[j] = '\0';
		return (p);
	}
	else
		return (ft_strdup(""));
}
