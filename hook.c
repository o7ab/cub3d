/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:19:30 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/22 21:44:50 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_hori(t_cub *cub, int keycode)
{
	if (keycode == 0)
	{
		if (cub->map[(int)(cub->posx
				- cub->planex * cub->move_speed)][(int)(cub->posy)] != '1')
			cub->posx -= cub->planex * cub->move_speed;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy
			- cub->planey * cub->move_speed)] != '1')
			cub->posy -= cub->planey * cub->move_speed;
	}
	if (keycode == 2)
	{
		if (cub->map[(int)(cub->posx + cub->planex
				* cub->move_speed)][(int)(cub->posy)] != '1')
			cub->posx += cub->planex * cub->move_speed;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy + cub->planey
			* cub->move_speed)] != '1')
			cub->posy += cub->planey * cub->move_speed;
	}
}

void	ft_move_vert(t_cub *cub, int keycode)
{
	if (keycode == 13)
	{
		if (cub->map[(int)(cub->posx + cub->dirx
				* cub->move_speed)][(int)(cub->posy)] != '1')
			cub->posx += cub->dirx * cub->move_speed;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy + cub->diry
			* cub->move_speed)] != '1')
			cub->posy += cub->diry * cub->move_speed;
	}
	if (keycode == 1)
	{	
		if (cub->map[(int)(cub->posx - cub->dirx
				* cub->move_speed)][(int)(cub->posy)] != '1')
			cub->posx -= cub->dirx * cub->move_speed;
		if (cub->map[(int)(cub->posx)][(int)(cub->posy - cub->diry
			* cub->move_speed)] != '1')
			cub->posy -= cub->diry * cub->move_speed;
	}
}

void	rotate_right(t_cub *cub)
{
	double	olddirx;
	double	oldplanex;

	olddirx = cub->dirx;
	cub->dirx = cub->dirx * cos(cub->rotate)
		- cub->diry * sin(cub->rotate);
	cub->diry = olddirx * sin(cub->rotate)
		+ cub->diry * cos(cub->rotate);
	oldplanex = cub->planex;
	cub->planex = cub->planex * cos(cub->rotate)
		- cub->planey * sin(cub->rotate);
	cub->planey = oldplanex * sin(cub->rotate)
		+ cub->planey * cos(cub->rotate);
}

void	ft_rotate(t_cub *cub, int keycode)
{
	double	olddirx;
	double	oldplanex;

	olddirx = cub->dirx;
	oldplanex = cub->planex;
	if (keycode == 123)
	{
		cub->dirx = cub->dirx * cos(-cub->rotate)
			- cub->diry * sin(-cub->rotate);
		cub->diry = olddirx * sin(-cub->rotate)
			+ cub->diry * cos(-cub->rotate);
		cub->planex = cub->planex * cos(-cub->rotate)
			- cub->planey * sin(-cub->rotate);
		cub->planey = oldplanex * sin(-cub->rotate)
			+ cub->planey * cos(-cub->rotate);
	}
	if (keycode == 124)
		rotate_right(cub);
}

int	cub_key_press(int keycode, t_cub *cub)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 1)
		ft_move_vert(cub, keycode);
	if (keycode == 0 || keycode == 2)
		ft_move_hori(cub, keycode);
	if (keycode == 123 || keycode == 124)
		ft_rotate(cub, keycode);
	ft_raycast(cub);
	return (0);
}
