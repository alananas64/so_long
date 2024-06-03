/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:02:00 by nosman            #+#    #+#             */
/*   Updated: 2024/05/17 13:25:57 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	escape_game(t_map *game)
{
	int	line;

	line = 0;
	destroy_image(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	while (line < game->height)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

static int	right_move(t_map *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables_num != 0)
			return (0);
		ft_printf("\nNUM NUM NUM, YOU ATE ALL THE TUNAS!\n");
		escape_game(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->moves_counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables_num--;
		game->moves_counter++;
	}
	return (1);
}

static int	move_up_down(t_map *game, int key_number)
{
	int	i;
	int	j;
	int	check;

	i = game->x_axis;
	j = game->y_axis;
	if ((key_number == 13) || (key_number == 126))
	{
		if (game->map[--j][i] == '1')
			return (0);
		check = right_move(game, i, j);
		if (!check)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if ((key_number == 1) || (key_number == 125))
	{
		if (game->map[++j][i] == '1')
			return (0);
		check = right_move(game, i, j);
		if (!check)
			return (0);
		game->map[j - 1][i] = '0';
	}
	return (1);
}

static int	right_left_lelo(t_map *game, int key_number)
{
	int	i;
	int	j;
	int	check;

	i = game->x_axis;
	j = game->y_axis;
	if ((key_number == 0) || (key_number == 123))
	{
		if (game->map[j][--i] == '1')
			return (0);
		check = right_move(game, i, j);
		if (!check)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if ((key_number == 2) || (key_number == 124))
	{
		if (game->map[j][++i] == '1')
			return (0);
		check = right_move(game, i, j);
		if (!check)
			return (0);
		game->map[j][i - 1] = '0';
	}
	return (1);
}

int	movement_keys(int key_number, t_map *game)
{
	int	works;

	if ((key_number != 53) && (key_number != 13) && (key_number != 126)
		&& (key_number != 1) && (key_number != 125) && (key_number != 0)
		&& (key_number != 123) && (key_number != 2) && (key_number != 124)
		&& (key_number != 12))
		ft_printf("WARNING: USE 'W,A,S,D' TO MOVE THE PLAYER\n");
	else
	{
		if ((key_number == 53) || (key_number == 12))
			escape_game(game);
		if ((key_number == 13) || (key_number == 126))
			works = move_up_down(game, key_number);
		if ((key_number == 1) || (key_number == 125))
			works = move_up_down(game, key_number);
		if ((key_number == 0) || (key_number == 123))
			works = right_left_lelo(game, key_number);
		if ((key_number == 2) || (key_number == 124))
			works = right_left_lelo(game, key_number);
		add_img_to_win(game);
		add_img_to_win2(game);
		ft_printf("you moved [%i] times \n", game->moves_counter);
		ft_printf("you have [%i] tunas left \n\n", game->collectables_num);
	}
	return (1);
}
