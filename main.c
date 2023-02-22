/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:10:41 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/22 21:45:23 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_structs(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	cub->mlx_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->address = mlx_get_data_addr(cub->mlx_img, &cub->bits_per_pixel, &cub->line_length, &cub->endian);
	cub->posx = 6;
	cub->posy = 6;
	cub->dirx = 1;
	cub->diry = 0;
	cub->planex = 0;
	cub->planey = 0.66;
	cub->move_speed = 0.15;
	cub->rotate = 0.15;
	// mlx_hook(cub->mlx_win, 2, 1L<<0, cub_key_press, cub);
	cub->map = init_map(cub);
}

int main(int argc, char **argv)
{
	t_cub		cub;

	(void) argc;
	(void) argv;
	init_structs(&cub);
	ft_raycast(&cub);
	mlx_hook(cub.mlx_win, 2, 1L<<0, cub_key_press, &cub);
	// mlx_loop_hook(cub.mlx, ft_raycast, &cub);
	mlx_loop(cub.mlx);
}