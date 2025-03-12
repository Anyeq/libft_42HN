/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 07:57:41 by asando            #+#    #+#             */
/*   Updated: 2025/03/12 08:21:00 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> copy the content of src into destination len - 1 
 * CALLED FUNCTION
 * ==> ft_strlen(libft)
 * PARAMETER (n = 3)
 * ==> 1.char * 2.char * 3.size_t
 * WORK
 * ==> traverse src
 * ==> copy src into destination
 * ==> Stop copying when it reach \0 or copied len - 1, it need spaces for \0
 * RETURN
 * ==> the len of source
 * REFERENCE
 * ==> strlcpy in string.h
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < (len - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
