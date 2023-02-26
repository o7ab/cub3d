/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:00:53 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 18:23:25 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	take_player_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		return (0);
	}
	return (1);
}

void	check_chars(t_cub *data)
{
	int		i;
	int		j;
	int		x;
	char	c;

	i = 0;
	x = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			c = data->map[i][j];
			check_player_pos(data, c, &x);
			if (take_player_pos(c) == 0)
			{
				data->posx = (double)j;
				data->posy = (double)i;
			}
			j++;
		}
		i++;
	}
	if (x != 1)
		print_error(data, "Map Includes Non or more than 1 starting pos!");
}

int	check_if_no_more_map(t_cub *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(data->config_fd);
		if (!line)
			return (0);
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		else
		{
			free(line);
			return (1);
		}
		free(line);
	}
}

void	check_spaces(t_cub *data, int i, int j)
{
	if (i + 1 < data->map_height)
	{
		if (data->map[i + 1][j] != ' ' && data->map[i + 1][j] != '1')
			print_error(data, "Map Not Closed by walls!1");
	}
	if (i - 1 >= 0)
		if (data->map[i - 1][j] != ' ' && data->map[i - 1][j] != '1')
			print_error(data, "Map Not Closed by walls!2");
	if (j + 1 < data->map_width)
		if (data->map[i][j + 1] != ' ' && data->map[i][j + 1] != '1')
			print_error(data, "Map Not Closed by walls!3");
	if (j - 1 >= 0)
		if (data->map[i][j - 1] != ' ' && data->map[i][j - 1] != '1')
			print_error(data, "Map Not Closed by walls!4");
}

void	check_spaces_from_all_dir(t_cub *data)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		temp = data->map[i];
		while (data->map[i][j])
		{
			if (temp[j] == ' ')
				check_spaces(data, i, j);
			j++;
		}
		i++;
	}
}
