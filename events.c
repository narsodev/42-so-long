/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:16:56 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/22 22:39:12 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	end_game(t_game *game)
{
	free_game(&game);
	system("leaks -q a.out");
	exit(EXIT_FAILURE);
}

void	keys_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (keydata.action)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			end_game(game);
		if (keydata.key == MLX_KEY_W)
			game->mov_y = UP;
		else if (keydata.key == MLX_KEY_A)
			game->mov_x = LEFT;
		else if (keydata.key == MLX_KEY_S)
			game->mov_y = DOWN;
		else if (keydata.key == MLX_KEY_D)
			game->mov_x = RIGHT;
		if (game->mov_x == UP || game->mov_y == LEFT)
			move_players(game);
		if (game->mov_x == RIGHT || game->mov_y == DOWN)
			move_players_reverse(game);
		game->mov_x = 0;
		game->mov_y = 0;
	}
}

void	close_hook(void *param)
{
	t_game	*game;

	game = param;
	end_game(game);
}
