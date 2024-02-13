/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:32:38 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 13:37:26 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <fcntl.h>

# define BLOCK 50

typedef struct s_pos
{
	int				x;
	int				y;
	char			content;
	struct s_pos	*next;
}	t_pos;

typedef struct s_player_pos
{
	int	x;
	int	y;
}	t_player_pos;

typedef struct s_data
{
	mlx_t			*window;
	mlx_image_t		*player;
	mlx_image_t		*exit;
	mlx_image_t		*obstacle;
	mlx_image_t		*background;
	mlx_image_t		*collectable;
	t_pos			*map;
	t_player_pos	*player_pos;
}	t_data;

int			end_in_ber(char *str);

//utils.c
void		free_data(t_data *data);
int			is_obstacle(t_data *data, int x, int y);
void		swap_cat(t_data *data);
void		free_map(t_pos *map);
int			biggest_x_or_y(t_data *data, char c);

//init_map.c
t_pos		*parse_map(char *file);
t_data		*init_map(char *file);

//init_window.c
mlx_t		*init_window(t_data *data);

//init_images_1.c
mlx_image_t	*init_obs(t_data *data);
mlx_image_t	*init_player(t_data *data);

//init_images_2.c
mlx_image_t	*init_col(t_data *data);
mlx_image_t	*init_exit(t_data *data);
mlx_image_t	*init_back(t_data *data);

//hooks.c
void		key_hook(mlx_key_data_t keydata, void *param);

//collectables.c
void		handle_collectables(t_data *data);
int			all_collected(t_data *data);
int			no_of_collectables(t_data *data);

//handlers.c
void		handlers(t_data *data);

//map_valid_1.c
int			map_valid(t_data *data);

//map_valid_2.c
int			check_border(t_data *data);

//valid_path.c
void		move(t_data *data, int x, int y);
int			check_for_unchanged(t_data *data);
void		reformat_map(t_data *data);
int			check_valid_path(t_data *data);

//valid_path_utils.c
int			get_p_x(t_data *data);
int			get_p_y(t_data *data);
void		set_square(t_data *data, int x, int y);
int			is_inside(t_data *data, int x, int y);

#endif