/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:14:50 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/22 18:52:10 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	check_map_size(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[i])
	{
		if (map->width != ft_strlen(map->map[i]))
			return (0);
		i++;
	}
	return (i == map->height);
}

int	check_map_content(t_map *map)
{
	size_t	n_e;
	size_t	i;

	if (!ft_strevery(map->map[0], char_is_wall)
		|| !ft_strevery(map->map[map->height - 1], char_is_wall)
		|| !map->n_c || !map->n_p)
		return (0);
	n_e = 0;
	i = 0;
	while (i < map->height)
	{
		n_e += ft_strsome(map->map[i], char_is_exit);
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1'
				|| !ft_strevery(map->map[i], char_is_valid))
			return (0);
		i++;
	}
	return (n_e);
}

int	check_map(t_map *map)
{
	if (map && check_map_size(map) && check_map_content(map))
		return (1);
	ft_printf("Error\n");
	return (0);
}
