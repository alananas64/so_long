/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:36:57 by nosman            #+#    #+#             */
/*   Updated: 2024/06/03 09:53:03 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	place_player(t_map *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->window, game->player, width * PIXEL_SIZE, height * PIXEL_SIZE);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_images_in_game_bonus(t_map *game)
{
	int	i;
	int	j;

	game->background = mlx_xpm_file_to_image(game->mlx,
			"Bonus/textures/background.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"Bonus/textures/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"Bonus/textures/player2.xpm", &i, &j);
	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"Bonus/textures/enemy.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"Bonus/textures/box1.xpm", &i, &j);
	game->collectables = mlx_xpm_file_to_image(game->mlx,
			"Bonus/textures/collectables.xpm", &i, &j);
	check_images_bonus(game);
}

void	add_img_to_win_bonus(t_map *game)
{
	int	heighti;
	int	width;

	heighti = 0;
	while (heighti < game->height)
	{
		width = 0;
		while (game->map[heighti][width] != '\0')
		{
			if (game->map[heighti][width] == '1')
				mlx_put_image_to_window(game->mlx,
					game->window, game->wall,
					width * PIXEL_SIZE, heighti * PIXEL_SIZE);
			if (game->map[heighti][width] == 'C')
				mlx_put_image_to_window(game->mlx,
					game->window, game->collectables,
					width * PIXEL_SIZE, heighti * PIXEL_SIZE);
			if (game->map[heighti][width] == 'P')
				place_player(game, heighti, width);
			width++;
		}
		heighti++;
	}
}

void	add_img_to_win_bonus2(t_map *game)
{
	int	heighti;
	int	width;

	heighti = 0;
	while (heighti < game->height)
	{
		width = 0;
		while (game->map[heighti][width] != '\0')
		{
			if (game->map[heighti][width] == 'E')
				mlx_put_image_to_window(game->mlx,
					game->window, game->exit,
					width * PIXEL_SIZE, heighti * PIXEL_SIZE);
			if (game->map[heighti][width] == '0')
				mlx_put_image_to_window(game->mlx,
					game->window, game->background,
					width * PIXEL_SIZE, heighti * PIXEL_SIZE);
			if (game->map[heighti][width] == 'X')
				mlx_put_image_to_window(game->mlx,
					game->window, game->enemy,
					width * PIXEL_SIZE, heighti * PIXEL_SIZE);
			width++;
		}
		heighti++;
	}
}

void	open_the_door(t_map *game, int width, int heighti)
{
	int	i;
	int	j;

	game->exit = mlx_xpm_file_to_image(game->mlx,
			"Bonus/textures/box2.xpm", &i, &j);
	check_images_bonus(game);
	mlx_put_image_to_window(game->mlx,
		game->window, game->exit,
		width * PIXEL_SIZE, heighti * PIXEL_SIZE);
}
