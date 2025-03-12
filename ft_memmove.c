/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:46:20 by asando            #+#    #+#             */
/*   Updated: 2025/03/12 14:52:49 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> cpoying the data from src to dest 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 3)
 * ==> 1.void *, 2.const void *, 3.size_t
 * WORK
 * ==> copying the source into the dstination
 * ==> stop when it reach n
 * RETURN
 * ==> destination
 * REFERENCE
 * ==> memmove in string.h
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	size_t		j;
	char		str_buff[n];
	const char	*src_str;
	char		*dest_str;

	src_str = src;
	dest_str = dest;
	i = 0;
	j = 0;
	while (i < n)
	{
		str_buff[i] = src_str[i];
		i++;
	}
	while (j < n)
	{
		dest_str[j] = str_buff[j];
		j++;
	}
	dest_str[j] = '\0';
	return (dest_str);
}
