/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:14:22 by asando            #+#    #+#             */
/*   Updated: 2025/03/21 20:01:27 by asando           ###   ########.fr       */
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
	int		in_word;
	size_t	i;

	res = 0;
	i = 0;
	in_word = 1;
	while (delimiter != '\0' && str[i] != '\0')
	{
		if ((unsigned char)str[i] != (unsigned char)delimiter && in_word)
		{
			res++;
			in_word = 0;
		}
		if (str[i] == delimiter)
			in_word = 1;
		i++;
	}
	if (delimiter == '\0')
		res++;
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
	char			*buff;
	unsigned int	delimiter_num;
	unsigned int	not_delimiter;
	unsigned int	len;

	delimiter_num = 0;
	if (!s)
		return (NULL);
	while (s[delimiter_num] == c && c != '\0')
		delimiter_num++;
	not_delimiter = delimiter_num;
	while (s[not_delimiter] != c && s[not_delimiter] != '\0')
		not_delimiter++;
	len = not_delimiter - delimiter_num;
	if (len == 0)
		return (NULL);
	buff = malloc((len + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	ft_strlcpy(buff, &s[delimiter_num], len + 1);
	return (buff);
}

/*
 * FUNCTION (l)
 * ==> find a charachter that is not delimiter to tackel multiple delimiter
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 2)
 * ==> 1. const char * 2. char
 * WORK
 * ==> traverse string and find the charachter that is not delimiter
 * RETURN
 * ==> NULL if non delimiter is not found
 * ==> addres of a non delimiter charachter
 * REFERENCE
 * ==>
*/
static char	*find_ndelimiter(char const *s, char c)
{
	unsigned int	res;
	char			*str;

	str = (char *)s;
	res = 0;
	while (str[res] != '\0')
	{
		if (str[res] != c)
			return (&str[res]);
		res++;
	}
	return (NULL);
}

static int	clean_if_null(char **str, size_t i)
{
	if (!str[i])
	{
		while (i > 0)
			free(str[--i]);
		free(str);
		return (1);
	}
	return (0);
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
	if (!s)
		return (NULL);
	s_temp = (char *)s;
	wc = count_word(s, c);
	str_arr = malloc((wc + 1) * sizeof(char *));
	if (str_arr == NULL)
		return (NULL);
	while (i < wc && (wc + 1) > 1)
	{
		str_arr[i] = keep_word(s_temp, c);
		if (clean_if_null(str_arr, i))
			return (NULL);
		i++;
		if (c == '\0')
		{
			str_arr[i] = NULL;
			return (str_arr);
		}
		s_temp = find_ndelimiter(s_temp, c);
		s_temp = ft_strchr(s_temp, c);
	}
	//if (c == '\0' && s[0] != '\0')
	//{
	//	str_arr[i] = keep_word(s_temp, c);
	//	if (clean_if_null(str_arr, i))
	//		return (NULL);
	//	i++;
	//}
	str_arr[i] = NULL;
	return (str_arr);
}
