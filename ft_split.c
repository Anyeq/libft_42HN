/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:14:22 by asando            #+#    #+#             */
/*   Updated: 2025/03/14 12:21:28 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (L)
 * ==> count how many part it would be when we split it by delimiter
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 2)
 * ==> 1. const char * 2. char
 * WORK
 * ==> count how many delimiter inside a src
 * RETURN
 * ==> number of delimiter could be intepreted as number of part after split
 * REFERENCE
 * ==>
*/
static size_t	count_word(const char *str, char delimiter)
{
	size_t	res;
	size_t	i;

	res = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == delimiter)
			res++;
		i++;
	}
	return (res);
}

/*
 * FUNCTION (L)
 * ==> copy the word to a new allocated memory before delimiter and \0
 * CALLED FUNCTION
 * ==> malloc(stdlib.h), ft_strlcpy(libft.h)
 * PARAMETER (n = 2)
 * ==> 1. const char * 2. char
 * WORK
 * ==> traverse trough the src until it reach delimiter or \0
 * ==> copying everything it traversed trough a new allocated memory
 * RETURN
 * ==> NULL if allocation fail
 * ==> addres of a new allocated memory consist of part of src before delimiter
 * REFERENCE
 * ==>
*/
static char	*keep_word(char const *s, char c)
{
	char	*buff;
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	buff = malloc((i + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	ft_strlcpy(buff, s, i + 1);
	return (buff);
}

/*
 * FUNCTION (G)
 * ==> splitting a src into part based on delimiter
 * CALLED FUNCTION
 * ==> count_word(l), malloc(stdlibg.h), keep_word(l), ft_strchr(libft.h)
 * PARAMETER (n = 2)
 * ==> 1. const char * 2. char
 * WORK
 * ==> count how many part it will be making
 * ==> allocate enough memory to keep the part
 * ==> keep the word
 * ==> tracking with ft_strchr which delimiter position we are working on
 * RETURN
 * ==> NULL if allocation failed
 * ==> addres of a list of parts that has been created trough splitting
 * REFERENCE
 * ==>
*/
char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	char	*s_temp;
	size_t	wc;
	size_t	i;

	i = 0;
	s_temp = (char *)s;
	wc = count_word(s, c);
	str_arr = malloc((wc + 1) * sizeof(char *));
	if (str_arr == NULL)
		return (NULL);
	while (i < wc && wc > 1)
	{
		str_arr[i] = keep_word(s_temp, c);
		s_temp = ft_strchr(s_temp, c) + 1;
		i++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}
