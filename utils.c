/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:58:20 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 11:02:36 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_pos *map)
{
	t_pos	*temp;

	if (!map)
		return ;
	temp = map->next;
	while (map->next)
	{
		free(map);
		map = temp;
		temp = map->next;
	}
	free(map);
}

void	free_data(t_data *data)
{
	free_map(data->map);
	if (data->player_pos)
		free(data->player_pos);
	if (data->player)
		mlx_delete_image(data->window, data->player);
	if (data->obstacle)
		mlx_delete_image(data->window, data->obstacle);
	if (data->collectable)
		mlx_delete_image(data->window, data->collectable);
	if (data->exit)
		mlx_delete_image(data->window, data->exit);
	if (data->background)
		mlx_delete_image(data->window, data->background);
	free(data);
}

int	is_obstacle(t_data *data, int x, int y)
{
	t_pos	*map;

	map = data->map;
	while (map)
	{
		if (map->x == x && map->y == y && map->content == '1')
			return (1);
		map = map->next;
	}
	return (0);
}

void	swap_cat(t_data *data)
{
	static int		n;
	mlx_texture_t	*texture;
	t_player_pos	*pos;

	pos = data->player_pos;
	if (n % 2 == 0)
	{
		texture = mlx_load_png("./textures/cat_right.png");
		mlx_delete_image(data->window, data->player);
		data->player = mlx_texture_to_image(data->window, texture);
		mlx_delete_texture(texture);
		mlx_image_to_window(data->window, data->player, \
		pos->x * BLOCK, pos->y * BLOCK);
	}
	else
	{
		texture = mlx_load_png("./textures/cat_left.png");
		mlx_delete_image(data->window, data->player);
		data->player = mlx_texture_to_image(data->window, texture);
		mlx_delete_texture(texture);
		mlx_image_to_window(data->window, data->player, \
		pos->x * BLOCK, pos->y * BLOCK);
	}
	n ++;
}

int	biggest_x_or_y(t_data *data, char c)
{
	t_pos	*map;
	int		n;

	n = 0;
	map = data->map;
	if (c == 'x')
	{
		while (map)
		{
			if (map->x > n)
				n = map->x;
			map = map->next;
		}
	}
	else if (c == 'y')
	{
		while (map)
		{
			if (map->y > n)
				n = map->y;
			map = map->next;
		}
	}
	return (n);
}
