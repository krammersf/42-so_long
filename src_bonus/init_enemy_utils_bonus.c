/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:01:55 by fde-carv          #+#    #+#             */
/*   Updated: 2023/08/26 16:07:55 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	create_path_grid(t_game *game)
{
	int	i;

	game->path_grid = ft_calloc(game->map.rows, sizeof(int *));
	if (!game->path_grid)
		exit_error(game, "Couldn't allocate memory.");
	i = -1;
	while (++i < game->map.rows)
	{
		game->path_grid[i] = ft_calloc(game->map.cols, sizeof(int));
		if (!game->path_grid[i])
			exit_error(game, "Couldn't allocate memory.");
	}
}

int	is_player_at_position(t_game *game, t_point pos)
{
	return (game->map.grid[pos.y][pos.x] == PLAYER);
}

int	is_space_or_collect(t_game *game, int y, int x)
{
	return (game->map.grid[y][x] == SPACE || game->map.grid[y][x] == COLLECT);
}

int	near_space_not_player(t_game *game, t_point pos)
{
	game->y = pos.y - 3;
	game->y *= !(game->y < 0);
	while (game->y < pos.y + 3 && game->y < game->map.rows)
	{
		game->x = pos.x - 3;
		game->x *= !(game->x < 0);
		while (game->x < pos.x + 3 && game->x < game->map.cols)
		{
			if (is_player_at_position(game, (t_point){game->x, game->y}))
				return (0);
			game->x++;
		}
		game->y++;
	}
	game->x = 0;
	if (is_space_or_collect(game, pos.y, pos.x + 1))
		game->x++;
	if (is_space_or_collect(game, pos.y, pos.x - 1))
		game->x++;
	if (is_space_or_collect(game, pos.y + 1, pos.x))
		game->x++;
	if (is_space_or_collect(game, pos.y - 1, pos.x))
		game->x++;
	return (game->x > 2);
}

void	count_collectibles(t_game *game)
{
	int	i; 
	int	j;

	i = 0;
	game->total_collects = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.grid[i][j] == COLLECT)
				game->total_collects++;
			j++;
		}
		i++;
	}
}
