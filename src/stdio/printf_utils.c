/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:37:01 by mbarberi          #+#    #+#             */
/*   Updated: 2023/05/13 16:57:34 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BASE10 "0123456789"
#define BASE16UP "0123456789ABCDEF"
#define BASE16LOW "0123456789abcdef"

ssize_t printf__putchar( int fd, char c ) {
    return ( write( fd, &c, 1 ) );
}

ssize_t printf__putstr( int fd, char * s ) {
    if ( !s )
        return ( write( fd, "(null)", 6 ) );
    return ( write( fd, s, f_strlen( s ) ) );
}

/**
 * @brief Print the argument according to format specified by c.
 * @param s The format string.
 * @param ap The list of variable arguments.
 * @return The number of characters printed.
 */
ssize_t printf__arg( int fd, const char ** s, va_list * ap ) {
    int is_z;

    is_z = 0;
    if ( **s == 'z' ) {
        is_z = 1;
        ( *s )++;
    }
    if ( **s == 'c' )
        return ( printf__putchar( fd, va_arg( *ap, int ) ) );
    if ( **s == 's' )
        return ( printf__putstr( fd, va_arg( *ap, char * ) ) );
    if ( **s == 'p' ) {
        printf__putstr( fd, "0x" );
        return ( f_uputnbr( fd, va_arg( *ap, uintptr_t ), BASE16LOW ) + 2 );
    }
    if ( **s == 'd' || **s == 'i' ) {
        if ( is_z )
            return ( f_sputnbr( fd, va_arg( *ap, ssize_t ), BASE10 ) );
        return ( f_sputnbr( fd, va_arg( *ap, int ), BASE10 ) );
    }
    if ( **s == 'u' ) {
        if ( is_z )
            return ( f_uputnbr( fd, va_arg( *ap, size_t ), BASE10 ) );
        return ( f_uputnbr( fd, va_arg( *ap, unsigned int ), BASE10 ) );
    }
    if ( **s == 'x' ) {
        if ( is_z )
            return ( f_uputnbr( fd, va_arg( *ap, size_t ), BASE16LOW ) );
        return ( f_uputnbr( fd, va_arg( *ap, unsigned int ), BASE16LOW ) );
    }
    if ( **s == 'X' ) {
        if ( is_z )
            return ( f_uputnbr( fd, va_arg( *ap, size_t ), BASE16UP ) );
        return ( f_uputnbr( fd, va_arg( *ap, unsigned int ), BASE16UP ) );
    }
    if ( **s == '%' )
        return ( printf__putchar( fd, '%' ) );
    return ( printf__putchar( fd, **s ) );
}
