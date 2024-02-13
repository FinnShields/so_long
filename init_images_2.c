/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:43:30 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 08:01:09 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*init_exit(t_data *data)
{
	mlx_image_t		*exit;
	mlx_texture_t	*texture;
	t_pos			*map;

	map = data->map;
	texture = mlx_load_png("./textures/big_door.png");
	exit = mlx_texture_to_image(data->window, texture);
	mlx_delete_texture(texture);
	if (!exit)
	{
		mlx_close_window(data->window);
		return (NULL);
	}
	while (map)
	{
		if (map->content == 'E')
		{
			mlx_image_to_window(data->window, exit, (map->x * BLOCK), \
			(map->y * BLOCK));
			return (exit);
		}
		map = map->next;
	}
	return (exit);
}

mlx_image_t	*init_back(t_data *data)
{
	mlx_image_t		*back;
	mlx_t			*window;
	mlx_texture_t	*texture;
	t_pos			*map;

	window = data->window;
	map = data->map;
	texture = mlx_load_png("./textures/big_dirt.png");
	back = mlx_texture_to_image(window, texture);
	mlx_delete_texture(texture);
	if (!back)
	{
		mlx_close_window(window);
		return (NULL);
	}
	while (map)
	{
		if (map->content != '1')
			mlx_image_to_window(window, back, (map->x * BLOCK), \
			(map->y * BLOCK));
		map = map->next;
	}
	return (back);
}

mlx_image_t	*init_col(t_data *data)
{
	mlx_image_t		*collect;
	mlx_t			*window;
	t_pos			*map;
	mlx_texture_t	*texture;

	window = data->window;
	map = data->map;
	texture = mlx_load_png("./textures/Skull.png");
	collect = mlx_texture_to_image(window, texture);
	mlx_delete_texture(texture);
	if (!collect)
	{
		mlx_close_window(window);
		return (NULL);
	}
	while (map)
	{
		if (map->content == 'C')
			mlx_image_to_window(window, collect, (map->x * BLOCK) + 9, \
			(map->y * BLOCK) + 9);
		map = map->next;
	}
	return (collect);
}
