/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:48:18 by asando            #+#    #+#             */
/*   Updated: 2026/03/17 21:11:49 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> put charachter on the file decriptor
 * CALLED FUNCTION
 * ==> write(unistd.h)
 * PARAMETER (n = 2)
 * ==> 1.char 2.int
 * WORK
 * ==> put charachter to the fd provided
 * RETURN
 * ==> none
 * REFERENCE
 * ==>
*/
void	ft_putchar_fd(char c, int fd)
{
	ssize_t	ignored;

	ignored = write(fd, &c, 1);
	(void)ignored;
	return ;
}
