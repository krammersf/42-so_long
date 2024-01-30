/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:56:34 by fde-carv          #+#    #+#             */
/*   Updated: 2023/08/27 16:32:17 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	put_tile(t_game *game, t_img *img, int i, t_point p)
{
	mlx_put_image_to_window(game->mlx, game->win, img[i].img,
		p.x * TILE_SIZE, p.y * TILE_SIZE);
}

static void	check_move(t_game *game, t_dummies *enemy, int x, int y)
{
	if (game->map.grid[y][x] == WALL || game->map.grid[y][x] == ENEMY)
	{
		enemy->direction += rand() % 2 + 1;
		enemy->direction = enemy->direction % 4;
		return ;
	}
	if (game->map.grid[y][x] == PLAYER)
		exit_game(game, "The ghost caught you! 👻");
	enemy->next = (t_point){x, y};
	render_move(game, enemy->current_tile, ENEMY, enemy);
	game->map.grid[enemy->current.y][enemy->current.x] = enemy->current_tile;
	enemy->current = enemy->next;
	enemy->current_tile = game->map.grid[y][x];
	game->map.grid[y][x] = ENEMY;
}

void	move_enemy(t_game *game, t_dummies *enemy)
{
	enemy->i_anim = 1;
	if (enemy->direction == 0)
	{
		enemy->img_index = FACE_UP;
		put_tile(game, game->img_e, enemy->img_index, enemy->current);
		check_move(game, enemy, enemy->current.x, enemy->current.y - 1);
	}
	else if (enemy->direction == 1)
	{
		enemy->img_index = FACE_LEFT;
		put_tile(game, game->img_e, enemy->img_index, enemy->current);
		check_move(game, enemy, enemy->current.x - 1, enemy->current.y);
	}
	else if (enemy->direction == 2)
	{
		enemy->img_index = FACE_DOWN;
		put_tile(game, game->img_e, enemy->img_index, enemy->current);
		check_move(game, enemy, enemy->current.x, enemy->current.y + 1);
	}
	else if (enemy->direction == 3)
	{
		enemy->img_index = FACE_RIGHT;
		put_tile(game, game->img_e, enemy->img_index, enemy->current);
		check_move(game, enemy, enemy->current.x + 1, enemy->current.y);
	}
}

void	render_animation(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
			if (game->map.grid[i][j] == COLLECT)
				put_tile(game, game->img_collect, game->anim_index,
					(t_point){j, i});
	}
	i = -1;
	while (game->enemy[0].current.x && ++i < game->enemy_count)
	{
		if (game->enemy[i].i_anim)
		{
			put_tile(game, game->img_e, game->enemy[i].img_index
				+ (game->enemy[i].i_anim % 2), game->enemy[i].current);
		}
	}
	if (game->player.i_anim)
		put_tile(game, game->img_p, game->player.img_index
			+ (game->player.i_anim % 2), game->player.current);
}

int	game_loop(t_game *game)
{
	animate_game(game);
	move_enemies(game);
	return (0);
}
