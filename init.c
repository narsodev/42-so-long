/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:55:33 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/22 00:35:31 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdlib.h>

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

void	set_game_default_values(t_game *game)
{
	game->mlx = NULL;
	game->img = NULL;
	game->map = NULL;
	game->wall = NULL;
	game->floor = NULL;
	game->collectible = NULL;
	game->exit = NULL;
	game->players = NULL;
	game->movements = 0;
	game->n_c = 0;
}

t_game	*create_game(char *mapfile)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	set_game_default_values(game);
	game->map = parse_map(mapfile);
	if (!game->map)
		ft_putendl_fd("Error", 1);
	if (game->map)
		game->mlx = mlx_init(game->map->width * TEXTURE_SIZE, game->map->height * TEXTURE_SIZE, "MLX42", true);
	if (game->mlx)
	{
		game->img = mlx_new_image(game->mlx, game->map->width * TEXTURE_SIZE, game->map->height * TEXTURE_SIZE);
	}
	if (game->img)
	{
		game->wall = mlx_load_png(WALL_TEXTURE);
		game->floor = mlx_load_png(FLOOR_TEXTURE);
		game->exit = mlx_load_png(EXIT_TEXTURE);
		game->collectible = mlx_load_png(COIN_TEXTURE);
		game->players = create_players(game);
	}
	if (!game->wall || !game->floor || !game->exit || !game->collectible || !game->players)
		free_game(&game);
	return (game);
}

