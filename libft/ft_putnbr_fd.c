/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:38:18 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 17:26:11 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			size;
	long long	cp;
	char		arr[12];

	size = 0;
	cp = ft_ternar_ll((n < 0), (long long)-n, (long long)n);
	if (cp == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
			write(fd, "-", 1);
		while (cp)
		{
			arr[size++] = cp % 10 + '0';
			cp /= 10;
		}
		while (size)
		{
			write(fd, &arr[--size], 1);
		}
	}
}
