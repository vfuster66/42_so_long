/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:05:04 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/06 18:12:06 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_sprites	ft_init_sprites(void *mlx, t_game *game)
{
	t_sprites	sprite;
	int			width;
	int			height;

	sprite.player = mlx_xpm_file_to_image(mlx,
			"img/busty.xpm", &width, &height);
	if (sprite.player == NULL)
		ft_print_error(PLAYER_XPM_ERROR, game);
	sprite.ground = mlx_xpm_file_to_image(mlx,
			"img/ground.xpm", &width, &height);
	if (sprite.ground == NULL)
		ft_print_error(GROUND_XPM_ERROR, game);
	sprite.wall = mlx_xpm_file_to_image(mlx,
			"img/wall.xpm", &width, &height);
	if (sprite.wall == NULL)
		ft_print_error(WALL_XPM_ERROR, game);
	sprite.object = mlx_xpm_file_to_image(mlx,
			"img/object.xpm", &width, &height);
	if (sprite.object == NULL)
		ft_print_error(OBJECT_XPM_ERROR, game);
	sprite.exit = mlx_xpm_file_to_image(mlx,
			"img/exit.xpm", &width, &height);
	if (sprite.exit == NULL)
		ft_print_error(EXIT_XPM_ERROR, game);
	return (sprite);
}

void	ft_put_sprites_by_line(t_game *game)
{
	int		width;
	int		height;

	height = FALSE;
	while (height < game->height)
	{
		width = FALSE;
		while (width < game->width)
		{
			ft_put_all_sprites_to_line(game, width, height);
			width++;
		}
		height++;
	}
}

void	ft_put_all_sprites_to_line(t_game *game, int width, int height)
{
	if (game->map[height * game->width + width] == WALL)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.wall, width * 80, height * 80);
	else if (game->map[height * game->width + width] == OBJECT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.object, width * 80, height * 80);
	else if (game->map[height * game->width + width] == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.player, width * 80, height * 80);
	else if (game->map[height * game->width + width] == EXIT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.exit, width * 80, height * 80);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.ground, width * 80, height * 80);
}
