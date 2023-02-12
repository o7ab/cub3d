/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:10:41 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/13 00:10:32 by oabushar         ###   ########.fr       */
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

void	init_structs(t_cub *cub, t_player *player)
{
	player->posx = 22;
	player->posy = 12;
	player->dirx = -1;
	player->diry = 0;
	player->planex = 0;
	player->planey = 0.66;
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
	// if (!cub_check_args(argc, argv))
	// 	return (0);
	cub.mlx = mlx_init();
	cub.mlx_win = mlx_new_window(cub.mlx, 1200, 800, "TEST");
	init_structs(&cub, &player);
	while (1)
	{
		while (i < w)
		{
			camerax = 2 * i / (double)w - 1;
			player.raydirx = player.dirx + player.planex * camerax;
			player.raydiry = player.diry + player.planey * camerax;
			i++;
		}

	}
	mlx_loop(cub.mlx);
}