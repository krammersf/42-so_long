/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:03:17 by fde-carv          #+#    #+#             */
/*   Updated: 2023/08/31 13:38:20 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../libfred/libft/libft.h"
# include "../libfred/get_next_line/get_next_line.h"
# include "../libfred/ft_printf/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <time.h>

# define TILE_SIZE 32
# define SP_LEN 9
# define SP_E_LEN 8
# define SP_ANIM 4
# define SP_ANIM_DELAY 100000 // (100000)
# define ENEMY_DELAY 100000 //( 100000) 
# define SPEED_PER_COLLET 20000 // (20000)
# define SPACES_PER_ENEMY 80 // 2 ate ... (80)
# define FLASH_ENEMY 1 // 1 ate ... (2 a 4)
# define TILLES "01CEP"
# define W1_XPM "textures/1.xpm"
# define W2_XPM "textures/2.xpm"
# define S_XPM "textures/0.xpm"
# define E_XPM "textures/E.xpm"
# define C1_XPM "textures/C1.xpm"
# define C2_XPM "textures/C2.xpm"
# define C3_XPM "textures/C3.xpm"
# define C4_XPM "textures/C4.xpm"
# define P0_XPM "textures/P0.xpm"
# define P1_XPM "textures/P1.xpm"
# define P2_XPM "textures/P2.xpm"
# define P3_XPM "textures/P3.xpm"
# define P4_XPM "textures/P4.xpm"
# define P5_XPM "textures/P5.xpm"
# define P6_XPM "textures/P6.xpm"
# define P7_XPM "textures/P7.xpm"
# define P8_XPM "textures/P8.xpm"
# define E0_XPM "textures/X0.xpm"
# define E1_XPM "textures/X1.xpm"
# define E2_XPM "textures/X2.xpm"
# define E3_XPM "textures/X3.xpm"
# define E4_XPM "textures/X4.xpm"
# define E5_XPM "textures/X5.xpm"
# define E6_XPM "textures/X6.xpm"
# define E7_XPM "textures/X7.xpm"

typedef enum e_key
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ESC = 65307,
	CURSOR_UP = 65362,
	CURSOR_LEFT = 65361,
	CURSOR_DOWN = 65364,
	CURSOR_RIGHT = 65363,
}				t_key;

typedef enum e_tile
{
	WALL = '1',
	SPACE = '0',
	EXIT = 'E',
	COLLECT = 'C',
	PLAYER = 'P',
	ENEMY,
}				t_tile;

typedef enum e_img_index
{
	FACE_LEFT = 2,
	FACE_RIGHT = 0,
	FACE_DOWN = 4,
	FACE_UP = 6, 
}				t_img_index;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct s_dummies
{
	t_point	current;
	char	current_tile;
	t_point	next;
	int		img_index;
	int		i_anim;
	int		collect;
	int		direction;
}				t_dummies;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	int			moves;
	t_dummies	player;
	int			flash_mode;
	int			clock_flash;
	t_img		img_p[SP_LEN];
	t_dummies	*enemy;
	t_img		img_e[SP_E_LEN];
	int			**path_grid;
	int			player_count;
	int			enemy_count;
	int			exit;
	int			collect;
	int			collect_count;
	int			total_collects;
	int			collected_collects;
	int			spaces;
	t_img		img_walls;
	t_img		img_walls2;
	t_img		img_space;
	t_img		img_exit;
	t_img		img_collect[SP_ANIM];
	int			anim_index;
	long		clock_anim;
	long		clock_enemy;
	int			x;
	int			y;

	double		zoom;
}				t_game;

int		exit_error(t_game *game, char *msg);
int		exit_game(t_game *game, char *msg);
int		exit_esc(t_game *game);
void	check_map(t_game *game);
void	init_game(t_game *game);
void	init_enemy(t_game *game);
int		key_press(int keycode, t_game *game);
void	render_move(t_game *game, char current, char next, t_dummies *dummy);
int		game_loop(t_game *game);
void	add_new_row(t_map *map);

void	move_enemy(t_game *game, t_dummies *enemy);
void	render_animation(t_game *game);
void	animate_game(t_game *game);
void	move_enemies(t_game *game);
void	count_collectibles(t_game *game);

void	create_path_grid(t_game *game);
int		is_player_at_position(t_game *game, t_point pos);
int		is_space_or_collect(t_game *game, int y, int x);
int		near_space_not_player(t_game *game, t_point pos);

int		count_collects(t_game *game);
void	check_characters(t_game *game);
#endif
