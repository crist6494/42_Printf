/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:36:03 by cmorales          #+#    #+#             */
/*   Updated: 2022/05/28 13:05:38 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include "./libft/libft.h"

int	ft_printf(char const *str, ...);
int	ft_select(char const *str, va_list alist, int tc);
int	checkdecimal(int pos, int tc);
int	checkhexa(int pos, int tc);

#endif