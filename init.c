/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:55:33 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/15 20:31:48 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdlib.h>

t_player	*create_player(t_game *game, size_t x, size_t y)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	player->img = create_img_from_png(game, PLAYER_TEXTURE);
	player->x = x;
	player->y = y;
	player->render = 1;
	return (player);
}

t_player	**create_players(t_game *game)
{
	t_player	**players;
	size_t		n;
	size_t		y;
	size_t		x;

	players = ft_calloc(game->n_p + 1, sizeof(t_player *));
	n = 0;
	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'P')
			{
				players[n] = create_player(game, x, y);
				n++;
			}
			x++;
		}
		y++;
	}
	return (players);
}

t_game	*create_game(char *mapfile)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = parse_map(mapfile);
	if (!game->map)
	{
		ft_putendl_fd("Error", 1);
		free(game);
		return (NULL);
	}
	game->mlx = mlx_init(game->map->width * TEXTURE_SIZE, game->map->height * TEXTURE_SIZE, "MLX42", true);
	game->img = mlx_new_image(game->mlx, game->map->width * TEXTURE_SIZE, game->map->height * TEXTURE_SIZE);
	game->wall = mlx_load_png(WALL_TEXTURE);
	game->floor = mlx_load_png(FLOOR_TEXTURE);
	game->exit = mlx_load_png(EXIT_TEXTURE);
	game->collectible = mlx_load_png(COIN_TEXTURE);
	game->movements = 0;
	game->n_c = 0;
	game->n_p = game->map->n_p;
	game->players = create_players(game);
	//game->coins = create_coins(game);
	return (game);
}

