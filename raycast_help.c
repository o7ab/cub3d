/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:50:39 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/23 14:39:24 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->address + (y * cub->line_length + x * (cub->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_line(t_cub *cub, t_rayc *rayc)
{
	int	lineheight;

	lineheight = (int)(HEIGHT / rayc->perpwalldist);
	cub->line_start = -lineheight / 2 + HEIGHT / 2;
	if (cub->line_start < 0)
		cub->line_start = 0;
	cub->line_end = lineheight / 2 + HEIGHT / 2;
	if (cub->line_end >= HEIGHT)
		cub->line_end = HEIGHT - 1;
	if (cub->line_start >= HEIGHT)
		cub->line_start = 0;
}

void	ft_init_var(t_cub *cub, t_rayc *rayc, int x)
{
	double	camerax;

	camerax = 2 * x / (double)(WIDTH) - 1;
	cub->raydirx = cub->dirx + cub->planex * camerax;
	cub->raydiry = cub->diry + cub->planey * camerax;
	cub->mapx = (int)(cub->posx);
	cub->mapy = (int)(cub->posy);
	rayc->deltadistx = fabs(1 / cub->raydirx);
	rayc->deltadisty = fabs(1 / cub->raydiry);
}
