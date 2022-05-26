/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:13:06 by cmorales          #+#    #+#             */
/*   Updated: 2022/05/26 18:40:51 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(char const *str, ...)
{
	int	count = 0;
	
	va_list arglist;
	va_start(arglist, str);
	while(*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
				ft_putstr_fd(va_arg(arglist, char *),1, count);
			if (*str == '%')
				ft_putchar_fd('%', 1);
			if (*str == 'd')
				ft_putnbr_fd(va_arg(arglist, int),1);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	va_end(arglist);
	return (count);	
}

int	main()
{
	ft_printf("hola buenas tardes %d", 1234);
	return (0);
}