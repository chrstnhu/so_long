/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:26:46 by chrhu             #+#    #+#             */
/*   Updated: 2024/02/09 14:26:48 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	finish_valid(t_game *game, int current_pos)
{
	if (current_pos == EXIT && game->data.collect == 0)
	{
		ft_printf("%sGreat job, you finished it !%s\n", GREEN, DEFAULT);
		free_exit_prog_close(game);
	}
}

void	locate_player(t_game *game)
{
	int	col;
	int	row;

	row = 0;
	if (game->data.collect == 0)
		game->img_obj.exit = game->img_obj.exit_open;
	while (game->map.tab[row])
	{
		col = 0;
		while (game->map.tab[row][col] != '\0')
		{
			if (game->map.tab[row][col] == PLAYER)
			{
				game->pos.player_col = col;
				game->pos.player_row = row;
				return ;
			}
			col++;
		}
		row++;
	}
}

int	key_move(t_game *game, int col, int row)
{
	int	maj_row;
	int	maj_col;
	int	current_pos;

	locate_player(game);
	maj_row = game->pos.player_row + row;
	maj_col = game->pos.player_col + col;
	current_pos = game->map.tab[maj_row][maj_col];
	if (current_pos == EMPTY || current_pos == COLLECTIBLE
		|| current_pos == ENEMY)
	{
		game->map.tab[maj_row][maj_col] = PLAYER;
		game->map.tab[game->pos.player_row][game->pos.player_col] = EMPTY;
		game->pos.player_row = maj_row;
		game->pos.player_col = maj_col;
		if (current_pos == COLLECTIBLE)
			game->data.collect--;
		if (current_pos == ENEMY)
			free_exit_prog_close(game);
		game->data.move++;
	}
	finish_valid(game, current_pos);
	return (0);
}
