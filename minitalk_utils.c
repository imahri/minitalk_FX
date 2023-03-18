/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahri <imahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:11:41 by imahri            #+#    #+#             */
/*   Updated: 2023/01/17 23:48:04 by imahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < n)
	{
		if (s[i] != '\0')
			s[i] = '\0';
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;
	int	pre;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		pre = res;
		res = str[i] - '0' + (res * 10);
		i++;
	}
	return (res * sign);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
			ft_putstr("-2147483648");
		else
		{
			nb *= -1;
			ft_putchar('-');
		}
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	if (nb >= 10)
	{
		ft_putnbr((nb / 10));
		ft_putnbr((nb % 10));
	}
}
