/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:57:06 by imahri            #+#    #+#             */
/*   Updated: 2023/01/18 00:36:49 by imahri           ###   ########.fr       */
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

void	unicode(unsigned char pr, siginfo_t *info, t_univar *uni)
{
	if (uni->nb_byte == 0 && pr >= 0 && pr < 128)
	{
		if (pr == '\0')
			kill(info->si_pid, SIGUSR1);
		ft_putchar(pr);
	}
	else if (uni->nb_byte == 0 && pr >= 192 && pr < 224)
		uni->nb_byte = 2;
	else if (uni->nb_byte == 0 && pr >= 224 && pr < 240)
		uni->nb_byte = 3;
	else if (uni->nb_byte == 0 && pr >= 240)
		uni->nb_byte = 4;
	if (uni->i < uni->nb_byte)
		uni->byte[uni->i++] = pr;
	if (uni->i == uni->nb_byte)
	{
		uni->i = 0;
		while (uni->i < uni->nb_byte)
			ft_putchar(uni->byte[uni->i++]);
		uni->nb_byte = 0;
		ft_bzero(uni->byte, 4);
		uni->i = 0;
	}
}

void	handler(int signal, siginfo_t *info, void *v)
{
	static t_univar			uni;
	static unsigned char	pr;
	static int				g_pid;
	static int				i;

	(void)v;
	if (g_pid != info->si_pid)
	{
		ft_bzero(uni.byte, 4);
		uni.i = 0;
		uni.nb_byte = 0;
		i = 7;
		pr = 0;
		g_pid = info->si_pid;
	}
	if (signal == SIGUSR2)
		pr = pr + ft_pow(2, i) * 1;
	i--;
	if (i == -1)
	{
		unicode(pr, info, &uni);
		i = 7;
		pr = 0;
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
