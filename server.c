/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:45:35 by imahri            #+#    #+#             */
/*   Updated: 2023/01/18 03:22:22 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int nb, int pp)
{
	int	res;

	res = 1;
	while (pp)
	{
		res *= nb;
		pp--;
	}
	return (res);
}

void	handler(int signal, siginfo_t *info, void *v)
{
	static unsigned char	byte;
	static int				g_pid;
	static int				i;

	(void)v;
	if (g_pid != info->si_pid)
	{
		byte = 0;
		g_pid = 0;
		i = 7;
		g_pid = info->si_pid;
	}
	if (signal == SIGUSR2)
		byte = byte + ft_pow(2, i) * 1;
	i--;
	if (i == -1)
	{
		ft_putchar(byte);
		i = 7;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	write(1, "\033[0;33m\e[1mThe pid : ", 22);
	write(1, "\033[0m", 5);
	ft_putnbr(pid);
	write (1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
