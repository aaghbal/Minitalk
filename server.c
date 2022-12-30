/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:11:18 by aaghbal           #+#    #+#             */
/*   Updated: 2022/12/26 22:13:47 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	checkbit(int param)
{
	int	bit;

	bit = 0;
	if (param == SIGUSR1)
		bit = 1;
	else if (param == SIGUSR2)
		bit = 0;
	return (bit);
}

void	receive_sig(int param, siginfo_t *info, void *ptr)
{
	static char		res;
	static int		i;
	int				bit;
	static int		check;

	if (res == 0)
		check = info->si_pid;
	(void) ptr;
	bit = checkbit(param);
	if (i < 8)
	{
		res = (res << 1) | bit;
		if (check != info->si_pid)
		{
			res = 0;
			i = 0;
		}
		i++;
	}
	if (i == 8)
	{
		write(1, &res, 1);
		res = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = receive_sig;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("Server pid is: ");
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
