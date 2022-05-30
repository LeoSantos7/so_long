/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:37:25 by lesantos          #+#    #+#             */
/*   Updated: 2022/05/30 02:39:45 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int			open_map_file(char *map_name);
static t_lines_list	*read_map_file(int fd, t_data *data);
static char			*list_to_str(t_lines_list *list, t_data *data);
static void			perror_exit(char *msg, t_lines_list *list,
						t_lines_list *last);

char	*load_map(char *map_name, t_data *data)
{
	int				fd;
	t_lines_list	*lines_list;
	char			*map;

	fd = open_map_file(map_name);
	lines_list = read_map_file(fd, data);
	map = list_to_str(lines_list, data);
	return (map);
}

static int	open_map_file(char *map_name)
{
	size_t	name_len;
	char	*map_path;
	int		fd;

	name_len = ft_strlen(map_name);
	if (ft_strncmp(&map_name[name_len - 4], ".ber", 4))
	{
		ft_printf("Wrong file extension.\n");
		exit(1);
	}
	map_path = ft_strjoin("maps/", map_name);
	fd = open(map_path, O_RDONLY);
	free(map_path);
	if (fd == -1)
	{
		ft_printf("Unable to open given map file.\n");
		exit(1);
	}
	return (fd);
}

static t_lines_list	*read_map_file(int fd, t_data *data)
{
	t_lines_list	*list;
	t_lines_list	*current;

	data->map_height = 0;
	data->map_length = 0;
	list = malloc(sizeof(t_lines_list));
	list->line = get_next_line(fd);
	if (!list->line)
		perror_exit("Emtpy map file.", list, list);
	data->map_width = ft_strlen(list->line) - 1;
	current = list;
	while (current->line)
	{
		if (data->map_width != ft_strlen(current->line) - 1)
			perror_exit("Map should be a rectangle.", list, current);
		data->map_height++;
		data->map_length += data->map_width;
		current->next = malloc(sizeof(t_lines_list));
		current = current->next;
		current->line = get_next_line(fd);
	}
	return (list);
}

char	*list_to_str(t_lines_list *list, t_data *data)
{
	t_lines_list	*current;
	char			*str;
	size_t			i;

	str = malloc(data->map_length + 1);
	i = 0;
	current = list;
	while (current->line)
	{
		ft_strncpy(str + i, current->line, data->map_width);
		i += data->map_width;
		list = list->next;
		free(current->line);
		free(current);
		current = list;
	}
	free(current);
	return (str);
}

void	perror_exit(char *msg, t_lines_list *list, t_lines_list *last)
{
	t_lines_list	*current;

	ft_printf("Error\n%s\n", msg);
	current = list;
	while (current != last)
	{
		list = list->next;
		free(current->line);
		free(current);
		current = list;
	}
	free(current->line);
	free(current);
	exit(1);
}
