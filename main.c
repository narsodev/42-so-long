/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:52:20 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/15 20:31:26 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "MLX42.h"
#include <stdlib.h>


void	move_player_hook(mlx_key_data_t press_data, void *param)
{
	t_game *game;

	game = (t_game *) param;

	if (press_data.key == 'W' && press_data.action)
		move_players(game, 0, -1);
	else if (press_data.key == 'A' && press_data.action)
		move_players(game, -1, 0);
	else if (press_data.key == 'S' && press_data.action)
		move_players_reverse(game, 0, 1);
	else if (press_data.key == 'D' && press_data.action)
		move_players_reverse(game, 1, 0);
}

mlx_image_t	*create_img_from_png(t_game *game, char *pngfile)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	
	texture = mlx_load_png(pngfile);
	img = mlx_texture_to_image(game->mlx, texture);

	return (img);
}


int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (EXIT_FAILURE);
	game = create_game(argv[1]);
	if(!game)
		return (EXIT_FAILURE);
	render_background(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	render_players(game);

	mlx_key_hook(game->mlx, move_player_hook, game);

	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);


	return (EXIT_SUCCESS);

}

