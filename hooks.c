/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:03:22 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 10:57:33 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	process_y_move(t_data *data, char key)
{
	t_player_pos	*pos;

	pos = data->player_pos;
	if (key == 'W')
	{
		if (!is_obstacle(data, pos->x, (pos->y) - 1))
		{
			data->player->instances[0].y -= BLOCK;
			data->player_pos->y --;
			handlers(data);
		}
	}
	else if (key == 'S')
	{
		if (!is_obstacle(data, pos->x, (pos->y) + 1))
		{
			data->player->instances[0].y += BLOCK;
			data->player_pos->y ++;
			handlers(data);
		}
	}
}

static void	process_d(t_data *data, int *r_flag)
{
	t_player_pos	*pos;

	pos = data->player_pos;
	if (!is_obstacle(data, (pos->x) + 1, pos->y))
	{
		data->player_pos->x ++;
		if (*r_flag)
			data->player->instances[0].x += BLOCK;
		else
		{
			swap_cat(data);
			*r_flag = 1;
		}
		handlers(data);
	}
}

static void	process_a(t_data *data, int *r_flag)
{
	t_player_pos	*pos;

	pos = data->player_pos;
	if (!is_obstacle(data, (pos->x) - 1, pos->y))
	{
		data->player_pos->x --;
		if (*r_flag)
		{
			swap_cat(data);
			*r_flag = 0;
		}
		else
			data->player->instances[0].x -= BLOCK;
		handlers(data);
	}
}

static void	process_x_move(t_data *data, char key)
{
	static int		r_flag;

	if (key == 'A')
		process_a(data, &r_flag);
	else if (key == 'D')
		process_d(data, &r_flag);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data			*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->window);
		return ;
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		process_y_move(data, 'W');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		process_y_move(data, 'S');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		process_x_move(data, 'A');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		process_x_move(data, 'D');
}
