/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:48:14 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 17:52:13 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_text(t_cub *cub)
{
	cub->ptr[NO] = mlx_xpm_file_to_image(cub->mlx, cub->no_path,
			&cub->img_width[NO], &cub->img_height[NO]);
	cub->texture[NO] = (int (*))mlx_get_data_addr(cub->ptr[NO],
			&cub->bits_per_pixel[NO], &cub->line_length[NO], &cub->endian[NO]);
	cub->ptr[SO] = mlx_xpm_file_to_image(cub->mlx, cub->so_path,
			&cub->img_width[SO], &cub->img_height[SO]);
	cub->texture[SO] = (int (*))mlx_get_data_addr(cub->ptr[SO],
			&cub->bits_per_pixel[SO], &cub->line_length[SO], &cub->endian[SO]);
	cub->ptr[WE] = mlx_xpm_file_to_image(cub->mlx, cub->we_path,
			&cub->img_width[WE], &cub->img_height[WE]);
	cub->texture[WE] = (int (*))mlx_get_data_addr(cub->ptr[WE],
			&cub->bits_per_pixel[WE], &cub->line_length[WE], &cub->endian[WE]);
	cub->ptr[EA] = mlx_xpm_file_to_image(cub->mlx, cub->ea_path,
			&cub->img_width[EA], &cub->img_height[EA]);
	cub->texture[EA] = (int (*))mlx_get_data_addr(cub->ptr[EA],
			&cub->bits_per_pixel[EA], &cub->line_length[EA], &cub->endian[EA]);
}
