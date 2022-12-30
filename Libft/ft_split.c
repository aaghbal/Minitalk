/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:12:02 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/30 14:00:55 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fc(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (++j);
}

char	*aloc(char const *s, char c)
{
	char	*mot;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	mot = ft_substr(s, 0, i);
	return (mot);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	tab = (char **)ft_calloc (sizeof(char *), (fc(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
		tab[i] = aloc(s, c);
		if (tab[i] == NULL)
		{
			free_tab(tab);
			return (NULL);
		}
		i++;
		while (*s && *s != c)
			s++;
	}
	return (tab);
}
