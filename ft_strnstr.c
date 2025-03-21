/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:34:54 by asando            #+#    #+#             */
/*   Updated: 2025/03/21 01:04:11 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> Find a set of charachter inside a list of character 
 * CALLED FUNCTION
 * ==> ft_strlen(libft)
 * PARAMETER (n = 3)
 * ==> 1.const char *  2.const char * c 3.size_t
 * WORK
 * ==> traversing through the whole list of character
 * ==> comparing ASCII every character with the set of charachter
 * ==> stop when it has the set of charachter
 * RETURN
 * ==> the address of set of charachter found
 * REFERENCE
 * ==> strnstr in string.h
*/
//static size_t	find_str(size_t *i, size_t len, const char *big, const char *little)
//{
//	size_t	j;
//	size_t	iteri;
//
//	j = 0;
//	iteri = *i;
//	while (big[iteri] != '\0' && little[j] != '\0'
//		&& big[iteri] == little[j] && (iteri < len))
//	{
//		iteri++;
//		j++;
//	}
//	*i = iteri - j;
//	return (j);
//}
//		nstr_found = find_str(&i, len, big, little);
//		if (nstr_found == little_len)
//			return ((char *)&big[i]);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	j;

	i = 0;
	j = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)&big[0]);
	while ((big[i] != '\0') && (i < len))
	{
		while (big[i] != '\0' && little[j] != '\0'
			&& big[i] == little[j] && (i < len))
		{
			i++;
			j++;
		}
		i = i - j;
		if (j == little_len)
			return ((char *)&big[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
