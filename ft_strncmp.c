/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 07:20:36 by asando            #+#    #+#             */
/*   Updated: 2025/03/12 07:26:37 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> Check the different between 2 list of characther 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 3)
 * ==> 1.char * 2.char * 3.size_t
 * WORK
 * ==> traversing through the whole list of character
 * ==> comparing ASCII every character with other list of characher
 * ==> stop when it find there is different or it reach n
 * RETURN
 * ==> the ASCII different between 2 character
 * REFERENCE
 * ==> strncmp in string.h
*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (str1[i] - str2[i]) == 0 && str1[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
