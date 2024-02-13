/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:25:42 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 11:01:39 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_chars(t_data *data)
{
	t_pos	*map;

	map = data->map;
	while (map)
	{
		if (map->content != '1' && map->content != '0' && \
		map->content != 'E' && map->content != 'P' && \
		map->content != 'C')
			return (0);
		map = map->next;
	}
	return (1);
}

static int	check_e_c_s(t_data *data)
{
	t_pos	*map;
	int		count;

	count = 0;
	map = data->map;
	if (no_of_collectables(data) < 1)
		return (0);
	while (map)
	{
		if (map->content == 'E')
			count ++;
		map = map->next;
	}
	if (count != 1)
		return (0);
	map = data->map;
	while (map)
	{
		if (map->content == 'P')
			count ++;
		map = map->next;
	}
	if (count != 2)
		return (0);
	return (1);
}

static int	check_pos(t_pos *map, int x, int y)
{
	while (map)
	{
		if (map->x == x && map->y == y)
			return (1);
		map = map->next;
	}
	return (0);
}

static int	check_shape(t_data *data)
{
	t_pos	*map;
	int		x;
	int		biggest_x;
	int		y;

	map = data->map;
	x = biggest_x_or_y(data, 'x');
	biggest_x = x;
	y = biggest_x_or_y(data, 'y');
	while (y >= 0)
	{
		while (x >= 0)
		{
			if (check_pos(map, x, y) == 0)
				return (0);
			x --;
		}
		x = biggest_x;
		y --;
	}
	return (1);
}

int	map_valid(t_data *data)
{
	if (!check_chars(data))
		return (0);
	if (!check_e_c_s(data))
		return (0);
	if (!check_shape(data))
		return (0);
	if (!check_border(data))
		return (0);
	if (!check_valid_path(data))
		return (0);
	return (1);
}
