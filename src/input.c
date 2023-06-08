/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:05:38 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/06 18:11:11 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_input_manager(int key_code, t_game *game)
{
	if (key_code == ESC_KEY)
		ft_exit_game(game);
	if (key_code == W_KEY || key_code == UP_KEY)
		ft_move_up(game);
	if (key_code == S_KEY || key_code == DOWN_KEY)
		ft_move_down(game);
	if (key_code == A_KEY || key_code == LEFT_KEY)
		ft_move_left(game);
	if (key_code == D_KEY || key_code == RIGHT_KEY)
		ft_move_right(game);
	return (EXIT_SUCCESS);
}

void	ft_move_up(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_len)
	{
		if (game->map[i] == PLAYER)
			break ;
		i++;
	}
	if (game->map[i - game->width] == OBJECT)
		game->storage++;
	if (game->map[i - game->width] == EXIT && game->storage == game->object)
		ft_win_game(game);
	else if (game->map[i - game->width] != WALL
		&& game->map[i - game->width] != EXIT)
	{
		game->map[i] = GROUND;
		game->map[i - game->width] = PLAYER;
		game->step++;
		ft_printf("Step: %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

void	ft_move_down(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_len)
	{
		if (game->map[i] == PLAYER)
			break ;
		i++;
	}
	if (game->map[i + game->width] == OBJECT)
		game->storage++;
	if (game->map[i + game->width] == EXIT && game->storage == game->object)
		ft_win_game(game);
	else if (game->map[i + game->width] != WALL
		&& game->map[i + game->width] != EXIT)
	{
		game->map[i] = GROUND;
		game->map[i + game->width] = PLAYER;
		game->step++;
		ft_printf("Step: %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

void	ft_move_left(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_len)
	{
		if (game->map[i] == PLAYER)
			break ;
		i++;
	}
	if (game->map[i - 1] == OBJECT)
		game->storage++;
	if (game->map[i - 1] == EXIT && game->storage == game->object)
		ft_win_game(game);
	else if (game->map[i - 1] != WALL && game->map[i - 1] != EXIT)
	{
		game->map[i] = GROUND;
		game->map[i - 1] = PLAYER;
		game->step++;
		ft_printf("Step: %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}

void	ft_move_right(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_len)
	{
		if (game->map[i] == PLAYER)
			break ;
		i++;
	}
	if (game->map[i + 1] == OBJECT)
		game->storage++;
	if (game->map[i + 1] == EXIT && game->storage == game->object)
		ft_win_game(game);
	else if (game->map[i + 1] != WALL && game->map[i + 1] != EXIT)
	{
		game->map[i] = GROUND;
		game->map[i + 1] = PLAYER;
		game->step++;
		ft_printf("Step: %d\n", game->step);
		ft_put_sprites_by_line(game);
	}
}
