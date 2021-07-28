/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_rgb_to_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:20:17 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 16:50:15 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_conv_rgb_to_hex(int r, int g, int b)
{
	unsigned int		conv_rgb;

	conv_rgb = r * 256 * 256 + g * 256 + b;
	return (conv_rgb);
}
