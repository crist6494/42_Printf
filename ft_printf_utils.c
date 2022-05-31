/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:43:47 by cmorales          #+#    #+#             */
/*   Updated: 2022/05/31 18:29:33 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd, int tc)
{
	if (n == -2147483648)
	{
		tc = ft_putstr_fd("-2147483648", fd, tc);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tc++;
		tc = ft_putnbr_fd(-n, fd, tc);
	}
	else if (n > 9)
	{
		tc = ft_putnbr_fd(n / 10, fd, tc);
		ft_putchar_fd((n % 10) + '0', fd);
		tc++;
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
		tc++;
	}
	return (tc);
}

int	ft_putstr_fd(char *s, int fd, int tc)
{
	if (!s)
	{
		write (1, "(null)", 6);
		return (tc += 6);
	}
	if (s)
	{
		write (fd, s, ft_strlen(s));
		tc += ft_strlen(s);
	}
	return (tc);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (0);
}

size_t	ft_strlen(const char	*str)
{
	int	pos;	

	pos = 0;
	while (str[pos] != '\0')
	{
		pos++;
	}
	return (pos);
}
