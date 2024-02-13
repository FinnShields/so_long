/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectables.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:37:22 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 10:56:07 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_of_collectables(t_data *data)
{
	int		rtn;
	t_pos	*map;

	rtn = 0;
	map = data->map;
	while (map)
	{
		if (map->content == 'C')
			rtn ++;
		map = map->next;
	}
	return (rtn);
}

static int	get_collectable_i(t_data *data)
{
	int				i;
	t_pos			*map;
	t_player_pos	*pos;

	i = -1;
	map = data->map;
	pos = data->player_pos;
	while (map)
	{
		if (map->content == 'C')
		{
			i ++;
			if (map->x == pos->x && map->y == pos->y)
				return (i);
		}
		map = map->next;
	}
	return (-1);
}

void	handle_collectables(t_data *data)
{
	int	i;

	i = get_collectable_i(data);
	if (i == -1)
		return ;
	data->collectable->instances[i].enabled = false;
}

int	all_collected(t_data *data)
{
	int	i;

	i = 0;
	while (i < no_of_collectables(data))
	{
		if (data->collectable->instances[i++].enabled == true)
			return (0);
	}
	return (1);
}
