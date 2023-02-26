/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:00:15 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 18:15:24 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_name(t_cub *data, int argc, char **argv)
{
	if (argc != 2)
		print_error(data, "Wrong number of args!");
	if (ft_strrchr(argv[1], '.'))
	{
		if (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5) \
		|| ft_strlen(argv[1]) == 4)
			print_error(data, "Wrong Input file!");
	}
	else
		print_error(data, "Wrong Input file!\n");
	data->config_fd = open(argv[1], O_RDWR);
	if (data->config_fd < 0)
		print_error(data, strerror(errno));
}

int	parse_map(t_cub *data, int argc, char **argv)
{
	check_map_name(data, argc, argv);
	check_elements(data);
	parse_map_contents(data);
	validate_map_contents(data);
	return (0);
}
