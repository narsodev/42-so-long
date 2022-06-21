/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:16:56 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/22 00:36:11 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	end_game(t_game *game)
{
	free_game(&game);
	system("leaks -q a.out");
	exit(1);
}

void	keys_hook(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *) param;


	if (keydata.key == MLX_KEY_W && keydata.action)
		move_players_reverse(game, 0, -1);
	else if (keydata.key == MLX_KEY_A && keydata.action)
		move_players(game, -1, 0);
	else if (keydata.key == MLX_KEY_S && keydata.action)
		move_players(game, 0, 1);
	else if (keydata.key == MLX_KEY_D && keydata.action)
		move_players_reverse(game, 1, 0);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == 1)
	{
		end_game(game);
	}
}

void	close_hook(void *param)
{
	t_game	*game;

	game = param;
	end_game(game);
}
