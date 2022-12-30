/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 10:07:42 by aaghbal           #+#    #+#             */
/*   Updated: 2022/11/03 16:38:43 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	if (ft_strlen(s1) != 0 || ft_strlen(s2) != 0)
	{
		p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
		if (p == 0)
			return (NULL);
		while (s1[i] != '\0')
			p[j++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			p[j++] = s2[i++];
		p[j] = '\0';
		return (p);
	}
	return (ft_strdup(""));
}
