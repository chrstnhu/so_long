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

#include "../includes/so_long.h"

// PLAYER move to the right and left
static void	player_right_left(int keysym, t_game *game)
{
	if (keysym == 97 || keysym == XK_Left)
	{
		game->img_obj.player = game->img_obj.player_left;
		key_move(game, -1, 0);
	}
	if (keysym == 100 || keysym == XK_Right)
	{
		game->img_obj.player = game->img_obj.player_right;
		key_move(game, +1, 0);
	}
}

// PLAYER move to the up and down
int	player_move(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		ft_printf("You pressed ESC !\n\n", keysym);
		free_exit_prog_close(game);
	}
	if (keysym == 119 || keysym == XK_Up)
	{
		game->img_obj.player = game->img_obj.player_up;
		key_move(game, 0, -1);
	}
	if (keysym == 115 || keysym == XK_Down)
	{
		game->img_obj.player = game->img_obj.player_down;
		key_move(game, 0, +1);
	}
	player_right_left(keysym, game);
	return (0);
}
