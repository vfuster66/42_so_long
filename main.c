/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:15:46 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/06 17:52:50 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->sprite.player)
		mlx_destroy_image(game->mlx, game->sprite.player);
	if (game->sprite.ground)
		mlx_destroy_image(game->mlx, game->sprite.ground);
	if (game->sprite.wall)
		mlx_destroy_image(game->mlx, game->sprite.wall);
	if (game->sprite.object)
		mlx_destroy_image(game->mlx, game->sprite.object);
	if (game->sprite.exit)
		mlx_destroy_image(game->mlx, game->sprite.exit);
	if (game->map)
		free(game->map);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game)
		free(game);
}

void	ft_map_fit_screen(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	width = 0;
	mlx_get_screen_size(game->mlx, &width, &height);
	if (game->width * 64 > width || game->height * 64 > height)
		ft_print_error(MAP_TOO_BIG, game);
}

int	main(int argc, char *argv[], char **envp)
{
	t_game	*game;

	if (argc != 2)
	{
		write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
		write(STDERR_FILENO, USAGE_MSG, ft_strlen(USAGE_MSG));
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_check_env(envp);
		game = ft_calloc(sizeof(t_game), sizeof(t_game));
		if (game == NULL)
			ft_print_error(GAME_ERROR, game);
		if (!ft_check_extension(argv[1], BER_EXTENSION))
			ft_print_error(EXTENSION_ERROR, game);
		ft_init_game(game, argv[1]);
		mlx_key_hook(game->win, &ft_input_manager, game);
		mlx_hook(game->win, CLOSE_ICON, FALSE, &ft_exit_game, game);
		mlx_loop(game->mlx);
	}
	return (EXIT_SUCCESS);
}
