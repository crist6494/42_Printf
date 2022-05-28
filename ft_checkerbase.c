/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:44:14 by cmorales          #+#    #+#             */
/*   Updated: 2022/05/28 13:10:58 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	checkdecimal(int pos, int tc)
{
	char*	numbers;

	numbers = "0123456789";
	if (pos >= 10)
	{
		tc = checkdecimal(pos / 10, tc);
		tc = checkdecimal(pos % 10, tc);
	}
	else
	{
		ft_putchar_fd(numbers[pos], 1);
		tc++;
	}
	return (tc);
}

int	checkhexa(int pos, int tc)
{
	char* numbers;

	numbers = "0123456789abcdef";
	if (pos >= 16)
	{
		tc = checkdecimal(pos / 16, tc);
		tc = checkdecimal(pos % 16, tc);
	}
	else
	{
		ft_putchar_fd(numbers[pos], 1);
		tc++;
	}
	return (tc);
}