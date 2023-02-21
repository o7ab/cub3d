/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:25 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/21 18:24:54 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_cub *cub, int x, int y, int color)
{
	char *dst;

	dst = cub->address+ (y * cub->line_length + x * (cub->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// temp function
void	draw_line(t_cub *cub, int x, int start, int end, int color)
{	
	int	i;
	i = start;
	while (i <= end)
	{
		ft_put_pixel(cub, x, i, color);
		// mlx_pixel_put(cub->mlx, cub->mlx_win, x, i, color);
		i++;
	}
}

int	ft_raycast(t_cub *cub)
{
	// double camerax = 0;
	// double sidedistx = 0;
	// double sidedisty = 0;
	// double deltadistx = 0;
	// double deltadisty = 0;
	// double perp_wall_dist = 0;
	// // double wall_x;
	// // double move_speed = 1.5;
	// int stepx = 0;
	// int stepy = 0;
	// int hit = 0;
	// int side = 0;
	// int i = 0;
	// int w = WIDTH;
	// // if (!cub_check_args(argc, argv))
	// // 	return (0);
	// int mapx = (int)cub->posx;
	// int mapy = (int)cub->posy;
	// while (i < w)
	// {
	// 	camerax = 2 * i / (double)w - 1;
	// 	cub->cub->raydirx = (cub->dirx + cub->planex * camerax);
	// 	cub->cub->raydiry = (cub->diry + cub->planey * camerax);
	// 	deltadistx = fabs(1 / cub->cub->raydirx);
	// 	deltadisty = fabs(1 / cub->cub->raydiry);
	// 	if (cub->cub->raydirx < 0)
	// 	{
	// 		stepx = -1;
	// 		sidedistx = (cub->posx - mapx) * deltadistx;
	// 	}
	// 	else
	// 	{
	// 		stepx = 1;
	// 		sidedistx = (mapx + 1.0 - cub->posx) * deltadistx;
	// 	}
	// 	if (cub->cub->raydiry < 0)
	// 	{
	// 		stepy = -1;
	// 		sidedisty = (cub->posy - mapy) * deltadisty;
	// 	}
	// 	else
	// 	{
	// 		stepy = 1;
	// 		sidedisty = (mapy + 1.0 - cub->posy) * deltadisty;
	// 	}
	// 	while (hit == 0)
	// 	{
	// 		if (sidedistx < sidedisty)
	// 		{
	// 			sidedistx += deltadistx;
	// 			mapx += stepx;
	// 			side = 0;
	// 		}
	// 		else
	// 		{
	// 			sidedisty += deltadisty;
	// 			mapy += stepy;
	// 			side = 1;
	// 		}
	// 		// if (ft_strlen(cub->map[mapx]) > (size_t) mapy)
	// 		// {
	// 			if (cub->map[mapx][mapy] == '1')
	// 				hit = 1;

	// 		// }
	// 	}
	// 	if (side == 0)
	// 		perp_wall_dist = (sidedistx - deltadistx);
	// 	else
	// 		perp_wall_dist = (sidedisty - deltadisty);
	// 	cub->line_height = (int) (HEIGHT / perp_wall_dist);
	// 	cub->line_start = (-cub->line_height / 2) + HEIGHT / 2;
	// 	// if (cub->line_start < 0 || cub->line_start >= cub->line_height)
	// 	if (cub->line_start < 0 || cub->line_start >= HEIGHT)
	// 		cub->line_start = 0;
	// 	cub->line_end = (cub->line_height / 2) + HEIGHT / 2;
	// 	if (cub->line_end >= HEIGHT)
	// 		cub->line_end = HEIGHT - 1;
	// 	// if (side == 0)
	// 	// 	wall_x = cub->posx + perp_wall_dist * cub->cub->raydirx;
	// 	// else
	// 	// 	wall_x = cub->posy + perp_wall_dist * cub->cub->raydiry;
	// 	// wall_x -= floor(wall_x);
	// 	// int tex_x = (int)(wall_x * (double)64);
	// 	// if (side == 0 && cub->cub->raydirx > 0)
	// 	// 	tex_x = 64 - tex_x - 1;
	// 	// if (side == 1 && cub->cub->raydiry < 0)
	// 	// 	tex_x = 64 - tex_x - 1;
	// 	// double step = 1.0 * 64 / cub->line_height;
	// 	// double tex_pos = (cub->line_start - HEIGHT / 2 + cub->line_height / 2) * step;
	// 	int y = 0;
	// 	while (y < HEIGHT)
	// 	{
	// 		if (y >= cub->line_start && y <= cub->line_end)
	// 		{
	// 			// int tex_y = (int)tex_pos & (64 - 1);
	// 			// tex_pos += step;
	// 			int color;
	// 		// printf("the testtttt is here \n, %d", worldMap[mapx][mapy]);
	// 			if (side == 0 && cub->cub->raydirx > 0)
	// 				color = 0x00FF0000;
	// 			else if (side == 0 && cub->cub->raydirx < 0)
	// 				color = 0x0FFF0000;
	// 			else if (side == 1 && cub->cub->raydiry > 0)
	// 				color = 0x000F00FF;
	// 			else
	// 				color = 0x000000FF;
	// 			// if (side == 1)
	// 			// 	color = (color >> 1) & 8355711;
	// 			cub->buffer[y][i] = color;
	// 		}
	// 		y++;
	// 	}
	// 	int j = 0;
	// 	// while (j < cub->line_end - cub->line_start)
	// 	while (j < HEIGHT)
	// 	{
	// 		// while (j )
	// 		// if (j < cub->line_start)
	// 		if (j < HEIGHT / 2)
	// 			ft_put_pixel(cub, i, j, 0x000000FF);
	// 		// else if (j > cub->line_end)
	// 		else if (j > HEIGHT / 2)
	// 			ft_put_pixel(cub, i, j, 0x00FF0000);
	// 		j++;
	// 	}
	// 	j = 0;

	// 	// int	color = 0xFFFF00;
	// 	// if (side)
	// 	// 	color /= 2;

	// 	// draw_line(cub, i, cub->line_start, cub->line_end, color);
	// 	while (j < HEIGHT)
	// 	{
	// 		if (j >= cub->line_start && j <= cub->line_end)
	// 			ft_put_pixel(cub, i, j, cub->buffer[j][i]);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->mlx_img, 0, 0);
	// return 0;

	int x = 0;
	int mapX;
	int mapY;
	while (x < WIDTH)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)(WIDTH) - 1; //x-coordinate in camera space
		cub->raydirx = cub->dirx + cub->planex * cameraX;
		cub->raydiry = cub->diry + cub->planey * cameraX;
		//which box of the map we're in
		mapX = (int)(cub->posx);
		mapY = (int)(cub->posy);

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / cub->raydirx);
		double deltaDistY = fabs(1 / cub->raydiry);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (cub->raydirx < 0)
		{
			stepX = -1;
			sideDistX = (cub->posx - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cub->posx) * deltaDistX;
		}
		if (cub->raydiry < 0)
		{
			stepY = -1;
			sideDistY = (cub->posy - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cub->posy) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			// printf("%d %d\n", mapX, mapY);
			// fflush(stdout);
			//Check if ray has hit a wall
			if (ft_strlen(cub->map[mapX]) > (size_t)mapY)
				if (cub->map[mapX][mapY] == '1')
					hit = 1;
		} 
		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		//Calculate height of line to draw on screen
		int lineHeight = (int)(HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		cub->line_start = -lineHeight / 2 + HEIGHT / 2;
		if(cub->line_start < 0)cub->line_start = 0;
			cub->line_end = lineHeight / 2 + HEIGHT / 2;
		if(cub->line_end >= HEIGHT)
			cub->line_end = HEIGHT - 1;
		if(cub->line_start >= HEIGHT)
			cub->line_start = 0;
		//choose wall color
		// int color;
		// switch(cub->s[mapX][mapY])
		// {
		// 	case '1':  color = 0x00FF0000;  break; //red
		// 	default: color = 0x00000000; break; //yellow
		// }
		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (side == 0) wallX = cub->posy + perpWallDist * cub->raydiry;
		else           wallX = cub->posx + perpWallDist * cub->raydirx;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int)(wallX * (double)(GRID));
		if(side == 0 && cub->raydirx > 0) texX = GRID - texX - 1;
		if(side == 1 && cub->raydiry < 0) texX = GRID - texX - 1;
		//give x and y sides different brightness
		// if (side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		// double step = 1.0 * GRID / lineHeight;
      // Starting texture coordinate
    //   double texPos = (cub->line_start - HEIGHT / 2 + lineHeight / 2) * step;
      for(int y = 0; y < HEIGHT; y++)
      {
		// Cast the texture coordinate to integer, and mask with (GRID - 1) in case of overflow
		if (y >= cub->line_start && y <= cub->line_end)
		{
			// int texY = (int)texPos & (cub->height[0] - 1);
			// texPos += step;
			// // fflush(stdout);
			// int color;
			// if (side == 0 && cub->raydirx > 0)
			// 	color = (int)cub->texture[0][(int)GRID * texY + texX];
			// else if (side == 0 && cub->raydirx < 0)
			// 	color = (int)cub->texture[1][(int)GRID * texY + texX];
			// else if (side == 1 && cub->raydiry > 0)
			// 	color = (int)cub->texture[2][(int)GRID * texY + texX];
			// else if (side == 1 && cub->raydiry < 0)
			// 	color = (int)cub->texture[3][(int)GRID * texY + texX];
			int color = 0x00F9BA84;
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		// printf("%d %d %d %d\n", cub->texture[GRID * texY + texX], GRID * texY + texX, texX, texY);
			if(side == 1) color = (color >> 1) & 8355711;
			cub->buffer[y][x] = color;
		}
		// else if (y < cub->drawStart)
		// 	cub->buffer[y][x] = 0x00FF0000;
		// else if (y > cub->drawEnd)
		// 	cub->buffer[y][x] = 0x00FF0000;
		
      }
		int i = 0;
		while (i < HEIGHT)
		{
			if (i <  HEIGHT / 2)
				ft_put_pixel(cub, x, i, 0x0098FF98);
			else if (i >  HEIGHT / 2)
				ft_put_pixel(cub, x, i, 0x007E0CD6);
			i++;
		}
		i = 0;
		while (i < HEIGHT)
		{
			if (i >= cub->line_start && i <= cub->line_end)
			{
				ft_put_pixel(cub, x, i,	cub->buffer[i][x]);
			}
			i++;
		}
		x++;
	}
	// printf("%u %u %d %d \n", cub->line_start, cub->drawEnd, mapX, mapY);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->mlx_img, 0, 0);
	return (0);
}