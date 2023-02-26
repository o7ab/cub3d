/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:49:10 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 16:33:56 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	mouse_rotate_left(t_cub *cub)
// {
// 	double	olddirx;
// 	double	oldplanex;

// 	olddirx = cub->dirx;
// 	cub->dirx = cub->dirx * cos(cub->rotate)
// 		- cub->diry * sin(cub->rotate);
// 	cub->diry = olddirx * sin(cub->rotate)
// 		+ cub->diry * cos(cub->rotate);
// 	oldplanex = cub->planex;
// 	cub->planex = cub->planex * cos(cub->rotate)
// 		- cub->planey * sin(cub->rotate);
// 	cub->planey = oldplanex * sin(cub->rotate)
// 		+ cub->planey * cos(cub->rotate);
// }

// int	cub_mouse_press(int keycode, t_cub *cub)
// {
// 	double	olddirx;
// 	double	oldplanex;

// 	olddirx = cub->dirx;
// 	oldplanex = cub->planex;
// 	if (keycode == 4)
// 	{
// 		cub->dirx = cub->dirx * cos(-cub->rotate)
// 			- cub->diry * sin(-cub->rotate);
// 		cub->diry = olddirx * sin(-cub->rotate)
// 			+ cub->diry * cos(-cub->rotate);
// 		cub->planex = cub->planex * cos(-cub->rotate)
// 			- cub->planey * sin(-cub->rotate);
// 		cub->planey = oldplanex * sin(-cub->rotate)
// 			+ cub->planey * cos(-cub->rotate);
// 	}
// 	if (keycode == 5)
// 		mouse_rotate_left(cub);
// 	ft_raycast(cub);
// 	return (0);
// }
