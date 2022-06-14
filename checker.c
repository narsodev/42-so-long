/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:14:50 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/14 16:57:28 by ngonzale         ###   ########.fr       */
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
	size_t	n_c;
	size_t	n_p;
	size_t	i;

	if (!ft_strevery(map->map[0], char_is_wall)
		|| !ft_strevery(map->map[map->height - 1], char_is_wall))
		return (0);
	n_e = 0;
	n_c = 0;
	n_p = 0;
	i = 0;
	while (i < map->height)
	{
		n_e += ft_strsome(map->map[i], char_is_exit);
		n_c += ft_strsome(map->map[i], char_is_collectible);
		n_p += ft_strsome(map->map[i], char_is_position);
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1'
				|| !ft_strevery(map->map[i], char_is_valid))
			return (0);
		i++;
	}
	return (n_e && n_c && n_p);
}

int	check_map(t_map *map)
{
	return (check_map_size(map) && check_map_content(map));
}
