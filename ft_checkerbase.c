/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:44:14 by cmorales          #+#    #+#             */
/*   Updated: 2022/05/31 17:49:01 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_decimal(unsigned int pos, int tc)
{
	char	*numbers;

	numbers = "0123456789";
	if (pos >= 10)
	{
		tc = check_decimal(pos / 10, tc);
		tc = check_decimal(pos % 10, tc);
	}
	else
	{
		ft_putchar_fd(numbers[pos], 1);
		tc++;
	}
	return (tc);
}

int	check_lower_hexa(unsigned int pos, int tc)
{
	char	*numbers;

	numbers = "0123456789abcdef";
	if (pos >= 16)
	{
		tc = check_lower_hexa(pos / 16, tc);
		tc = check_lower_hexa(pos % 16, tc);
	}
	else
	{
		ft_putchar_fd(numbers[pos], 1);
		tc++;
	}
	return (tc);
}

int	check_upper_hexa(unsigned int pos, int tc)
{
	char	*numbers;

	numbers = "0123456789ABCDEF";
	if (pos >= 16)
	{
		tc = check_upper_hexa(pos / 16, tc);
		tc = check_upper_hexa(pos % 16, tc);
	}
	else
	{
		ft_putchar_fd(numbers[pos], 1);
		tc++;
	}
	return (tc);
}

int	void_hexa(unsigned long pos, int tc, int boolean)
{
	char	*numbers;

	numbers = "0123456789abcdef";
	if (boolean)
	{
		write(1, "0x", 2);
		tc += 2;
	}
	if (pos >= 16)
	{
		tc = void_hexa(pos / 16, tc, 0);
		tc = void_hexa(pos % 16, tc, 0);
	}
	else
	{
		ft_putchar_fd(numbers[pos], 1);
		tc++;
	}
	return (tc);
}
