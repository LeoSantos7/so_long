/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 08:52:46 by lesantos          #+#    #+#             */
/*   Updated: 2022/05/30 00:35:57 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_memory(t_data *data);

int	main(int argc, char *argv[])
{
	t_data			data;

	if (argc != 2)
	{
		ft_printf("Error\nThe program should receive exactly one argument.\n");
		exit(1);
	}
	data.map = load_map(argv[1], &data);
	parse_map(&data);
	data.move_count = 0;
	data.mlx = mlx_init();
	load_imgs(data.mlx, &data);
	data.win = mlx_new_window(data.mlx, data.map_width * TILE_SIZE,
			data.map_height * TILE_SIZE, argv[0]);
	mlx_hook(data.win, KEYPRESS, KEYPRESSMASK, player_move, &data);
	mlx_hook(data.win, KEYRELEASE, KEYRELEASEMASK, handle_escape, &data);
	mlx_hook(data.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, handle_close, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	clean_memory(&data);
}

static void	clean_memory(t_data *data)
{
	mlx_destroy_image(data->mlx, data->tile.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_image(data->mlx, data->coin.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->map);
	free(data->mlx);
}

void	perror_clean(char *msg, t_data *data)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	mlx_loop_end(data->mlx);
}
