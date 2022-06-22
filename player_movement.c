/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:41:14 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/22 22:42:33 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	move_player(t_game *game, t_player *player)
{
	if (ft_strchr("0C",
			game->map->map[player->y + game->mov_y][player->x + game->mov_x]))
	{
		player->img->instances[0].x += TEXTURE_SIZE * game->mov_x;
		player->img->instances[0].y += TEXTURE_SIZE * game->mov_y;
		game->map->map[player->y][player->x] = '0';
		player->x += game->mov_x;
		player->y += game->mov_y;
		if (game->map->map[player->y][player->x] == 'C')
			get_collectible(game, player->x, player->y);
		game->map->map[player->y][player->x] = 'P';
		return (1);
	}
	else if (game->map->map[player->y + game->mov_y][player->x + game->mov_x]
			== 'E' && game->n_c == game->map->n_c)
	{
		game->map->map[player->y][player->x] = '0';
		player->render = 0;
		mlx_delete_image(game->mlx, player->img);
		return (2);
	}
	return (0);
}
