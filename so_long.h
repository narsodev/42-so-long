/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:46:42 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/09 00:37:08 by ngonzale         ###   ########.fr       */
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

#endif
