#include "../cub3d.h"


void	validate_map_contents(t_cub *data)
{
	check_chars(data);
	resize_width(data);
	check_if_closed_by_walls(data);
	check_spaces_from_all_dir(data);
}