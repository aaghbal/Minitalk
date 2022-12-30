/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:45:56 by aaghbal           #+#    #+#             */
/*   Updated: 2022/12/27 18:45:58 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_var{
	char	res;
	int		i;
	int		check;
}	t_var;

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
	static t_var	var;
	int				bit;

	if (var.res == 0)
		var.check = info->si_pid;
	(void) ptr;
	bit = checkbit(param);
	if (var.i < 8)
	{
		var.res = (var.res << 1) | bit;
		if (var.check != info->si_pid)
		{
			var.res = 0;
			var.i = 0;
		}
		var.i++;
	}
	if (var.i == 8)
	{
		write(1, &var.res, 1);
		if (var.res == '\0')
			kill(info->si_pid, SIGUSR2);
		var.res = 0;
		var.i = 0;
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
