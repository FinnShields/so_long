/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:17:00 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 11:05:09 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_pos	*new_pos(int x, int y, char c)
{
	t_pos	*rtn;

	rtn = (t_pos *) malloc(sizeof(t_pos));
	if (!rtn)
		return (NULL);
	rtn->x = x;
	rtn->y = y;
	rtn->content = c;
	rtn->next = NULL;
	return (rtn);
}

static void	add_to_end(t_pos **map, t_pos *new)
{
	t_pos	*last;

	if (!(*map))
	{
		*map = new;
		return ;
	}
	last = *map;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

static void	parse_line(t_pos **map, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		add_to_end(map, new_pos(x, y, line[x]));
		x ++;
	}
}

t_pos	*parse_map(char *file)
{
	char	*line;
	t_pos	*map;
	int		fd;
	int		y;

	y = 0;
	map = NULL;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		parse_line(&map, line, y++);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

t_data	*init_map(char *file)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = parse_map(file);
	if (!map_valid(data))
	{
		free_map(data->map);
		free(data);
		return (NULL);
	}
	data->window = init_window(data);
	data->obstacle = init_obs(data);
	data->background = init_back(data);
	data->player = init_player(data);
	data->collectable = init_col(data);
	data->exit = init_exit(data);
	return (data);
}
