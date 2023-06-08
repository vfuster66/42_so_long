/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:15:54 by vfuster-          #+#    #+#             */
/*   Updated: 2023/06/06 17:52:19 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"

# define BER_EXTENSION		".ber"
# define ERROR_MSG		"Error\n"
# define GAME_TITLE		"./so_long"
# define USAGE_MSG		"./so_long [pass to map][map name].ber\n"
# define NO_ENV_ERROR		"No variable environment available\n"
# define NO_DISP_ERROR		"DISPLAY not found in env\n"
# define GAME_ERROR		"Malloc t_game fail\n"
# define BAD_MAP_ERROR		"Map Should contain char : '1' 'P' 'C' 'E' '0'\n"
# define WALL_ERROR		".ber should be surrounded by walls : 1\n"
# define FORM_ERROR		".ber should be in rectangular form !\n"
# define OBJECT_ERROR		".ber should have at least one collectible -> C\n"
# define PLAYER_ERROR		".ber should have one starting point -> P\n"
# define EXIT_ERROR		".ber should have at east one exit -> E\n"
# define EXTENSION_ERROR	"Map extension should be a .ber\n"
# define OPEN_ERROR		".ber fail to open\n"
# define MLX_INIT_ERROR		"mlx_init() fail\n"
# define MLX_WINDOW_ERROR	"mlx_new_window() fail\n"
# define PLAYER_XPM_ERROR	"player.xpm fail to load\n"
# define GROUND_XPM_ERROR	"ground.xpm fail to load\n"
# define WALL_XPM_ERROR		"wall.xpm fail to load\n"
# define OBJECT_XPM_ERROR	"key.xpm fail to load\n"
# define EXIT_XPM_ERROR		"exit.xpm fail to load\n"
# define EMPTY_LINE 		"Remove that empty line at the top or middle\n"
# define MAP_TOO_BIG    	"Reduce map size, map too big for the screen\n"

typedef enum e_key_code
{
	CLOSE_ICON = 17,
	ESC_KEY = 65307,
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	UP_KEY = 65362,
	DOWN_KEY = 65364,
	LEFT_KEY = 65361,
	RIGHT_KEY = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
}	t_key_code;

typedef enum e_map_char
{
	WALL = '1',
	PLAYER = 'P',
	OBJECT ='C',
	EXIT = 'E',
	GROUND = '0'
}	t_map_char;

// true false enum for loop if etc
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

// sprite struct
typedef struct s_sprites
{
	void	*player;
	void	*ground;
	void	*wall;
	void	*object;
	void	*exit;
}		t_sprites;

// game struct
typedef struct s_game
{
	t_sprites		sprite;
	long long int	step;
	void			*mlx;
	void			*win;
	char			*map;
	long long int	map_len;
	long long int	width;
	long long int	height;
	long long int	object;
	long long int	storage;
	long long int	exit;
	long long int	player;
	long long int	empty_line;
	int				key_up;
	int				key_down;
	int				key_right;
	int				key_left;
}		t_game;

//main.c

void		ft_map_fit_screen(t_game *game);
void		ft_free_all(t_game *game);

//check_map.c   

int			get_map_height(char *map_name, t_game *game);
void		check_ber_format(char *map_name, int height, t_game *game);
void		ft_init_map_info(t_game *game, char *line);

//input.c
int			ft_input_manager(int key, t_game *game);
void		ft_move_up(t_game *game);
void		ft_move_down(t_game *game);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);

//map.c
void		ft_read_map(t_game *game, char *map_name);
void		ft_check_map(t_game *game);
void		ft_check_sealed(t_game *game);
void		ft_check_rectangular(t_game *game);
void		ft_check_playability(t_game *game);

//so_long.c
int			ft_exit_game(t_game *game);
int			ft_win_game(t_game *game);
void		ft_print_error(char *error_msg, t_game *game);
void		ft_check_valid_char(t_game *game);

//sprites.c
t_sprites	ft_init_sprites(void *mlx, t_game *game);
void		ft_put_sprites_by_line(t_game *game);
void		ft_put_all_sprites_to_line(t_game *game, int width, int height);

//tools_.c
char		*ft_strdup_n(char *s1);
int			ft_strlcpy_n(char *dst, char *src, int dst_size);
char		*ft_strjoin_n(char *s1, char *s2);
void		ft_check_env(char **env);
int			ft_check_extension(char *map_name, char *extension);

//init.c
int			ft_key_press(int keycode, t_game *game);
int			ft_key_release(int keycode, t_game *game);
void		ft_init_game(t_game *game, char *map_name);

#endif
