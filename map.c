/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:56:18 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/06 18:11:39 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_read_map(t_game *game, char *map_name)
{
	int		fd;
	int		height;
	char	*line;

	height = get_map_height(map_name, game);
	check_ber_format(map_name, height, game);
	if (game->empty_line == 1)
		ft_print_error(EMPTY_LINE, game);
	fd = open(map_name, O_RDONLY);
	if (fd <= FALSE)
		ft_print_error(OPEN_ERROR, game);
	line = get_next_line(fd);
	ft_init_map_info(game, line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
			game->map = ft_strjoin_n(game->map, line);
	}
	close(fd);
	game->map_len = ft_strlen(game->map);
}

void	ft_check_map(t_game *game)
{
	ft_check_sealed(game);
	ft_map_fit_screen(game);
	ft_check_valid_char(game);
	ft_check_rectangular(game);
	ft_check_playability(game);
}

void	ft_check_sealed(t_game *game)
{
	int	i;

	i = FALSE;
	while (i < game->map_len)
	{
		if (i > (game->map_len - game->width))
		{
			if (game->map[i] != WALL)
				ft_print_error(WALL_ERROR, game);
		}
		else if (i < game->width)
		{
			if (game->map[i] != WALL)
				ft_print_error(WALL_ERROR, game);
		}
		else if (i % game->width == FALSE
			|| (i % game->width) == game->width - TRUE)
		{
			if (game->map[i] != WALL)
				ft_print_error(WALL_ERROR, game);
		}
		i++;
	}
}

void	ft_check_playability(t_game *game)
{
	int	i;

	i = FALSE;
	game->player = i;
	game->object = FALSE;
	game->exit = i;
	game->storage = FALSE;
	while (i++ < game->map_len)
	{		
		if (game->map[i] == OBJECT)
			game->object++;
		else if (game->map[i] == PLAYER)
			game->player++;
		else if (game->map[i] == EXIT)
			game->exit++;
	}
	if (game->object == FALSE)
		ft_print_error(OBJECT_ERROR, game);
	if (game->player != TRUE)
		ft_print_error(PLAYER_ERROR, game);
	if (game->exit == FALSE)
		ft_print_error(EXIT_ERROR, game);
}
