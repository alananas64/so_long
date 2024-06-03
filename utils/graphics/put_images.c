/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:36:57 by nosman            #+#    #+#             */
/*   Updated: 2024/05/31 12:59:58 by nosman           ###   ########.fr       */
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

void	place_images_in_game(t_map *game)
{
	int	i;
	int	j;

	game->background = mlx_xpm_file_to_image(game->mlx,
			"textures/background.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player2.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &i, &j);
	game->collectables = mlx_xpm_file_to_image(game->mlx,
			"textures/collectables.xpm", &i, &j);
	check_images(game);
}

void	add_img_to_win(t_map *game)
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
			width++;
		}
		heighti++;
	}
}

void	add_img_to_win2(t_map *game)
{
	int	heighti;
	int	width;

	heighti = 0;
	while (heighti < game->height)
	{
		width = 0;
		while (game->map[heighti][width] != '\0')
		{
			if (game->map[heighti][width] == 'P')
				place_player(game, heighti, width);
			if (game->map[heighti][width] == 'E')
				mlx_put_image_to_window(game->mlx,
					game->window, game->exit,
					width * PIXEL_SIZE, heighti * PIXEL_SIZE);
			if (game->map[heighti][width] == '0')
				mlx_put_image_to_window(game->mlx,
					game->window, game->background,
					width * PIXEL_SIZE, heighti * PIXEL_SIZE);
			width++;
		}
		heighti++;
	}
}
