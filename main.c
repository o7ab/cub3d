/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:10:41 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/18 01:53:56 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	put_cubes(t_cub *cub, int color, int x, int y)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (i < sqrt(GRID))
// 	{
// 		j = 0;
// 		while (j < sqrt(GRID))
// 		{
// 			mlx_pixel_put(cub->mlx, cub->mlx_win, x + i, y + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_minimap(t_cub *cub, t_cub *cub)
// {
// 	int i = 0;
// 	int j = 0;
// 	(void) cub;
// 	while (i < HEIGHT / GRID)
// 	{
// 		j = 0;
// 		while (j < WIDTH / GRID)
// 		{
// 			if (worldMap[i][j] == 1)
// 				put_cubes(cub, 0x00FF0000, j * 64, i * 64);
// 			else
// 				put_cubes(cub, 0x00FFFFFF, j * 64, i * 64);
// 			j++;
// 		}
// 		i++;
// 	}
// }
void	init_structs(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	cub->mlx_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->address = mlx_get_data_addr(cub->mlx_img, &cub->bits_per_pixel, &cub->line_length, &cub->endian);
	cub->posx = 12;
	cub->posy = 12;
	cub->dirx = -1;
	cub->diry = 0;
	cub->planex = 0;
	cub->planey = 0.60;
	mlx_hook(cub->mlx_win, 2, 1L<<0, cub_key_press, cub);
	cub->map = init_map(cub);
}

int main(int argc, char **argv)
{
	t_cub		cub;

	(void) argc;
	(void) argv;
	init_structs(&cub);
	ft_raycast(&cub);
	mlx_loop(cub.mlx);
}