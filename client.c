/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:45:24 by imahri            #+#    #+#             */
/*   Updated: 2023/01/19 17:40:29 by imahri           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write (2, "\033[0;31m\e[1mInvalid PID ❎\n", 28);
			exit(1);
		}		
		while (av[2][i])
			send_signal(pid, av[2][i++]);
	}
	else
		write(2, "\033[0;31m\e[1mError Args ❎\n", 27);
	return (0);
}
