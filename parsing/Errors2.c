/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:26:10 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 18:13:51 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_text(t_cub *data)
{
	if (data->no_path)
		free(data->no_path);
	if (data->so_path)
		free(data->so_path);
	if (data->we_path)
		free(data->we_path);
	if (data->ea_path)
		free(data->ea_path);
}

void	free_imgs(t_cub *data)
{
	int	i;

	i = -1;
	mlx_destroy_image(data->mlx, data->mlx_img);
}

int	ft_strlen_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_all(t_cub *data)
{
	obj_status(data, 0, 0, 1);
	if (!data)
		return ;
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->map)
		free_2d(&(data->map));
	free_imgs(data);
	free_text(data);
	if (data->mlx)
		free(data->mlx);
	free(data);
}

int	close_window(t_cub *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
}
