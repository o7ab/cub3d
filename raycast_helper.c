/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:16:57 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 16:34:12 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dda(t_rayc *rayc, t_cub *cub)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rayc->sidedistx < rayc->sidedisty)
		{
			rayc->sidedistx += rayc->deltadistx;
			cub->mapx += rayc->stepx;
			rayc->side = 0;
		}
		else
		{
			rayc->sidedisty += rayc->deltadisty;
			cub->mapy += rayc->stepy;
			rayc->side = 1;
		}
		if (ft_strlen(cub->map[cub->mapx]) > (size_t)cub->mapy)
			if (cub->map[cub->mapx][cub->mapy] == '1')
				hit = 1;
	}
}

void	get_side_dist(t_cub *cub, t_rayc *rayc)
{
	if (cub->raydiry < 0)
	{
		rayc->stepy = -1;
		rayc->sidedisty = (cub->posy - cub->mapy) * rayc->deltadisty;
	}
	else
	{
		rayc->stepy = 1;
		rayc->sidedisty = (cub->mapy + 1.0 - cub->posy) * rayc->deltadisty;
	}
	if (cub->raydirx < 0)
	{
		rayc->stepx = -1;
		rayc->sidedistx = (cub->posx - cub->mapx) * rayc->deltadistx;
	}
	else
	{
		rayc->stepx = 1;
		rayc->sidedistx = (cub->mapx + 1.0 - cub->posx) * rayc->deltadistx;
	}
}
