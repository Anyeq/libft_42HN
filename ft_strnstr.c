/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:34:54 by asando            #+#    #+#             */
/*   Updated: 2025/03/18 16:59:05 by asando           ###   ########.fr       */
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
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			little_len;
	unsigned char	*big_uc;

	i = 0;
	j = 0;
	big_uc = (unsigned char *)big;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return (&big_uc[0]);
	while ((big_uc[i] != '\0') && (i < len))
	{
		while (big_uc[i] != '\0' && little[j] != '\0'
			&& big_uc[i] == (unsigned char)little[j] && (i < len))
		{
			j++;
			i++;
		}
		i = i - j;
		if (j == little_len)
			return (&big_uc[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
