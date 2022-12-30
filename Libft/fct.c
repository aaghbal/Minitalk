/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:49:20 by aaghbal           #+#    #+#             */
/*   Updated: 2022/11/18 16:13:38 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fct(size_t n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n > 15)
	{
		i += fct (n / 16);
		i += fct (n % 16);
	}
	else
		i += ft_putchar(base[n]);
	return (i);
}
