/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:49:14 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/15 01:27:29 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

void	set_map_size(t_map *map)
{
	if (!map->map[0] || !map->map[0][0])
	{
		map->width = 0;
		map->height = 0;
		return ;
	}	
	map->width = ft_strlen(map->map[0]);
	map->height = 1;
	while (map->map[map->height])
		map->height += 1;
}

void	set_map_items(t_map *map)
{
	size_t	i;
	size_t	j;

	map->n_c = 0;
	map->n_p = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->n_c += 1;
			else if (map->map[i][j] == 'P')
				map->n_p += 1;
			j++;
		}
		i++;
	}
}

char	**get_map_matrix(char	*mapfile)
{
	char	*map_raw;
	char	**map;

	map_raw = ft_read_file(mapfile);
	if (!map_raw)
		return (NULL);
	map = ft_split(map_raw, '\n');
	free(map_raw);
	return (map);
}

t_map	*parse_map(char *mapfile)
{
	t_map	*map;
	char	*map_raw;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = get_map_matrix(mapfile);
	if (!map->map)
	{
		free(map);
		return (NULL);
	}
	set_map_size(map);
	if (!map->width || !map->height)
	{
		free_map(map);
		return (NULL);
	}
	set_map_items(map);
	if (!check_map(map))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
