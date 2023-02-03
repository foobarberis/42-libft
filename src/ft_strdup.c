/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:09 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/03 18:22:42 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strdup(3) function allocates sufficient memory for a copy of
 * the string s, does the copy, and returns a pointer to it. The pointer
 * may subsequently be used as an argument to the function free(3).
 * @param s The string to duplicate.
 * @return A pointer to the duplicate if the copy is successful, NULL if an
 * error occured.
 */
char *strdup(const char *s)
{
	char	*d;
	size_t	l;

	l = ft_strlen(s);
	d = malloc(l + 1);
	if (!d)
		return (NULL);
	return (ft_memcpy(d, s, l + 1));
}
