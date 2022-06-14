/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:49:14 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/14 16:53:13 by ngonzale         ###   ########.fr       */
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

t_map	*parse_map(char *filename)
{
	t_map	*map;
	char	*map_raw;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map_raw = ft_read_file(filename);
	if (!map_raw)
	{
		free(map);
		return (NULL);
	}
	map->map = ft_split(map_raw, '\n');
	free(map_raw);
	if (!map->map)
		return (NULL);
	set_map_size(map);
	if (!map->width || !map->height)
	{
		free(map->map);
		free(map);
		return (NULL);
	}
	return (map);
}
