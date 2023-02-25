/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:10:41 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/25 18:38:40 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_player_dir(t_cub *cub, int j, int k)
{
	if (cub->map[j][k] == 'N')
	{
		cub->dirx = 1;
		cub->planey = -0.66;
	}
	else if (cub->map[j][k] == 'W')
	{
		cub->diry = 1;
		cub->planex = 0.66;
	}
	else if (cub->map[j][k] == 'E')
	{
		cub->diry = -1;
		cub->planex = -0.66;
	}
	else
	{
		cub->dirx = -1;
		cub->planey = 0.66;
	}
}

void	init_structs(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	cub->mlx_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->address = mlx_get_data_addr(cub->mlx_img, &cub->bits_per_pixel,
			&cub->line_length, &cub->endian);
	cub->posx = 6;
	cub->posy = 6;
	ft_set_player_dir(cub, cub->mapx, cub->mapy);
	cub->dirx = 0;
	cub->diry = 0;
	cub->planex = 0;
	cub->planey = 0.66;
	cub->move_speed = 0.15;
	cub->rotate = 0.15;
	cub->map = init_map(cub);
}

void	rotate(double angle, t_cub *cub)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = cub->dirx;
	cub->dirx = cub->dirx * cos(angle) - cub->diry
		* sin(angle);
	cub->diry = old_dirx * sin(angle) + cub->diry * cos(angle);
	old_planex = cub->planex;
	cub->planex = cub->planex * cos(angle) - cub->planey
		* sin(angle);
	cub->planey = old_planex * sin(angle) + cub->planey
		* cos(angle);
	ft_raycast(cub);
}

int	move_mouse(int x, int y, t_cub *cub)
{
	double	angle_r;

	(void)y;
	angle_r = (x - WIDTH / 2) / 1200.0;
	rotate(angle_r, cub);
	mlx_mouse_move(cub->mlx_win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub		cub;

	if (parse_map(&cub, argc, argv))
		return (0);
	init_structs(&cub);
	ft_raycast(&cub);
	mlx_hook(cub.mlx_win, 2, 1L << 0, cub_key_press, &cub);
	mlx_hook(cub.mlx_win, 6, 1L << 6, move_mouse, &cub);
	mlx_loop(cub.mlx);
}
