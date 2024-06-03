/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:41:26 by nosman            #+#    #+#             */
/*   Updated: 2024/05/17 13:27:06 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../so_long.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include <strings.h>
# include <string.h>

/* --- so_long functions --- */
char		**map_prep(char *map);
char		**reading(int fd, int map_height);

/* --- validate map functions --- */
void		check_map_validity(char **map, int height, int width);
int			check_walls(char **map, int height, int width);
int			check_rows_width(char **map, int width);
int			check_characters(char **map, int width);

/* --- valid path --- */
void		valid_path(char **map, int height);

/* --- map utils functions --- */
int			get_map_height(char *path_to_map);
int			get_map_width(char **map);
int			find_player_position_y(char **map);
int			find_player_position_x(char **map);

/* --- utils --- */
void		free_node(char **node, int node_size);
int			ft_stlen(const char *str);
int			char_numbers(char **map, int height, int width, char c);

#endif
