/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:52:20 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/23 00:14:24 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "MLX42.h"
#include <stdlib.h>

mlx_image_t	*create_img_from_png(t_game *game, char *pngfile)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(pngfile);
	if (!texture)
		return (NULL);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*extension;

	extension = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (argc != 2 || !extension || *(4 + extension))
		return (EXIT_FAILURE);
	game = create_game(argv[1]);
	if (!game)
		return (EXIT_FAILURE);
	render_game(game);
	mlx_key_hook(game->mlx, keys_hook, game);
	mlx_close_hook(game->mlx, close_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
