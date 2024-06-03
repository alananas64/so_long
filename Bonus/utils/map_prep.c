/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:40:25 by nosman            #+#    #+#             */
/*   Updated: 2024/05/16 18:43:53 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	map_signature_check(char *path_to_map)
{
	unsigned long	i;

	i = 0;
	while (path_to_map[i] != '\0')
		i++;
	if ((path_to_map[i - 4] != '.') || (path_to_map[i - 3] != 'b')
		|| (path_to_map[i - 2] != 'e') || (path_to_map[i - 1] != 'r'))
		perr ("so_long: unknown suffix -- ignored", 2);
}

char	**reading(int fd, int map_height)
{
	int		l;
	char	**map;

	l = 0;
	map = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (!map)
		return (free_node(map, map_height), NULL);
	while (l <= map_height)
	{
		map[l] = get_next_line(fd);
		if (map[0] == NULL)
		{
			free_node(map, map_height);
			perr("YOUR MAP IS EMPTY", 555);
		}
		l++;
	}
	map[map_height] = NULL;
	return (map);
}

char	**read_map(char *path_to_map)
{
	int		fd;
	char	**map;
	int		map_height;

	map_signature_check(path_to_map);
	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		perr ("could not open your map file", 3);
	map_height = get_map_height(path_to_map);
	close(fd);
	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		perr ("could not open your map file", 4);
	map = reading(fd, map_height);
	close(fd);
	return (map);
}

/**
 * find_valid_path(path_to_map);
 * print_map(map); // printng temp map for debuging
*/
char	**map_prep(char *path_to_map)
{
	char		**map;
	size_t		map_height;
	size_t		map_width;

	map = read_map(path_to_map);
	map_height = get_map_height(path_to_map);
	map_width = get_map_width(map);
	check_map_validity(map, map_height, map_width);
	return (map);
}
