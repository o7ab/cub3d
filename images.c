/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:48:14 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 15:58:08 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_images(t_cub *cub)
{
	cub->images = NULL;
	cub->images = (char **)malloc(5 * sizeof(char *));
	if (!cub->images)
		exit(EXIT_FAILURE);
	cub->images[0] = ft_strdup("imgs/Wall.xpm");
	cub->images[1] = ft_strdup("imgs/Wall2.xpm");
	cub->images[2] = ft_strdup("imgs/wood.xpm");
	cub->images[3] = ft_strdup("imgs/blust.xpm");
	cub->images[4] = NULL;
	

}

void	init_text(t_cub *cub)
{
	init_images(cub);
	cub->ptr[NO] = mlx_xpm_file_to_image(cub->mlx, cub->images[NO],
		&cub->img_width[NO], &cub->img_height[NO]);
	cub->texture[NO] = (int (*))mlx_get_data_addr(cub->ptr[NO], &cub->bits_per_pixel[NO],
		&cub->line_length[NO], &cub->endian[NO]);
	cub->ptr[SO] = mlx_xpm_file_to_image(cub->mlx, cub->images[SO],
		&cub->img_width[SO], &cub->img_height[SO]);
	cub->texture[SO] = (int (*))mlx_get_data_addr(cub->ptr[SO], &cub->bits_per_pixel[SO],
		&cub->line_length[SO], &cub->endian[SO]);
	cub->ptr[WE] = mlx_xpm_file_to_image(cub->mlx, cub->images[WE],
		&cub->img_width[WE], &cub->img_height[WE]);
	cub->texture[WE] = (int (*))mlx_get_data_addr(cub->ptr[WE], &cub->bits_per_pixel[WE],
		&cub->line_length[WE], &cub->endian[WE]);
	cub->ptr[EA] = mlx_xpm_file_to_image(cub->mlx, cub->images[EA],
		&cub->img_width[EA], &cub->img_height[EA]);
	cub->texture[EA] = (int (*))mlx_get_data_addr(cub->ptr[EA], &cub->bits_per_pixel[EA],
		&cub->line_length[EA], &cub->endian[EA]);
}