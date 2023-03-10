/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.elemnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:00:43 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 18:21:27 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	error(char **color_split)
{
	free_2d(&color_split);
	return (1);
}

int	read_color(t_cub *data, char **split_line, char type)
{
	char	**color_split;
	int		color[3];

	color_split = ft_split(split_line[1], ',');
	if (!color_split || ft_strlen_2d(color_split) != 3)
		print_error(data, "Wrong Config File2");
	color[0] = color_atoi(ft_strtrim(color_split[0], " \n"));
	color[1] = color_atoi(ft_strtrim(color_split[1], " \n"));
	color[2] = color_atoi(ft_strtrim(color_split[2], " \n"));
	if (color[0] == -1 || color[1] == -1 || color[2] == -1)
		return (error(color_split));
	free_2d(&color_split);
	if (type == 'F')
	{
		data->f_color = (0x00 << 24 | color[0] << 16 | \
		color[1] << 8 | color[2]);
	}
	else if (type == 'C')
	{
		data->c_color = (0x00 << 24 | color[0] << 16 | \
		color[1] << 8 | color[2]);
	}
	return (0);
}

int	handle_color(t_cub *data, char **split_line)
{
	if (!strncmp(split_line[0], "F", 2))
	{
		if (read_color(data, split_line, 'F'))
			return (1);
		data->f_color_count++;
	}
	else if (!strncmp(split_line[0], "C", 2))
	{
		if (read_color(data, split_line, 'C'))
			return (1);
		data->c_color_count++;
	}
	else
		return (1);
	return (0);
}

int	handle_elements(t_cub *data, char **split_line)
{
	if (ft_strlen_2d(split_line) != 2)
		return (1);
	if (ft_strlen(split_line[0]) == 2)
	{
		if (!ft_strncmp(split_line[0], "NO", 3))
			data->no_path = ft_strdup(split_line[1]);
		else if (!ft_strncmp(split_line[0], "SO", 3))
			data->so_path = ft_strdup(split_line[1]);
		else if (!ft_strncmp(split_line[0], "WE", 3))
			data->we_path = ft_strdup(split_line[1]);
		else if (!ft_strncmp(split_line[0], "EA", 3))
			data->ea_path = ft_strdup(split_line[1]);
		else
			return (1);
	}
	else if (ft_strlen(split_line[0]) == 1)
		return (handle_color(data, split_line));
	else
		return (1);
	return (0);
}

// void	norm_free(char *str1, char **str2)
// {
// 	free_2d(&str2);
// 	free(str1);
// }

void	check_elements(t_cub *data)
{
	char	*line;
	char	**split_line;
	char	*temp;

	while (data->index < 6)
	{
		line = get_next_line(data->config_fd);
		if (!line)
			print_error(data, "Wrong Config File3");
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		temp = line;
		line = ft_strtrim(line, "\n");
		free(temp);
		split_line = ft_split(line, ' ');
		if (handle_elements(data, split_line))
			data->index = -2;
		norm_free(line, split_line);
		if (data->index == -2)
			print_error(data, "Wrong Config Filefbxg");
		data->index++;
	}
}
