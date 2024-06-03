/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:40:34 by nosman            #+#    #+#             */
/*   Updated: 2024/05/17 13:26:54 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	char_numbers(char **map, int height, int width, char c)
{
	int		m;
	int		i;
	int		char_num;

	m = 0;
	char_num = 0;
	while (m < height - 1)
	{
		i = 0;
		while (i < width)
		{
			if (map[m][i] == c)
			{
				char_num++;
			}
			i++;
		}
		m++;
	}
	return (char_num);
}

int	find_player_position_x(char **map)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (map[pos] != NULL)
	{
		i = 0;
		while (map[pos][i] != '\0')
		{
			if (map[pos][i] == 'P')
				return (pos);
			i++;
		}
		pos++;
	}
	exit (1);
}

int	find_player_position_y(char **map)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (map[m] != NULL)
	{
		i = 0;
		while (map[m][i] != '\0')
		{
			if (map[m][i] == 'P')
				return (i);
			i++;
		}
		m++;
	}
	return (-1);
}
