/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:20:12 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/13 00:00:42 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
#include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_cub{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
}	t_cub;

typedef struct s_player{
	int		posx;
	int		posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	raydirx;
	double	raydiry;
}	t_player;
#endif