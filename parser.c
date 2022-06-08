/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:49:14 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/09 01:37:44 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

t_map	*create_map(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (map)
	{
		map->height = 0;
		map->width = 0;
		map->map = NULL;
		map->c_n = 0;
	}
	return (map);
}

void	ft_free_char_bimatrix(char **matrix, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**ft_create_char_bimatrix(size_t height, size_t width)
{
	char	**matrix;
	size_t	i;

	matrix = ft_calloc(height, sizeof(char *));
	if (matrix)
	{
		i = 0;
		while (i < height)
		{
			matrix[i] = ft_calloc(width, sizeof(char));
			if (!matrix[i])
			{
				ft_free_char_bimatrix(matrix, i);
				return (NULL);
			}
			i++;
		}
	}
	return (matrix);
}

int	check_chars(size_t i, char c)
{
	(void)i;
	return ((int) ft_strchr("01CEP", c));
}

t_map	*create_map(char *filename)
{
	int		fd;
	char	*str;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
	}

}

void	set_map_size(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	size_t	line_len;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	if (line)
		map->width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->height += 1;
	}
	close(fd);
}

void	set_map_content(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	size_t	height;
	size_t	width;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	height = 0;
	while (line)
	{
		map[height] = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
}

int	check_map(t_map *map)
{
	size_t	height;
	size_t	width;
	size_t	n_e;
	size_t	n_p;

	height = 0;
	n_e = 0;
	n_p = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			if (map->map[height][width] == 'C')
				map->c_n += 1;
			else if (map->map[height][width] == 'E')
				n_e++;
			else if (map->map[height][width] == 'P')
				n_p++;
			else if (!ft_strchr("01", map->map[height][width]))
				return (0);
			width++;
		}
		height++;
	}
	return (map->c_n > 0 && n_e > 0 && n_p > 0);
}

t_map	*parse_map(char	*filename)
{
	t_map	*map;

	map = create_map();
	if (!map)
		return (map);
	set_map_size(filename, map);
	if (!map->width || !map->height)
	{
		free(map);
		return (NULL);
	}
	map->map = ft_create_char_bimatrix(map->height, map->width);
	if (!map->map)
	{
		free(map);
		return (NULL);
	}
	set_map_content(filename, map);
	if (!check_map(map))
	{
		ft_free_char_bimatrix(map->map, map->height);
		free(map);
		return (NULL);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	t_map *map;
	size_t	i;
	size_t	j;

	map = parse_map(argv[1]);
	if (!map)
	{
		ft_putendl_fd("Error", 1);
		system("leaks -q a.out");
		return (1);
	}
	ft_printf("%d %d\n", map->width, map->height);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_putchar_fd(map->map[i][j], 1);
			j++;
		}
		ft_putendl_fd("", 1);
		i++;
	}
	ft_free_char_bimatrix(map->map, map->height);
	free(map);
	system("leaks -q a.out");
}
