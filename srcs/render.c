/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:52:44 by lesantos          #+#    #+#             */
/*   Updated: 2022/05/29 15:12:00 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_data *data)
{
	int		i;
	char	current_char;
	void	*img_ptr;

	i = -1;
	while (data->map[++i])
	{
		current_char = data->map[i];
		if (current_char == '0')
			img_ptr = data->tile.img;
		else if (current_char == '1')
			img_ptr = data->wall.img;
		else if (current_char == 'C')
			img_ptr = data->coin.img;
		else if (current_char == 'E')
			img_ptr = data->exit.img;
		else if (current_char == 'P')
			img_ptr = data->player.img;
		mlx_put_image_to_window(data->mlx, data->win, img_ptr,
			i % data->map_width * TILE_SIZE, i / data->map_width * TILE_SIZE);
	}
	return (0);
}

void	load_imgs(void *mlx, t_data *data)
{
	data->tile.img = mlx_xpm_file_to_image(mlx, "assets/tile.xpm",
			&data->tile.width, &data->tile.height);
	data->wall.img = mlx_xpm_file_to_image(mlx, "assets/wall.xpm",
			&data->wall.width, &data->wall.height);
	data->coin.img = mlx_xpm_file_to_image(mlx, "assets/coin.xpm",
			&data->coin.width, &data->coin.height);
	data->player.img = mlx_xpm_file_to_image(mlx, "assets/player.xpm",
			&data->player.width, &data->player.height);
	data->exit.img = mlx_xpm_file_to_image(mlx, "assets/exit.xpm",
			&data->exit.width, &data->exit.height);
}
