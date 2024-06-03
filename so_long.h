/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:42:34 by nosman            #+#    #+#             */
/*   Updated: 2024/05/17 13:27:22 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "utils/utils.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef PIXEL_SIZE
#  define PIXEL_SIZE 60
# endif

typedef struct s_map
{
	char	**map;
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	int		x_axis;
	int		y_axis;
	int		moves_counter;
	int		collectables_num;
	void	*background;
	void	*wall;
	void	*player;
	void	*collectables;
	void	*exit;
}	t_map;

void	place_images_in_game(t_map *game);
void	add_img_to_win(t_map *game);
void	add_img_to_win2(t_map *game);
int		movement_keys(int command, t_map *game);
int		escape_game(t_map *game);
void	check_images(t_map *game);
void	destroy_image(t_map *game);
void	ft_free_arr(char **arr);

#endif
