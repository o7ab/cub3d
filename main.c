/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:10:41 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/15 00:34:40 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int cub_check_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) == 0)
			return (1);
		else
		{
			perror("Wrong expansion of the file");
			return (0);
		}
	}
	perror("Wrong number of arguments");
	return (0);
}

void	put_cubes(t_cub *cub, int color)
{
	int i = 0;
	int j = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			mlx_pixel_put(cub->mlx, cub->mlx_win, i * 20, j * 20, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_player *player, t_cub *cub)
{
	int i = 0;
	int j = 0;
	while (i < 12)
	{
		j = 0;
		while (j < 12)
		{
			if (i == (int)player->posx && j == (int)player->posy)
				put_cubes(cub, 0x00FF0000);
			else
				put_cubes(cub, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}
void	init_structs(t_cub *cub, t_player *player)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "TEST");
	player->posx = 22;
	player->posy = 12;
	player->dirx = -1;
	player->diry = 0;
	player->planex = 0;
	player->planey = 0.60;
}

int main(int argc, char **argv)
{
	t_cub		cub;
	t_player	player;

	(void) argc;
	(void) argv;
	int i = 0;
	int w = 22;
	double camerax = 0;
	double sidedistx = 0;
	double sidedisty = 0;
	double deltadistx = 0;
	double deltadisty = 0;
	// double perp_wall_dist;
	int stepx = 0;
	int stepy = 0;
	// int hit = 0;
	// int side;
	// if (!cub_check_args(argc, argv))
	// 	return (0);
	init_structs(&cub, &player);
	int mapx = (int)player.posx;
	int mapy = (int)player.posy;
	while (1)
	{
		while (i < w)
		{
			camerax = 2 * i / (double)w - 1;
			player.raydirx = (player.dirx + player.planex * camerax);
			player.raydiry = (player.diry + player.planey * camerax);
			deltadistx = fabs(1 / player.raydirx);
			deltadisty = fabs(1 / player.raydiry);
			if (player.raydirx < 0)
			{
				stepx = -1;
				sidedistx = (player.posx - mapx) * deltadistx;
			}
			else
			{
				stepx = 1;
				sidedistx = (mapx + 1.0 - player.posx) * deltadistx;
			}
			if (player.raydiry < 0)
			{
				stepy = -1;
				sidedisty = (player.posy - mapy) * deltadisty;
			}
			else
			{
				stepy = 1;
				sidedisty = (mapy + 1.0 - player.posy) * deltadisty;
			}
		}

	}
	draw_minimap(&player, &cub);
	mlx_loop(cub.mlx);
}