/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:39:53 by lesantos          #+#    #+#             */
/*   Updated: 2022/05/29 22:46:10 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	handle_escape(int key_code, t_data *data)
{
	if (key_code == XK_ESCAPE)
		mlx_loop_end(data->mlx);
	return (0);
}

int	player_move(int key_code, t_data *data)
{
	size_t	new_pos;

	new_pos = data->player_pos;
	if (key_code == XK_W)
		new_pos += -data->map_width;
	else if (key_code == XK_S)
		new_pos += data->map_width;
	else if (key_code == XK_A)
		new_pos += -1;
	else if (key_code == XK_D)
		new_pos += 1;
	if (new_pos == data->player_pos || data->map[new_pos] == '1'
		|| (data->map[new_pos] == 'E' && data->coins_left))
		return (0);
	ft_printf("Movement count: %d\n", ++data->move_count);
	if (data->map[new_pos] == 'E')
		mlx_loop_end(data->mlx);
	if (data->map[new_pos] == 'C')
		data->coins_left--;
	data->map[data->player_pos] = '0';
	data->map[new_pos] = 'P';
	data->player_pos = new_pos;
	return (0);
}
