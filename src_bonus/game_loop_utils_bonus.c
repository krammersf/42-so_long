/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:56:34 by fde-carv          #+#    #+#             */
/*   Updated: 2023/08/28 13:48:50 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	animate_game(t_game *game)
{
	if (clock() - game->clock_anim >= SP_ANIM_DELAY)
	{
		game->clock_anim = clock();
		render_animation(game);
		game->anim_index++;
		game->anim_index = (game->anim_index) % SP_ANIM;
		if (game->player.i_anim)
			game->player.i_anim = (game->player.i_anim + 1) % 3;
	}
}

static void	speed_enemies(t_game *game)
{
	int	enemy;
	int	i;

	enemy = -1;
	while (game->enemy[++enemy].current.x && (enemy < game->enemy_count))
	{
		i = 1;
		while (++i <= FLASH_ENEMY)
		{
			if (rand() % (i / 2))
				move_enemy(game, &game->enemy[enemy]);
		}
	}
}

void	move_enemies(t_game *game)
{
	int	enemy;
	int	rand_value;

	enemy = -1;
	if (game->enemy[0].current.x && clock() - (game->clock_enemy)
		>= ENEMY_DELAY)
	{
		if (game->total_collects > 10)
			game->clock_enemy = clock() + game->collect * SPEED_PER_COLLET / 50;
		else
			game->clock_enemy = clock() + game->collect * SPEED_PER_COLLET / 1;
		while (game->enemy[++enemy].current.x && (enemy < game->enemy_count))
		{
			rand_value = rand() % 100;
			if (rand_value < 50)
				game->enemy[enemy].direction = rand() % 2;
			else
				game->enemy[enemy].direction = 2 + rand() % 2;
			move_enemy(game, &game->enemy[enemy]);
			speed_enemies(game);
		}
	}
}
