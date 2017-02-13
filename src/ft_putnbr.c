/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:30:01 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/16 14:27:18 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static	void	int_min(void)
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void			ft_putnbr(int n)
{
	long	cursor;
	int		numb;

	cursor = 1;
	if (n == -2147483648)
		int_min();
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar('-');
		}
		while (cursor * 10 <= n)
			cursor *= 10;
		while (cursor >= 1)
		{
			numb = n / cursor;
			n -= cursor * numb;
			ft_putchar(numb + '0');
			cursor /= 10;
		}
	}
}
