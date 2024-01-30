/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:01:55 by fde-carv          #+#    #+#             */
/*   Updated: 2023/08/26 18:27:10 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	count_spaces_and_collects(t_game *game)
{
	int	space_count;
	int	collect_count;
	int	i;
	int	j;

	space_count = 0;
	collect_count = 0;
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.grid[i][j] == SPACE)
				space_count++;
			if (game->map.grid[i][j] == COLLECT)
				collect_count++;
			j++;
		}
		i++;
	}
	return (space_count + collect_count);
}

static void	allocate_enemies(t_game *game)
{
	int	k;
	int	time_out;
	int	i;
	int	j;

	k = 0;
	time_out = 1000;
	while (k < game->enemy_count && time_out)
	{
		i = rand() % (game->map.rows);
		j = rand() % (game->map.cols);
		if (game->map.grid[i][j] == SPACE
			|| game->map.grid[i][j] == COLLECT)
		{
			if (near_space_not_player(game, (t_point){j, i}))
			{
				game->enemy[k].current = (t_point){j, i};
				game->enemy[k].next = (t_point){j, i};
				game->map.grid[i][j] = ENEMY;
				k++;
			}
			time_out--;
		}
	}
}

static void	place_enemies(t_game *game)
{
	int	total_tiles;

	total_tiles = count_spaces_and_collects(game);
	if (total_tiles < game->enemy_count)
		return ;
	allocate_enemies(game);
}

static void	count_spaces(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.grid[i][j] == SPACE
				|| game->map.grid[i][j] == COLLECT)
				game->spaces++;
		}
	}
}

void	init_enemy(t_game *game)
{
	int	total_coins;

	count_spaces(game);
	count_collectibles(game); 
	total_coins = game->total_collects;
	if (total_coins > 10)
		game->enemy_count = game->spaces / SPACES_PER_ENEMY * 2;
	else
		game->enemy_count = game->spaces / SPACES_PER_ENEMY;
	game->enemy = ft_calloc(game->enemy_count + 1, sizeof(t_dummies));
	if (!game->enemy)
		exit_error(game, "Couldn't allocate memory.");
	place_enemies(game);
	create_path_grid(game);
}
