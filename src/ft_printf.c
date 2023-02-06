/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:19:38 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/06 17:28:20 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Print the output corresponding to each %-construct in the format
 * string.
 * @param c The character following a % in the format string.
 * @param ap The list of variable arguments.
 * @return The number of characters printed.
 */
int	printf__subperc(char c, va_list *ap)
{
	if (c == 'c')
		return (printf__putchar_fd(va_arg(*ap, int), 1));
	if (c == 's')
		return (printf__putstr_fd(va_arg(*ap, char *), 1));
	if (c == 'p')
	{
		printf__putstr_fd("0x", 1);
		return (printf__putnbr_base(va_arg(*ap, size_t), HX_LO) + 2);
	}
	if (c == 'd' || c == 'i')
		return (printf__putnbr_fd(va_arg(*ap, int), 1));
	if (c == 'u')
		return (printf__putnbr_base(va_arg(*ap, unsigned int), DECIM));
	if (c == 'x')
		return (printf__putnbr_base(va_arg(*ap, unsigned int), HX_LO));
	if (c == 'X')
		return (printf__putnbr_base(va_arg(*ap, unsigned int), HX_HI));
	if (c == '%')
		return (printf__putchar_fd('%', 1));
	return (printf__putchar_fd(c, 1));
}

/**
 * @brief Produce output according to a format specified in the string s and
 * write this output to stdout.
 * @param s The format string.
 * @return The number of characters printed if the function returns
 * successfully, else it returns a negative value.
 */
int	ft_printf(const char *s, ...)
{
	int		r;
	va_list	ap;

	if (!s || write(1, 0, 0) < 0)
		return (-1);
	if (!*s)
		return (0);
	r = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
			r += printf__putchar_fd(*s, 1);
		else
			r += printf__subperc(*++s, &ap);
		if (!*s++)
			break ;
	}
	va_end(ap);
	return (r);
}
