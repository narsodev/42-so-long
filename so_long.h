/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:46:42 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/14 16:56:50 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>

typedef struct s_map {
	size_t		width;
	size_t		height;
	char		**map;
	size_t		c_n;
}				t_map;

// Parser
t_map	*parse_map(char *filename);

// Checker
int		check_map(t_map *map);
int		check_map_size(t_map *map);
int		check_map_content(t_map *map);

// Checker utils
int		char_is_wall(size_t i, char c);
int		char_is_position(size_t i, char c);
int		char_is_exit(size_t i, char c);
int		char_is_collectible(size_t i, char c);
int		char_is_valid(size_t i, char c);

#endif
