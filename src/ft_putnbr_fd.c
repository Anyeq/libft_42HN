/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2026/03/17 21:22:30 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> put number into fd provided
 * CALLED FUNCTION
 * ==> write(unistd.h)
 * PARAMETER (n = 2)
 * ==> 1.int 2.int
 * WORK
 * ==> devide by ten to get every digit and write it to fd
 * ==> if number consist a sign multiplyit to -1 to get positif number
 * ==> write sign separately
 * ==> if number == INT_MIN from limits.h write it on fd right away
 * RETURN
 * ==> none
 * REFERENCE
 * ==>
*/

static int	ft_is_intmin(int n, int fd)
{
	ssize_t	ignored;

	if (n == INT_MIN)
	{
		ignored = write(fd, "-2147483648", 11);
		(void)ignored;
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	ssize_t	ignored;

	if (n == 0)
	{
		ignored = write(fd, "0", 1);
		(void)ignored;
		return ;
	}
	if (ft_is_intmin(n, fd))
		return ;
	if (n < 0)
	{
		ignored = write(fd, "-", 1);
		(void)ignored;
		n = n * -1;
	}
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	ignored = write(fd, &c, 1);
	(void)ignored;
	return ;
}
