/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:16:07 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/06 17:32:18 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_error(char *error_msg, t_game *game)
{
	ft_free_all(game);
	write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	exit(EXIT_FAILURE);
}

int	ft_win_game(t_game *game)
{
	ft_printf("Congratulations, you win with %d moves\n", game->step);
	ft_free_all(game);
	exit(EXIT_SUCCESS);
}

int	ft_exit_game(t_game *game)
{
	ft_free_all(game);
	exit(EXIT_SUCCESS);
}

void	ft_check_valid_char(t_game *game)
{
	int	i;

	i = FALSE;
	while (game->map[i] != '\0')
	{
		if (game->map[i] != WALL
			&& game->map[i] != PLAYER
			&& game->map[i] != OBJECT
			&& game->map[i] != EXIT
			&& game->map[i] != GROUND)
			ft_print_error(BAD_MAP_ERROR, game);
		i++;
	}
}
