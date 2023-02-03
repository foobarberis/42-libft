/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:53:46 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/03 18:22:42 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

/**
 * @brief The atoi(3) function converts the initial portion of the string
 * pointed to by s to int representation.
 * @param s The string to convert.
 * @return Return an int corresponding to s. If an error occured during the
 * processing of the string (if the string contains non-digit characters
 * for example) return the number computed up to the point the error
 * occured.
 */
int	ft_atoi(const char *s)
{
	int			x;
	int			sign;

	x = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		sign *= -1;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
		x = x * 10 + *s++ - '0';
	return (x * sign);
}
