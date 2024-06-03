/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:41:36 by nosman            #+#    #+#             */
/*   Updated: 2024/05/16 18:39:16 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**set_map_as_zero(char **map, char **zero_map, int height)
{
	int	m;
	int	i;

	m = 0;
	i = 0;
	while (m < height)
	{
		i = 0;
		while (map[m][i] != '\0')
		{
			zero_map[m][i] = '0';
			i++;
		}
		m++;
	}
	return (zero_map);
}

char	**check_valid_path(char **map, int height)
{
	char	**temp_map;
	int		m;

	m = 0;
	temp_map = malloc(sizeof(char *) * (height + 1));
	if (!temp_map)
		return (free(temp_map), NULL);
	while ((map[m] != NULL) && (m < height))
	{
		temp_map[m] = ft_strdup(map[m]);
		if (!temp_map[m])
			return (free_node(temp_map, height), NULL);
		m++;
	}
	temp_map = set_map_as_zero(map, temp_map, height);
	temp_map[m] = NULL;
	return (temp_map);
}

char	**set_valid_path_as_one(char **map, char **temp_map, int x, int y)
{
	int	i;
	int	new_r;
	int	new_c;
	int	*row_array;
	int	*column_array;

	i = 0;
	temp_map[x][y] = '1';
	if (map[x][y] == 'E')
		return (NULL);
	row_array = (int []){-1, 0, 1, 0};
	column_array = (int []){0, 1, 0, -1};
	while (i < 4)
	{
		new_r = x + row_array[i];
		new_c = y + column_array[i];
		if ((new_r >= 0) && (new_r < get_map_width(map))
			&& (new_c >= 0) && (new_c < ft_stlen(map[0]))
			&& (map[new_r][new_c] != '\0')
			&& (map[new_r][new_c] != '1')
			&& temp_map[new_r][new_c] == '0')
			set_valid_path_as_one(map, temp_map, new_r, new_c);
		i++;
	}
	return (temp_map);
}

void	compare_map(char **map, char **temp_map, int map_height)
{
	int	m;
	int	offset;

	m = 0;
	while (m < map_height)
	{
		offset = 0;
		while (map[m][offset] != '\0')
		{
			if (((map[m][offset] == 'C') || (map[m][offset] == 'E'))
				&& (temp_map[m][offset] == '0'))
			{
				free (temp_map);
				free (map);
				perr ("you do not have a valid path", 404);
			}
			offset++;
		}
		m++;
	}
	free_node(temp_map, map_height);
}

void	valid_path(char **map, int height)
{
	char	**zero_map;
	char	**temp_map;
	int		player_pos_x;
	int		player_pos_y;

	player_pos_x = find_player_position_x(map);
	player_pos_y = find_player_position_y(map);
	zero_map = check_valid_path(map, height);
	temp_map = set_valid_path_as_one(map, zero_map, player_pos_x, player_pos_y);
	compare_map(map, temp_map, height);
}
