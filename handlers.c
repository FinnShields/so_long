/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:11:23 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 10:56:21 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_exit(t_data *data)
{
	t_player_pos	*pos;
	t_pos			*map;

	pos = data->player_pos;
	map = data->map;
	while (map)
	{
		if (map->content == 'E' && map->x == pos->x && map->y == pos->y)
		{
			if (all_collected(data))
			{
				ft_printf("You collected everything, well done!\n");
				mlx_close_window(data->window);
				return ;
			}
		}
		map = map->next;
	}
}

static void	handle_moves(void)
{
	static int	moves;

	moves ++;
	if (moves == 1)
		ft_printf("You've moved 1 time\n");
	else
		ft_printf("You've moved %i times\n", moves);
}

void	handlers(t_data *data)
{
	handle_moves();
	handle_collectables(data);
	handle_exit(data);
}
