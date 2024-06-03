/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:15:45 by nosman            #+#    #+#             */
/*   Updated: 2024/05/17 13:25:49 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	destroy_image(t_map *game)
{
	if (game->background)
		mlx_destroy_image(game->mlx, game->background);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->collectables)
		mlx_destroy_image(game->mlx, game->collectables);
}

void	check_images(t_map *game)
{
	if ((!game->background) || (!game->wall)
		|| (!game->player) || (!game->exit) || (!game->collectables))
	{
		write (2, "ERROR IN PUTTING THE IMAGES\n", 28);
		destroy_image(game);
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
			free(game->mlx);
		ft_free_arr(game->map);
		exit(EXIT_FAILURE);
	}
}
