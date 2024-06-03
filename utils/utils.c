/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:41:14 by nosman            #+#    #+#             */
/*   Updated: 2024/05/17 10:44:05 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_node(char **node, int node_size)
{
	int	i;

	i = 0;
	while (i <= node_size)
		free (node[i++]);
	free(node);
}

int	ft_stlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	get_map_width(char **map)
{
	int		i;

	i = 0;
	while (map[0][i] != '\0')
		i++;
	if (map[0][i - 1] == '\n')
		i--;
	if (i > 42)
		perr ("you entered a map with a size bigger than your PC window", 248);
	return (i);
}

int	get_map_height(char *path_to_map)
{
	int		map_height;
	char	*map;
	int		fd;

	map_height = 0;
	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		perr ("open", 13);
	map = get_next_line(fd);
	while (map != NULL)
	{
		free(map);
		map = get_next_line(fd);
		map_height++;
	}
	if (map_height > 23)
		perr ("you entered a map with a size bigger than your PC window", 90);
	free(map);
	return (map_height);
}
