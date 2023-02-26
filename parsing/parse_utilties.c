/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utilties.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:59:40 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 18:22:28 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*create_spaces(t_cub *cub, int number)
{
	char	*res;
	int		i;

	i = 0;
	if (number > 0)
	{
		res = malloc(sizeof(char) * (number + 1));
		if (!res)
			print_error(cub, "Malloc Error!");
	}
	else
		return (NULL);
	while (i < number)
		res[i++] = ' ';
	res[i] = '\0';
	return (res);
}

void	resize_width(t_cub *cub)
{
	int		i;
	int		width;
	char	*spaces;

	i = 0;
	while (cub->map[i])
	{
		width = ft_strlen(cub->map[i]);
		if (width < cub->map_width)
		{
			spaces = create_spaces(cub, cub->map_width - width);
			cub->map[i] = ft_strjoin(cub->map[i], spaces);
			free(spaces);
		}
		i++;
	}
}

void	calc_map_width_height(t_cub *cub)
{
	int	i;

	i = 0;
	cub->map_width = 0;
	cub->map_height = 0;
	cub->map_width = ft_strlen(cub->map[i]);
	while (cub->map[i])
	{
		if ((int)ft_strlen(cub->map[i]) > cub->map_width)
			cub->map_width = ft_strlen(cub->map[i]);
		i++;
	}
	cub->map_height = i;
}
