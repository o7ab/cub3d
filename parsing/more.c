/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:09:17 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 18:22:16 by oabushar         ###   ########.fr       */
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

void	validate_map_contents(t_cub *data)
{
	check_chars(data);
	resize_width(data);
	check_if_closed_by_walls(data);
}

void	norm_free(char *str1, char **str2)
{
	free_2d(&str2);
	free(str1);
}
