/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:46:14 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 17:13:20 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strrev(char *str)
{
	size_t	len;
	size_t	i;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		++i;
	}
}

static int	get_len_int(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			is_neg;
	size_t		len;
	long long	cp;

	cp = ft_ternar_ll((n < 0), (long long)-n, (long long)n);
	is_neg = (n < 0);
	str = ft_calloc(get_len_int(n) + is_neg + 1, sizeof(*str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	len = 0;
	while (cp != 0)
	{
		str[len++] = cp % 10 + '0';
		cp /= 10;
	}
	if (is_neg)
		str[len++] = '-';
	ft_strrev(str);
	return (str);
}
