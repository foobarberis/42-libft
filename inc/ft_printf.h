/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:54:23 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/06 17:30:31 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define HX_LO "0123456789abcdef"
# define HX_HI "0123456789ABCDEF"
# define DECIM "0123456789"

/* FT_PRINTF */
int			ft_printf(const char *s, ...);
int			printf__subperc(char c, va_list *ap);
int			printf__putchar_fd(char c, int fd);

/* FT_UTILS_UTILS */
int			printf__putstr_fd(char *s, int fd);
int			printf__putnbr_base(uint64_t n, char *base);
int			printf__putnbr_fd(int64_t n, int fd);

#endif
