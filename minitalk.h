/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:40:26 by imahri            #+#    #+#             */
/*   Updated: 2023/01/18 02:17:29 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>

typedef struct s_univar
{
	unsigned char	byte[4];
	int				nb_byte;
	int				i;
}	t_univar;

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
void	ft_bzero(void *str, size_t n);

int		ft_atoi(const char *str);

#endif