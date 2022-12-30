/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:28:59 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/26 09:55:05 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft(int n, int j)
{
	char	*tab;

	tab = (char *)malloc(sizeof(char) * j);
	if (tab == 0)
		return (0);
	if (n == 0)
	{
		tab[0] = '0';
		tab[1] = '\0';
	}
	j = j - 2;
	while (n != 0)
	{
		tab[j] = (n % 10) + '0';
		n /= 10;
		j--;
	}
	return (tab);
}

int	fc(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		num;
	char	*tab;

	num = fc (n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		tab = ft(n, num + 2);
		tab[0] = '-';
		num++;
	}
	else
		tab = ft(n, num + 1);
	tab[num] = '\0';
	return (tab);
}
