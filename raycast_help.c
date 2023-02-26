/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:50:39 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 15:42:57 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->address + (y * cub->line_len + x * (cub->bpp / 8));
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
	if (rayc->side == 0)
		rayc->wallx = cub->posy + rayc->perpwalldist * cub->raydiry;
	else
		rayc->wallx = cub->posx + rayc->perpwalldist * cub->raydirx;
	rayc->wallx -= floor((rayc->wallx));
	rayc->texx = (int)(rayc->wallx * (double)(GRID));
	if (rayc->side == 0 && cub->raydirx > 0)
		rayc->texx = GRID - rayc->texx - 1;
	if (rayc->side == 1 && cub->raydiry < 0)
		rayc->texx = GRID - rayc->texx - 1;
	rayc->step = 1.0 * GRID / lineheight;
	rayc->texpos = (cub->line_start - HEIGHT / 2
			+ lineheight / 2) * rayc->step;
	rayc->y = 0;
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
