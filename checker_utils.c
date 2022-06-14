/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:11:56 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/14 16:43:42 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_is_wall(size_t i, char c)
{
	return (c == '1');
}

int	char_is_position(size_t i, char c)
{
	return (c == 'P');
}

int	char_is_exit(size_t i, char c)
{
	return (c == 'E');
}

int	char_is_collectible(size_t i, char c)
{
	return (c == 'C');
}

int	char_is_valid(size_t i, char c)
{
	return (ft_strchr("01CEP", c) != NULL);
}
