/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:22:14 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/22 18:25:43 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

t_player	*create_player(t_game *game, size_t x, size_t y);
t_player	**create_players_helper(t_game *game, size_t n, size_t y, size_t x);

t_player	**create_players(t_game *game)
{
	size_t		n;
	size_t		y;
	size_t		x;

	n = 0;
	y = 0;
	x = 0;
	return (create_players_helper(game, n, y, x));
}

t_player	**create_players_helper(t_game *game, size_t n, size_t y, size_t x)
{
	t_player	**players;

	players = ft_calloc(game->map->n_p + 1, sizeof(t_player *));
	if (!players)
		return (NULL);
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'P')
			{
				players[n] = create_player(game, x, y);
				if (!players[n])
				{
					free_players(game->mlx, players);
					return (NULL);
				}
				n++;
			}
			x++;
		}
		y++;
	}
	return (players);
}

t_player	*create_player(t_game *game, size_t x, size_t y)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->img = create_img_from_png(game, PLAYER_TEXTURE);
	if (!player->img)
	{
		free(player);
		return (NULL);
	}
	player->x = x;
	player->y = y;
	player->render = 1;
	return (player);
}
