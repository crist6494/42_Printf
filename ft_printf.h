/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:36:03 by cmorales          #+#    #+#             */
/*   Updated: 2022/05/31 16:34:45 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_select(char const *str, va_list alist, int tc);
int		check_decimal(unsigned int pos, int tc);
int		check_lower_hexa(unsigned int pos, int tc);
int		check_upper_hexa(unsigned int pos, int tc);
int		void_hexa(unsigned long pos, int tc, int boolean);
int		ft_putstr_fd(char *s, int fd, int tc);
void	ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd, int tc);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char	*str);
char	*ft_strchr(const char *s, int c);

#endif