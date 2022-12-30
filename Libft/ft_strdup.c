/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:07:28 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/30 14:00:03 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	c;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	c = ft_strlen(s1);
	p = (char *)malloc((c + 1) * sizeof(char));
	if (p == 0)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
