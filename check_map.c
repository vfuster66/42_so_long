/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:39:33 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/06 14:34:21 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/get_next_line.h"

int	get_map_height(char *map_name, t_game *game)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd <= FALSE)
		ft_print_error(OPEN_ERROR, game);
	line = get_next_line(fd);
	height = TRUE;
	free(line);
	while (line)
	{
		height++;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	return (height);
}

void	check_ber_format(char *map_name, int height, t_game *game)
{
	int		fd;
	char	*line;
	int		curr_height;

	game->empty_line = 0;
	fd = open(map_name, O_RDONLY);
	if (fd <= FALSE)
		ft_print_error(OPEN_ERROR, game);
	line = get_next_line(fd);
	if (line == NULL || line[FALSE] == '\n')
		game->empty_line = 1;
	curr_height = TRUE;
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		curr_height++;
		if ((line == NULL || line[FALSE] == '\n') && curr_height != height)
			game->empty_line = 1;
		if ((curr_height == height) && line == NULL)
			return ;
		free(line);
	}
	close(fd);
}

void	ft_init_map_info(t_game *game, char *line)
{
	game->height = FALSE;
	game->step = FALSE;
	game->width = ft_strlen(line) - TRUE;
	game->map = ft_strdup_n(line);
	free(line);
}

void	ft_check_rectangular(t_game *game)
{
	if (game->height * game->width != game->map_len)
		ft_print_error(FORM_ERROR, game);
}
