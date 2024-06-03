/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:46:20 by nosman            #+#    #+#             */
/*   Updated: 2024/05/17 11:37:01 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * takes path to map as parameter
 * parse the map and run the program
 * SO_LONG.
 * make the run_so_long function
*/

char	**so_long(char *path_to_map)
{
	return (map_prep(path_to_map));
}

int	main(int ac, char *av[])
{
	char	**map;
	t_map	game;

	if (ac != 2)
		perr ("usage: ./so_long 'path/to/map.ber'.", 1);
	map = so_long(av[1]);
	game.map = map;
	game.width = get_map_width(game.map);
	game.x_axis = find_player_position_x(game.map);
	game.y_axis = find_player_position_y(game.map);
	game.moves_counter = 0;
	game.height = get_map_height(av[1]);
	game.collectables_num = check_characters(game.map, game.width);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, (game.width * PIXEL_SIZE),
			(game.height * PIXEL_SIZE), "so_long");
	place_images_in_game(&game);
	add_img_to_win(&game);
	add_img_to_win2(&game);
	mlx_key_hook(game.window, movement_keys, &game);
	mlx_hook(game.window, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx);
	exit (EXIT_SUCCESS);
}
