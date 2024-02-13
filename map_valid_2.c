/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:49:00 by fshields          #+#    #+#             */
/*   Updated: 2024/01/30 15:13:49 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(t_data *data)
{
	t_pos	*map;
	int		big_x;
	int		big_y;

	map = data->map;
	big_x = biggest_x_or_y(data, 'x');
	big_y = biggest_x_or_y(data, 'y');
	while (map)
	{
		if (map->x == 0 || map->x == big_x || map->y == 0 \
		|| map->y == big_y)
		{
			if (map->content != '1')
				return (0);
		}
		map = map->next;
	}
	return (1);
}
