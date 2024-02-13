/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:01:53 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 11:05:00 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_p_x(t_data *data)
{
	t_pos	*map;

	map = data->map;
	while (map)
	{
		if (map->content == 'P')
			return (map->x);
		map = map->next;
	}
	return (-1);
}

int	get_p_y(t_data *data)
{
	t_pos	*map;

	map = data->map;
	while (map)
	{
		if (map->content == 'P')
			return (map->y);
		map = map->next;
	}
	return (-1);
}

void	set_square(t_data *data, int x, int y)
{
	t_pos	*map;

	map = data->map;
	while (map)
	{
		if (map->x == x && map->y == y)
		{
			if (map->content == '0')
				map->content = 'o';
			if (map->content == 'C')
				map->content = 'c';
			if (map->content == 'P')
				map->content = 'p';
			if (map->content == 'E')
				map->content = 'e';
			return ;
		}
		map = map->next;
	}
}

int	is_inside(t_data *data, int x, int y)
{
	t_pos	*map;

	map = data->map;
	while (map)
	{
		if (map->x == x && map->y == y)
		{
			if (map->content == '1' || map->content == 'o' \
				|| map->content == 'c' || map->content == 'e' \
				|| map->content == 'p')
				return (0);
			return (1);
		}
		map = map->next;
	}
	return (-1);
}
