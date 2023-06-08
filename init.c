/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:35:10 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/06 18:02:36 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		ft_exit_game(game);
	else if (keycode == W_KEY || keycode == UP_KEY)
		game->key_up = 1;
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		game->key_down = 1;
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		game->key_left = 1;
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		game->key_right = 1;
	return (EXIT_SUCCESS);
}

int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == W_KEY || keycode == UP_KEY)
		game->key_up = 0;
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		game->key_down = 0;
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		game->key_left = 0;
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		game->key_right = 0;
	return (EXIT_SUCCESS);
}

void	ft_init_game(t_game *game, char *map_name)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_print_error(MLX_INIT_ERROR, game);
	game->sprite = ft_init_sprites(game->mlx, game);
	ft_read_map(game, map_name);
	ft_check_map(game);
	game->win = mlx_new_window(game->mlx, game->width * 80,
			game->height * 80, GAME_TITLE);
	if (game->win == NULL)
		ft_print_error(MLX_WINDOW_ERROR, game);
	ft_put_sprites_by_line(game);
	mlx_hook(game->win, KEY_PRESS, 1L << 0, &ft_key_press, game);
	mlx_hook(game->win, KEY_RELEASE, 1L << 1, &ft_key_release, game);
}
