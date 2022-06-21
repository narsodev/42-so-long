/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:23:42 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/22 00:38:21 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "libft.h"

void	free_textures(t_game *game);
void	free_mlx(t_game *game);

void	free_game(t_game **game_p)
{
	t_game	*game;

	game = *game_p;
	if (game)
	{
		free_map(game->map);
		free_textures(game);
		free_players(game->mlx, game->players);
		free_mlx(game);
		free(game);
	}
	*game_p = NULL;
}

void	free_textures(t_game *game)
{
	if (game->wall)
		mlx_delete_texture(game->wall);
	if (game->floor)
		mlx_delete_texture(game->floor);
	if (game->collectible)
		mlx_delete_texture(game->collectible);
	if (game->exit)
		mlx_delete_texture(game->exit);
}

void	free_mlx(t_game *game)
{
	if (game->mlx && game->img)
		mlx_delete_image(game->mlx, game->img);
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	free_players(mlx_t *mlx, t_player **players)
{
	size_t	i;

	if (!players)
		return ;
	i = 0;
	while (players[i])
	{
		if (players[i]->render)
			mlx_delete_image(mlx, players[i]->img);
		free(players[i]);
		i++;
	}
	free(players);
}

void	free_map(t_map *map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}
