/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 08:53:14 by lesantos          #+#    #+#             */
/*   Updated: 2022/05/30 02:07:38 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# define TILE_SIZE 16
# define XK_W 0x0077
# define XK_A 0x0061
# define XK_S 0x0073
# define XK_D 0x0064
# define XK_ESCAPE 0xff1b
# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROYNOTIFY 17
# define KEYPRESSMASK 1
# define KEYRELEASEMASK 2
# define STRUCTURENOTIFYMASK 131072

typedef struct s_lines_list
{
	char				*line;
	struct s_lines_list	*next;
}	t_lines_list;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_game_data
{
	void	*mlx;
	void	*win;
	char	*map;
	size_t	map_width;
	size_t	map_height;
	size_t	map_length;
	t_img	tile;
	t_img	wall;
	t_img	coin;
	t_img	exit;
	t_img	player;
	size_t	player_pos;
	size_t	coins_left;
	size_t	move_count;
}	t_data;
char	*load_map(char *map_name, t_data *data);
void	parse_map(t_data *data);
void	load_imgs(void *mlx, t_data *data);
int		player_move(int key_code, t_data *data);
int		handle_escape(int key_code, t_data *data);
int		handle_close(t_data *data);
int		render(t_data *data);

#endif
