/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:01:20 by fde-carv          #+#    #+#             */
/*   Updated: 2023/08/27 15:05:05 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	print_moves(t_game *game, t_img *image)
{
	char		*moves;

	mlx_put_image_to_window(game->mlx, game->win,
		image->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win,
		image->img, TILE_SIZE, 0);
	mlx_put_image_to_window(game->mlx, game->win,
		image->img, 2 * TILE_SIZE, 0);
	mlx_string_put(game->mlx, game->win, 14, 20, 0xFF0000, "Moves:  ");
	mlx_string_put(game->mlx, game->win, 54, 20, 0xFFCC33,
		moves = ft_itoa(++game->moves));
	free(moves);
}

static void	check_move(t_game *game, int x, int y)
{
	game->player.i_anim = 1;
	if (game->map.grid[y][x] == WALL)
		return ;
	print_moves(game, &(game->img_walls2));
	if (game->map.grid[y][x] == COLLECT)
	{
		game->map.grid[y][x] = SPACE;
		game->collected_collects++;
	}
	if (game->map.grid[y][x] == EXIT &&
		(game->collected_collects == game->total_collects))
		exit_game(game, "Congratulations! 🏆 You WIN 🏆");
	if (game->map.grid[y][x] == EXIT)
		ft_printf("You still have to eat more balls! 🤪\n");
	if (game->map.grid[y][x] == ENEMY)
		exit_game(game, "You lost !!! 👻");
	game->player.next = (t_point){x, y};
	render_move(game, game->player.current_tile, PLAYER, &game->player);
	game->map.grid[game->player.current.y][game->player.current.x]
		= game->player.current_tile;
	game->player.current = game->player.next;
	game->player.current_tile = game->map.grid[y][x];
	game->map.grid[y][x] = PLAYER;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W || keycode == CURSOR_UP)
	{
		game->player.img_index = FACE_UP;
		check_move(game, game->player.current.x, game->player.current.y - 1);
	}
	else if (keycode == A || keycode == CURSOR_LEFT)
	{
		game->player.img_index = FACE_LEFT;
		check_move(game, game->player.current.x - 1, game->player.current.y);
	}
	else if (keycode == S || keycode == CURSOR_DOWN)
	{
		game->player.img_index = FACE_DOWN;
		check_move(game, game->player.current.x, game->player.current.y + 1);
	}
	else if (keycode == D || keycode == CURSOR_RIGHT)
	{
		game->player.img_index = FACE_RIGHT;
		check_move(game, game->player.current.x + 1, game->player.current.y);
	}
	else if (keycode == ESC)
		exit_game(game, "You gave up! 😡");
	return (0);
}
