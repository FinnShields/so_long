/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:31:30 by fshields          #+#    #+#             */
/*   Updated: 2024/02/08 13:02:05 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*init_obs(t_data *data)
{
	mlx_image_t		*obstacle;
	mlx_t			*window;
	t_pos			*map;
	mlx_texture_t	*texture;

	window = data->window;
	map = data->map;
	texture = mlx_load_png("./textures/big_stones.png");
	obstacle = mlx_texture_to_image(window, texture);
	mlx_delete_texture(texture);
	if (!obstacle)
	{
		mlx_close_window(window);
		return (NULL);
	}
	while (map)
	{
		if (map->content == '1')
			mlx_image_to_window(window, obstacle, (map->x * BLOCK), \
			(map->y * BLOCK));
		map = map->next;
	}
	return (obstacle);
}

static int	init_player_pos(t_data *data)
{
	t_pos	*map;

	map = data->map;
	data->player_pos = (t_player_pos *) malloc(sizeof(t_player_pos));
	if (!data->player_pos)
		return (-1);
	while (map)
	{
		if (map->content == 'P')
		{
			data->player_pos->x = map->x;
			data->player_pos->y = map->y;
		}
		map = map->next;
	}
	return (0);
}

mlx_image_t	*init_player(t_data *data)
{
	mlx_image_t		*player;
	mlx_texture_t	*texture;
	mlx_t			*window;
	t_pos			*map;

	window = data->window;
	map = data->map;
	texture = mlx_load_png("./textures/cat_left.png");
	if (init_player_pos(data) == -1)
		return (NULL);
	player = mlx_texture_to_image(window, texture);
	mlx_delete_texture(texture);
	if (!player)
	{
		mlx_close_window(window);
		return (NULL);
	}
	while (map)
	{
		if (map->content == 'P')
			mlx_image_to_window(window, player, (map->x * BLOCK), \
			(map->y * BLOCK));
		map = map->next;
	}
	return (player);
}
