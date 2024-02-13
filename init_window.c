/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:15:10 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 11:00:06 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_x(t_pos *map)
{
	int	x;

	x = 0;
	while (map)
	{
		if (map->x > x)
			x = map->x;
		map = map->next;
	}
	return (x);
}

static int	get_map_y(t_pos *map)
{
	int	y;

	y = 0;
	while (map)
	{
		if (map->y > y)
			y = map->y;
		map = map->next;
	}
	return (y);
}

mlx_t	*init_window(t_data *data)
{
	int		x;
	int		y;
	t_pos	*map;
	mlx_t	*mlx;

	map = data->map;
	x = get_map_x(map);
	y = get_map_y(map);
	mlx = mlx_init((x + 1) * BLOCK, (y + 1) * BLOCK, \
	"so_long", true);
	if (!mlx)
		return (NULL);
	return (mlx);
}
