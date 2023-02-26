/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar <omar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:26:10 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 13:09:59 by omar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	obj_status(t_cub *data, int x, int y, int to_do)
{
	static int	**obj_map;
	int			i;

	if (!obj_map)
	{
		i = 0;
		obj_map = ft_calloc(data->map_height, sizeof(int *));
		while (i < data->map_height)
			obj_map[i++] = ft_calloc(data->map_width, sizeof(int));
	}
	if (to_do == 1)
	{
		i = -1;
		while (++i < data->map_height)
			if (obj_map[i])
				free(obj_map[i]);
		if (obj_map)
			free(obj_map);
		return (0);
	}
	if (to_do > 2)
		obj_map[y][x] = to_do;
	return (obj_map[y][x]);
}

int	color_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] \
	== '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	free ((char *)str);
	if (i > 5 || num > 255 || sign < 0)
		return (-1);
	return ((int)(num * sign));
}

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
