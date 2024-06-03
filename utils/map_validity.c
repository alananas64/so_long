/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:41:08 by nosman            #+#    #+#             */
/*   Updated: 2024/05/17 17:21:15 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_walls(char **map, int height, int width)
{
	int	m;
	int	offset;

	m = 0;
	offset = 0;
	while (map[m] != NULL)
	{
		if ((map[m][0] != '1') || (map[m][width - 1] != '1'))
			perr("you have error in the walls", 5);
		while (offset < width)
		{
			if ((map[0][offset] != '1') || (map[height - 1][offset] != '1'))
				perr("you have error in the walls", 5);
			offset++;
		}
		m++;
	}
	return (0);
}

int	check_rows_width(char **map, int width)
{
	int	i;
	int	m;
	int	l;

	m = 1;
	while (map[m] != NULL)
	{
		i = 0;
		while (map[m][i] != '\n')
			i++;
		l = i;
		if (l == width)
			m++;
		else
			perr ("your map's width are not equal", 9);
	}
	return (0);
}

int	check_characters(char **map, int width)
{
	int	m;
	int	i;
	int	collectable_num;

	m = 1;
	collectable_num = 0;
	while (map[m] != NULL)
	{
		i = 1;
		while (i < width)
		{
			if ((map[m][i] != '1') && (map[m][i] != '0')
				&& (map[m][i] != 'P') && (map[m][i] != 'C')
				&& (map[m][i] != 'E'))
				perr ("you have error in the characters", 10);
			if (map[m][i] == 'C')
				collectable_num++;
			i++;
		}
		m++;
	}
	return (collectable_num);
}

void	check_validity(char **string, int map_height, int width)
{
	int	player_count;
	int	exit_count;
	int	collecable_count;

	player_count = char_numbers(string, map_height, width, 'P');
	exit_count = char_numbers(string, map_height, width, 'E');
	collecable_count = char_numbers(string, map_height, width, 'C');
	if (player_count != 1)
		perr("so_long needs excatly ONE player", 74);
	if (exit_count != 1)
		perr ("so_long needs excatly ONE exit", 34);
	if (collecable_count < 1)
		perr ("You do not have enough collecables", 42);
}

void	check_map_validity(char **map, int height, int width)
{
	check_walls(map, height, width);
	check_rows_width(map, width);
	check_characters(map, width);
	check_validity(map, height, width);
	valid_path(map, height);
}
