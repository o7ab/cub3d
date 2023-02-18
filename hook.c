/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:19:30 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/18 01:52:04 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_key_press(int keycode, t_cub *cub)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
	{
		if (cub->map[(int)(cub->posx + cub->dirx * cub->move_speed)][(int)(cub->posy)] == '0')
			cub->posx += cub->dirx * cub->move_speed;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy + cub->diry * cub->move_speed)] == '0')
			cub->posy += cub->diry * cub->move_speed;		
	}
	if (keycode == 0)
	{
		if (cub->map[(int)(cub->posx - cub->planex * cub->move_speed)][(int)(cub->posy)] == '0')
			cub->posx -= cub->planex * cub->move_speed;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy - cub->planey * cub->move_speed)] == '0')
			cub->posy -= cub->planey * cub->move_speed;
	}
	if (keycode == 1)
	{
		if (cub->map[(int)(cub->posx - cub->dirx * cub->move_speed)][(int)(cub->posy)] == '0')
			cub->posx -= cub->dirx * cub->move_speed;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy - cub->diry * cub->move_speed)] == '0')
			cub->posy -= cub->diry * cub->move_speed;
	}
	if (keycode == 2)
	{
		if (cub->map[(int)(cub->posx + cub->planex * cub->move_speed)][(int)(cub->posy)] == '0')
			cub->posx += cub->planex * cub->move_speed;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy + cub->planey * cub->move_speed)] == '0')
			cub->posy += cub->planey * cub->move_speed;
	}
	if (keycode == 123)
	{
		double olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(-cub->rotate) - cub->diry * sin(-cub->rotate);
		cub->diry = olddirx * sin(-cub->rotate) + cub->diry * cos(-cub->rotate);
		double oldplanex = cub->planex;
		cub->planex = cub->planex * cos(-cub->rotate) - cub->planey * sin(-cub->rotate);
		cub->planey = oldplanex * sin(-cub->rotate) + cub->planey * cos(-cub->rotate);
	}
	if (keycode == 124)
	{
		double olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(cub->rotate) - cub->diry * sin(cub->rotate);
		cub->diry = olddirx * sin(cub->rotate) + cub->diry * cos(cub->rotate);
		double oldplanex = cub->planex;
		cub->planex = cub->planex * cos(cub->rotate) - cub->planey * sin(cub->rotate);
		cub->planey = oldplanex * sin(cub->rotate) + cub->planey * cos(cub->rotate);
	}
	ft_raycast(cub);
	return (0);
}