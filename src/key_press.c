/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:01:20 by fde-carv          #+#    #+#             */
/*   Updated: 2023/08/26 16:03:07 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_tile_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_p[game->player.img_index].img,
		game->player.current.x * TILE_SIZE, game->player.current.y * TILE_SIZE);
}

static void	print_moves(t_game *game)
{
	ft_putstr_fd("\033[32mMoves: ", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putnbr_fd(++game->moves, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("\033[0m", 1);
}

static void	check_move(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == WALL)
		return ;
	print_moves(game);
	if (game->map.grid[y][x] == COLLECT)
	{
		game->map.grid[y][x] = SPACE;
		game->collect--;
	}
	if (game->map.grid[y][x] == EXIT && !game->collect)
		exit_game(game, "Congratulations! 🏆 You WIN 🏆");
	if (game->map.grid[y][x] == EXIT)
		ft_printf("You still have to eat more balls! 🤪\n");
	game->player.next = (t_point){x, y};
	render_move(game, game->player.current_tile, PLAYER, &game->player);
	game->map.grid[game->player.current.y][game->player.current.x]
		= game->player.current_tile;
	game->player.current = game->player.next;
	game->player.current_tile = game->map.grid[y][x];
	game->map.grid[y][x] = PLAYER;
}

int	key_press_moves(int keycode, t_game *game)
{
	if (keycode == W || keycode == CURSOR_UP)
	{
		game->player.img_index = FACE_UP;
		put_tile_player(game);
		check_move(game, game->player.current.x, game->player.current.y - 1);
	}
	else if (keycode == A || keycode == CURSOR_LEFT)
	{
		game->player.img_index = FACE_LEFT;
		put_tile_player(game);
		check_move(game, game->player.current.x - 1, game->player.current.y);
	}
	else if (keycode == S || keycode == CURSOR_DOWN)
	{
		game->player.img_index = FACE_DOWN;
		put_tile_player(game);
		check_move(game, game->player.current.x, game->player.current.y + 1);
	}
	else if (keycode == D || keycode == CURSOR_RIGHT)
	{
		game->player.img_index = FACE_RIGHT;
		put_tile_player(game);
		check_move(game, game->player.current.x + 1, game->player.current.y);
	}
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	key_press_moves(keycode, game);
	if (keycode == ESC)
		exit_game(game, "You gave up! 😡");
	return (0);
}
