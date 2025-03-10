/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:09:26 by asando            #+#    #+#             */
/*   Updated: 2025/03/10 21:15:23 by asando           ###   ########.fr       */
/*                                                                            */
/*
/* ************************************************************************** */
/*
 * FUNCTION (G)
 * ==> to count how many character is in a string (char*) 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 1)
 * ==> 1. int
 * WORK
 * ==> using control loop while it traverse inside a string
 * ==> while traversing adding 1 into variable count
 * RETURN
 * ==> length of parameter
 * REFERENCE
 * ==> strlen from string.h
*/
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}
