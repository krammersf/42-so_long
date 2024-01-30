/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:24:21 by fde-carv          #+#    #+#             */
/*   Updated: 2023/08/26 16:08:41 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	render_map(t_game *game, int i, int j)
{
	t_img	*tile;

	tile = &game->img_walls;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.grid[i][j] == WALL)
				tile = &game->img_walls;
			else if (game->map.grid[i][j] == SPACE)
				tile = &game->img_space;
			else if (game->map.grid[i][j] == EXIT)
				tile = &game->img_exit;
			else if (game->map.grid[i][j] == COLLECT)
				tile = &game->img_collect[0];
			else if (game->map.grid[i][j] == PLAYER)
				tile = &game->img_p[0];
			mlx_put_image_to_window(game->mlx, game->win, tile->img,
				j * TILE_SIZE, i * TILE_SIZE);
		}
	}
}

static void	check_textures(t_game *game)
{
	if (!game->img_walls.img || !game->img_walls2.img
		|| !game->img_space.img || !game->img_exit.img
		|| !game->img_collect[0].img || !game->img_collect[1].img
		|| !game->img_collect[2].img || !game->img_collect[3].img
		|| !game->img_p[0].img || !game->img_p[1].img
		|| !game->img_p[2].img || !game->img_p[3].img
		|| !game->img_p[4].img || !game->img_p[5].img
		|| !game->img_p[6].img || !game->img_p[7].img
		|| !game->img_p[8].img
		|| !game->img_e[0].img || !game->img_e[1].img
		|| !game->img_e[2].img || !game->img_e[3].img
		|| !game->img_e[4].img || !game->img_e[5].img
		|| !game->img_e[6].img || !game->img_e[7].img)
		exit_error(game, "Couldn't load textures.");
}

static void	load_textures(t_game *g)
{
	g->img_walls.img = mlx_xpm_file_to_image(g->mlx, W1_XPM, &g->x, &g->y);
	g->img_walls2.img = mlx_xpm_file_to_image(g->mlx, W2_XPM, &g->x, &g->y);
	g->img_space.img = mlx_xpm_file_to_image(g->mlx, S_XPM, &g->x, &g->y);
	g->img_exit.img = mlx_xpm_file_to_image(g->mlx, E_XPM, &g->x, &g->y);
	g->img_collect[0].img = mlx_xpm_file_to_image(g->mlx, C1_XPM, &g->x, &g->y);
	g->img_collect[1].img = mlx_xpm_file_to_image(g->mlx, C2_XPM, &g->x, &g->y);
	g->img_collect[2].img = mlx_xpm_file_to_image(g->mlx, C3_XPM, &g->x, &g->y);
	g->img_collect[3].img = mlx_xpm_file_to_image(g->mlx, C4_XPM, &g->x, &g->y);
	g->img_p[0].img = mlx_xpm_file_to_image(g->mlx, P0_XPM, &g->x, &g->y);
	g->img_p[1].img = mlx_xpm_file_to_image(g->mlx, P1_XPM, &g->x, &g->y);
	g->img_p[2].img = mlx_xpm_file_to_image(g->mlx, P2_XPM, &g->x, &g->y);
	g->img_p[3].img = mlx_xpm_file_to_image(g->mlx, P3_XPM, &g->x, &g->y);
	g->img_p[4].img = mlx_xpm_file_to_image(g->mlx, P4_XPM, &g->x, &g->y);
	g->img_p[5].img = mlx_xpm_file_to_image(g->mlx, P5_XPM, &g->x, &g->y);
	g->img_p[6].img = mlx_xpm_file_to_image(g->mlx, P6_XPM, &g->x, &g->y);
	g->img_p[7].img = mlx_xpm_file_to_image(g->mlx, P7_XPM, &g->x, &g->y);
	g->img_p[8].img = mlx_xpm_file_to_image(g->mlx, P8_XPM, &g->x, &g->y);
	g->img_e[0].img = mlx_xpm_file_to_image(g->mlx, E0_XPM, &g->x, &g->y);
	g->img_e[1].img = mlx_xpm_file_to_image(g->mlx, E1_XPM, &g->x, &g->y);
	g->img_e[2].img = mlx_xpm_file_to_image(g->mlx, E2_XPM, &g->x, &g->y);
	g->img_e[3].img = mlx_xpm_file_to_image(g->mlx, E3_XPM, &g->x, &g->y);
	g->img_e[4].img = mlx_xpm_file_to_image(g->mlx, E4_XPM, &g->x, &g->y);
	g->img_e[5].img = mlx_xpm_file_to_image(g->mlx, E5_XPM, &g->x, &g->y);
	g->img_e[6].img = mlx_xpm_file_to_image(g->mlx, E6_XPM, &g->x, &g->y);
	g->img_e[7].img = mlx_xpm_file_to_image(g->mlx, E7_XPM, &g->x, &g->y);
}

static void	init_mlx_and_textures(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Couldn't initialize mlx.");
	load_textures(game);
	check_textures(game);
	game->win = mlx_new_window(game->mlx, game->map.cols * TILE_SIZE,
			game->map.rows * TILE_SIZE, "so_long");
	if (!game->win)
		exit_error(game, "Couldn't create window.");
}

void	init_game(t_game *game)
{
	init_enemy(game);
	count_collectibles(game);
	init_mlx_and_textures(game);
	render_map(game, -1, -1);
}
