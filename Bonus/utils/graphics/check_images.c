/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:15:45 by nosman            #+#    #+#             */
/*   Updated: 2024/06/03 09:52:34 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	nblen(long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*result;
	long int	nb;

	nb = (long int )n;
	len = nblen(nb);
	result = (char *)malloc(len * sizeof(char) + 1);
	if (!(result))
		return (NULL);
	result[len] = '\0';
	len--;
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		result[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (result);
}

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
	if (game->enemy)
		mlx_destroy_image(game->mlx, game->enemy);
}

void	check_images_bonus(t_map *game)
{
	if ((!game->background) || (!game->wall)
		|| (!game->player) || (!game->exit) || (!game->collectables)
		|| (!game->enemy))
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
