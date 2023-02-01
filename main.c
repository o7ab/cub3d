/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:10:41 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/01 23:35:14 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int cub_check_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) == 0)
			return (1);
		else
		{
			perror("Wrong expansion of the file");
			return (0);
		}
	}
	perror("Wrong number of arguments");
	return (0);
}

int main(int argc, char **argv)
{
	if (!cub_check_args(argc, argv))
		return (0);
}