/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:27:43 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/22 23:51:39 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

void	check_win(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->players[i])
	{
		if (game->players[i]->render)
			return ;
		i++;
	}
	ft_printf("Map finished with %u movements.\n", game->movements);
	end_game(game);
}

void	move_players_helper(t_game *game, t_list **lst, int x, int y)
{
	t_player	*player;

	player = find_player(game->players, x, y);
	if (player && !ft_lstfind(*lst, player))
	{
		if (move_player(game, player))
			ft_lstadd_back(lst, ft_lstnew(player));
	}
}

void	ft_fake_dellst(void *foo)
{
	(void)foo;
}

void	move_players(t_game *game)
{
	size_t	y;
	size_t	x;
	t_list	*lst;

	y = 0;
	lst = NULL;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'P')
				move_players_helper(game, &lst, x, y);
			x++;
		}
		y++;
	}
	x = (size_t) lst;
	ft_lstclear(&lst, ft_fake_dellst);
	if (x)
	{
		game->movements += 1;
		ft_printf("Movements: %d\n", game->movements);
		check_win(game);
	}
}

void	move_players_reverse(t_game *game)
{
	size_t	y;
	size_t	x;
	t_list	*lst;

	y = game->map->height - 1;
	lst = NULL;
	while (y > 0)
	{
		x = game->map->width - 1;
		while (x > 0)
		{
			if (game->map->map[y][x] == 'P')
				move_players_helper(game, &lst, x, y);
			x--;
		}
		y--;
	}
	x = (size_t) lst;
	ft_lstclear(&lst, ft_fake_dellst);
	if (x)
	{
		game->movements += 1;
		ft_printf("Movements: %d\n", game->movements);
		check_win(game);
	}
}
