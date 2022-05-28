/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:32:01 by cmorales          #+#    #+#             */
/*   Updated: 2022/05/28 13:10:20 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

int	ft_select(char const *str, va_list alist, int tc)
{
	if (*str == 'c')
	{
		ft_putchar_fd(va_arg(alist, int),1);
		tc++;
	}
	else if (*str == 's')
		tc = ft_putstr_fd(va_arg(alist, char *),1, tc);
	//else if (*str == 'p')
	
	else if (*str == 'd' || *str == 'i')
		tc = ft_putnbr_fd(va_arg(alist, int),1, tc);
	else if (*str == 'u')
		tc = checkdecimal(va_arg(alist, unsigned int), tc);
	else if(*str == 'x')
	{
		tc = checkhexa(va_arg(alist, int), tc);
	}
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		tc++;
	}
	return (tc);
}

int	ft_printf(char const *str, ...)
{
	int	tc = 0;
	
	va_list alist;
	va_start(alist, str);
	while(*str)
	{
		if (*str == '%')
		{
			str++;
			ft_select(str, alist, tc);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			tc++;
		}
		str++;
	}
	va_end(alist);
	return (tc);	
}

int	main()
{
	ft_printf("Muestra un caracter = %c\nMuestra un string = %s\nMuestra un porcentaje = %%\nMuestra número decimal = %d\nMuestra un entero de base 10 = %i\nMuestra un numero decimal sin signo = %u\nMuestra un numero hexadecimal en minuscula = %x\n",'c', "El mamporrero",  8, 9, -10, 12);
	printf("\n\nMuestra un caracter = %c\nMuestra un string = %s\nMuestra un porcentaje = %%\nMuestra número decimal = %d\nMuestra un entero de base 10 = %i\nMuestra un numero decimal sin signo = %u\nMuestra un numero hexadecimal en minuscula = %x\n",'c', "El mamporrero", 8, 9, -10, 12);
	return (0);
}