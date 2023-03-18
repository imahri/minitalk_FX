/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:56:47 by imahri            #+#    #+#             */
/*   Updated: 2023/01/18 00:42:31 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char c)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (c >> i & 1);
		if (bit == 0)
			kill (pid, SIGUSR1);
		if (bit == 1)
			kill (pid, SIGUSR2);
		usleep(800);
	}
}

void	very_well(int signal)
{
	if (signal == SIGUSR1)
		write (1, "\033[0;32m\e[1mEverything was received ✅\n", 40);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{	
		pid = ft_atoi(av[1]);
		signal(SIGUSR1, &very_well);
		if (pid <= 0)
		{
			write (2, "\033[0;31m\e[1mInvalid PID ❎\n", 28);
			exit(1);
		}
		while (av[2][i])
			send_signal(pid, av[2][i++]);
		send_signal(pid, '\0');
	}
	else
		write(2, "\033[0;31m\e[1mError Args ❎\n", 27);
	return (0);
}
