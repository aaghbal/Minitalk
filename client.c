/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:10:40 by aaghbal           #+#    #+#             */
/*   Updated: 2022/12/25 20:20:12 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (ft_atoi(argv[1]) <= 0)
		exit(0);
	if (argc == 3)
	{
		while (argv[2][i])
		{
			send_sig(argv[2][i], ft_atoi(argv[1]));
			i++;
		}
	}
	else
		ft_putstr("Enter two arguments as follows: ./client [pid] [string]");
	return (0);
}
