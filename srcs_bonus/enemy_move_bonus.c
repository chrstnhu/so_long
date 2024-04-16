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

void	anim_enemy(t_game *game)
{
	if (game->data.anim_enemy >= 121)
		game->data.anim_enemy = 0;
	mlx_destroy_image(game->mlx_ptr, game->img_obj.enemy);
	if (game->data.anim_enemy <= 40)
		check_img(game, &game->img_obj.enemy, ENEMY01_PATH);
	else if (game->data.anim_enemy <= 80)
		check_img(game, &game->img_obj.enemy, ENEMY02_PATH);
	else if (game->data.anim_enemy <= 120)
		check_img(game, &game->img_obj.enemy, ENEMY03_PATH);
	game->data.anim_enemy++;
	draw_map(game);
}

void	locate_enemy(t_game *game)
{
	int	col;
	int	row;

	game->pos.enemy_col = -1;
	game->pos.enemy_row = -1;
	row = 0;
	while (game->map.tab[row])
	{
		col = 0;
		while (game->map.tab[row][col] != '\0')
		{
			if (game->map.tab[row][col] == ENEMY)
			{
				game->pos.enemy_col = col;
				game->pos.enemy_row = row;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	enemy_events(t_game *game)
{
	int	enemy_row;
	int	enemy_col;
	int	new_col;
	int	round;

	round = 200;
	locate_enemy(game);
	enemy_row = game->pos.enemy_row;
	enemy_col = game->pos.enemy_col;
	new_col = enemy_col + game->pos.enemy_direction;
	if ((game->data.round++) % round == 0)
	{
		if (new_col >= 0 && new_col < game->map.tab_col
			&& game->map.tab[enemy_row][new_col] != WALL
			&& game->map.tab[enemy_row][new_col] != COLLECTIBLE)
		{
			game->map.tab[enemy_row][enemy_col] = EMPTY;
			game->map.tab[enemy_row][new_col] = ENEMY;
			game->pos.enemy_col = new_col;
		}
		else
			game->pos.enemy_direction *= -1;
	}
	if (game->map.tab[enemy_row][new_col] == PLAYER)
		free_exit_prog_close(game);
}
