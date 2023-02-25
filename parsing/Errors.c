/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:09:17 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/25 20:08:53 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_2d(char ***str)
{
	int	i;

	if (!(*str))
		return ;
	i = 0;
	while ((*str)[i])
		free((*str)[i++]);
	free(*str);
	*str = NULL;
}

void	print_error(t_cub *data, char *msg)
{
	(void)data;
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	// free_all(data);
	printf("test\n");
	exit(EXIT_FAILURE);
}

void	read_map(t_cub *data, char **line, char **map_input)
{
	while (1)
	{
		*line = get_next_line(data->config_fd);
		if (!*line)
			print_error(data, "Wrong Config File467863");
		if (*line[0] == '\n')
		{
			free(*line);
			continue ;
		}
		else
		{
			*map_input = *line;
			break ;
		}
		free(*line);
	}
}

void	parse_map_contents(t_cub *data)
{
	char	*line;
	char	*map_input;

	read_map(data, &line, &map_input);
	while (1)
	{
		line = get_next_line(data->config_fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			if (check_if_no_more_map(data))
			{
				free(map_input);
				print_error(data, "Wrong Config File1");
			}
			break ;
		}
		map_input = ft_strjoin(map_input, line);
		free(line);
	}
	data->map = ft_split(map_input, '\n');
	free(map_input);
	calc_map_width_height(data);
}