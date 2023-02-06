/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:00:58 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/06 20:08:18 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

static int split__count_words(const char *s, char c)
{
	int i;

	i = 0;
	while (*s)
		if (*s++ == c)
			i++;
	return (i + 1);
}

static char **split__setup_arr(int size)
{
	char **tmp;

	tmp = malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (NULL);
	tmp[size - 1] = ft_strdup("\0");
	return (tmp);
}

static void split__split(char *s, char **arr, int len, int c)
{
	int		i;
	char	*l;
	char	*r;

	i = 0;
	r = s;
	while (1)
	{
		l = r;
		while (*r && (*r != c))
			r++;
		*r = '\0';
		arr[i++] = ft_strdup(l);
		if ((r - s) == len)
			break;
		r++;
	}
	free(s);
}

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings
 * obtained by splitting 's' using the character 'c' as a delimiter. The
 * array must end with a NULL pointer
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split or NULL if the
 * allocation fails.
 */
char **ft_split(char const *s, char c)
{
	int			len;
	char		**arr;

	len = ft_strlen(s);
	arr = split__setup_arr(split__count_words(s, c));
	split__split(ft_strdup(s), arr, len, c);
	return (arr);
}

int main(void)
{
	char c = ' ';
	char **split;
	char  *s = "            hello world, this is a test.";

	split = ft_split(s, c);
	for (int i = 0; i < split__count_words(s, c); i++)
		ft_printf("%s\n", split[i]);
	return 0;
}
