/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:46:31 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/03 18:20:44 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# include "ft_ctype.h"
# include "ft_print.h"
# include "ft_list.h"
# include "ft_stdlib.h"
# include "ft_string.h"

/* DEFINES */
# define OCTAL "01234567"
# define HX_LO "0123456789abcdef"
# define HX_HI "0123456789ABCDEF"

/* EXTRAS */


/* PERSONAL */
int			ft_permute(void *b, int n);
int			ft_permute_int(int *arr, int n);
int			ft_ndigit(int n, int baselen);
uintmax_t	ft_abs(intmax_t n);

#endif
