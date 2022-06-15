/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:27:43 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/15 20:25:22 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_player	*find_player(t_player **players, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while (players[i])
	{
		if (players[i]->render && players[i]->x == x && players[i]->y == y)
			return (players[i]);
		i++;
	}
	return (0);
}

void	get_coin(t_game *game, int x, int y)
{
	game->n_c += 1;
	mlx_draw_texture(game->img, game->floor, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	/*
	t_player	*coin;


	coin = find_player(game->coins, player->x, player->y);
	if (coin)
	{
		game->n_c += 1;
		mlx_delete_image(game->mlx, coin->img);
		coin->render = 0;
	}
	*/
}

void	move_player(t_game *game, t_player *player, int x_dir, int y_dir)
{
	t_player	*coin;

	if (ft_strchr("0C", game->map->map[player->y + y_dir][player->x + x_dir]))
	{
		player->img->instances[0].x += TEXTURE_SIZE * x_dir;
		player->img->instances[0].y += TEXTURE_SIZE * y_dir;
		game->map->map[player->y][player->x] = '0';
		player->x += x_dir;
		player->y += y_dir;
		if (game->map->map[player->y][player->x] == 'C')
			get_coin(game, player->x, player->y);
		game->map->map[player->y][player->x] = 'P';
	}
	else if (game->map->map[player->y + y_dir][player->x + x_dir] == 'E' && game->n_c == game->map->n_c)
	{
		game->map->map[player->y][player->x] = '0';
		player->render = 0;
		mlx_delete_image(game->mlx, player->img);
	}
}

void	move_players(t_game *game, int x_dir, int y_dir)
{
	size_t	n;

	n = 0;
	while (game->players[n])
	{
		if (game->players[n]->render)
			move_player(game, game->players[n], x_dir, y_dir);
		n++;
	}
}

void	move_players_reverse(t_game *game, int x_dir, int y_dir)
{
	size_t	n;

	n = game->map->n_p - 1;
	while (n >= 0)
	{
		if (game->players[n]->render)
			move_player(game, game->players[n], x_dir, y_dir);
		if (n == 0)
			break;
		n--;
	}
}

