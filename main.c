/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:23:07 by fshields          #+#    #+#             */
/*   Updated: 2024/01/31 13:35:58 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_in_ber(char *str)
{
	str += (ft_strlen(str) - 4);
	if (ft_strncmp(".ber", str, 4) == 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		return (write(2, "Error\n", 6));
	if (!end_in_ber(argv[1]))
		return (write(2, "Error\nOnly .ber\n", 16));
	data = init_map(argv[1]);
	if (!data)
		return (write(2, "Error\nMap invalid\n", 18));
	mlx_key_hook(data->window, &key_hook, data);
	mlx_loop(data->window);
	free_data(data);
	return (0);
}
