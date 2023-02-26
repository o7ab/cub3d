/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:58:54 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 16:32:47 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	**init_map(t_cub *cub)
// {
// 	int		i;
// 	int		j;
// 	char	**map;

// 	i = 0;
// 	j = 0;
// 	(void)cub;
// 	map = (char **)malloc(sizeof(char *) * (MAPHEIGHT + 1));
// 	while (i < MAPHEIGHT)
// 	{
// 		map[i] = (char *)malloc(sizeof(char) * (MAPHEIGHT + 1));
// 		i++;
// 	}
// 	i = 0;
// 	while (i < MAPHEIGHT)
// 	{
// 		while (j < MAPWIDTH)
// 		{
// 			map[i][j] = '0';
// 			j++;
// 		}
// 		map[i][j] = '\0';
// 		j = 0;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < MAPHEIGHT)
// 	{
// 		while (j < MAPWIDTH)
// 		{
// 			if (i == 0 || i == MAPHEIGHT - 1)
// 				map[i][j] = '1';
// 			else if (j == 0 || j == MAPWIDTH - 1)
// 				map[i][j] = '1';
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	map[i] = NULL;
// 	i = 0;
// 	j = 0;
// 	map[3][3] = '1';
// 	map[3][4] = '1';
// 	map[3][5] = '1';
// 	map[3][6] = '1';
// 	map[10][10] = '1';
// 	while (i < 12)
// 	{
// 		printf("%s\n", map[i++]);
// 	}
// 	return (map);
// }