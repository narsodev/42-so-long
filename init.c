/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:55:33 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/22 21:41:05 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdlib.h>

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
	game->mov_x = 0;
	game->mov_y = 0;
}

void	create_textures(t_game *game)
{
	game->wall = mlx_load_png(WALL_TEXTURE);
	game->floor = mlx_load_png(FLOOR_TEXTURE);
	game->exit = mlx_load_png(EXIT_TEXTURE);
	game->collectible = mlx_load_png(COIN_TEXTURE);
}

t_game	*create_game(char *mapfile)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	set_game_default_values(game);
	game->map = parse_map(mapfile);
	if (check_map(game->map))
		game->mlx = mlx_init(game->map->width * TEXTURE_SIZE,
				game->map->height * TEXTURE_SIZE, "MLX42", true);
	if (game->mlx)
	{
		game->img = mlx_new_image(game->mlx, game->map->width * TEXTURE_SIZE,
				game->map->height * TEXTURE_SIZE);
	}
	if (game->img)
	{
		create_textures(game);
		game->players = create_players(game);
	}
	if (!game->wall || !game->floor || !game->exit
		|| !game->collectible || !game->players)
		free_game(&game);
	return (game);
}
