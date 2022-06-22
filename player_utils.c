/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:28:25 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/22 22:43:06 by ngonzale         ###   ########.fr       */
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

void	get_collectible(t_game *game, int x, int y)
{
	game->n_c += 1;
	mlx_draw_texture(game->img, game->floor,
		x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}
