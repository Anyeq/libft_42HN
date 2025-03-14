/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:48:46 by asando            #+#    #+#             */
/*   Updated: 2025/03/14 10:10:21 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (L)
 * ==> check if string consist of set of character to trim
 * CALLED FUNCTION
 * ==> ft_strlen(libft.h), ft_strnstr(libft)
 * PARAMETER (n = 4)
 * ==> 1.const char * 2.const char * 3.int * 4 int *
 * WORK
 * ==> check the length of src and set
 * ==> check if set inside src
 * RETURN
 * ==> 0 if set is not in src
 * ==> 1 if set only in the front of src
 * ==> 2 if set onlu in the back of src
 * ==> 3 if set in the front and back of src
 * REFERENCE
 * ==>
*/
static int	check_str(char const *s1, char const *set, int *s1n, int *setn)
{
	int	res;

	*setn = ft_strlen(set);
	*s1n = ft_strlen(s1);
	res = 0;
	if (ft_strnstr(s1, set, *setn))
		res = res + 1;
	if (ft_strnstr(&s1[*s1n - *setn], set, *setn))
		res = res + 2;
	return (res);
}

/*
 * FUNCTION (L)
 * ==> copy string into a new varible
 * CALLED FUNCTION
 * ==> ft_strlcpy(libft.h)
 * PARAMETER (n = 4)
 * ==> 1.void * 2.const char * 3.int * 4 int *
 * WORK
 * ==> copy src into allocated memory without set
 * RETURN
 * ==> NULL if variable allocated is null or allocation failed
 * ==> address of allocated memory
 * REFERENCE
 * ==>
*/
static char	*copy_str(void *mem, char const *s1, int s1_len, int set_len)
{
	if (mem == NULL)
		return (NULL);
	ft_strlcpy(mem, s1, (s1_len - set_len + 1));
	return (mem);
}

/*
 * FUNCTION (G)
 * ==> trim set from src
 * CALLED FUNCTION
 * ==> check_str(l), ft_strdup(libft.h), malloc(stdlib.h), copy_str(l)
 * PARAMETER (n = 4)
 * ==> 1.char const *, 2.char const *
 * WORK
 * ==> check if src contain set
 * ==> based on condition copy only src without trim to result_str
 * RETURN
 * ==> NULL if variable allocated is null or allocation failed
 * ==> cleaned (without set) string
 * REFERENCE
 * ==>
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		set_len;
	int		s1_len;
	int		condition_num;
	char	*result_str;

	condition_num = check_str(s1, set, &s1_len, &set_len);
	if (condition_num == 1)
		result_str = ft_strdup(&s1[set_len]);
	else if (condition_num == 2)
	{
		result_str = malloc((s1_len - set_len + 1) * sizeof(char));
		copy_str(result_str, s1, s1_len, set_len);
		return (result_str);
	}
	else if (condition_num == 3)
	{
		result_str = malloc((1 + s1_len - 2 * set_len) * sizeof(char));
		copy_str(result_str, &s1[set_len], s1_len, 2 * set_len);
		return (result_str);
	}
	else
		result_str = ft_strdup(s1);
	return (result_str);
}
