/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 02:29:31 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/15 20:25:56 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	render_background(t_game *game)
{
	size_t	y;
	size_t	x;

	if (game->n_p == 0)
	{
		ft_printf("Has ganado!");
	}

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '1')
    			mlx_draw_texture(game->img, game->wall, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			else if (game->map->map[y][x] == 'E')
    			mlx_draw_texture(game->img, game->exit, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			else if (game->map->map[y][x] == 'C')
    			mlx_draw_texture(game->img, game->collectible, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			else
    			mlx_draw_texture(game->img, game->floor, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
			x++;
		}
		y++;
	}
}

void	render_players(t_game *game)
{
	size_t	n;
	n = 0;
	while (n < game->n_p)
	{
		mlx_image_to_window(game->mlx, game->players[n]->img, game->players[n]->x * TEXTURE_SIZE, game->players[n]->y * TEXTURE_SIZE);
		n++;
	}
}

void	render_coins(t_game *game)
{
	size_t	n;
	n = 0;
	while (n < game->map->n_c)
	{
		mlx_image_to_window(game->mlx, game->coins[n]->img, game->coins[n]->x * TEXTURE_SIZE, game->coins[n]->y * TEXTURE_SIZE);
		n++;
	}
}
