/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:00:52 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 11:04:42 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *data, int x, int y)
{
	if (!is_inside(data, x, y))
		return ;
	set_square(data, x, y);
	move(data, x, y - 1);
	move(data, x, y + 1);
	move(data, x - 1, y);
	move(data, x + 1, y);
	return ;
}

int	check_for_unchanged(t_data *data)
{
	t_pos	*map;

	map = data->map;
	while (map)
	{
		if (map->content == 'C' || map->content == 'E')
			return (0);
		map = map->next;
	}
	return (1);
}

void	reformat_map(t_data *data)
{
	t_pos	*map;

	map = data->map;
	while (map)
	{
		if (map->content == 'o')
			map->content = '0';
		if (map->content == 'c')
			map->content = 'C';
		if (map->content == 'e')
			map->content = 'E';
		if (map->content == 'p')
			map->content = 'P';
		map = map->next;
	}
}

int	check_valid_path(t_data *data)
{
	int	x;
	int	y;

	x = get_p_x(data);
	y = get_p_y(data);
	move(data, x, y);
	if (!check_for_unchanged(data))
		return (0);
	reformat_map(data);
	return (1);
}
