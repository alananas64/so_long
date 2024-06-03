/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:52:28 by nosman            #+#    #+#             */
/*   Updated: 2024/06/03 09:53:32 by nosman           ###   ########.fr       */
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
	void	*enemy;
}	t_map;

void	place_images_in_game_bonus(t_map *game);
void	add_img_to_win_bonus(t_map *game);
void	add_img_to_win_bonus2(t_map *game);
int		movement_keys(int command, t_map *game);
void	show_movments(t_map *game);
char	*ft_itoa(int n);
int		escape_game(t_map *game);
void	open_the_door(t_map *game, int width, int heighti);
void	check_images_bonus(t_map *game);
void	destroy_image(t_map *game);
void	ft_free_arr(char **arr);

#endif
