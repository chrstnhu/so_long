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

//Initialise game with loop
static void	init_game_loop(t_game *game, int window_width, int window_height)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, window_width,
			window_height, "so_long");
	if (!game->win_ptr)
	{
		ft_printf("%sError\nFail open window%s\n", RED, DEFAULT);
		exit(1);
	}
	mlx_hook(game->win_ptr, 17, 0, free_exit_prog_close, game);
	mlx_hook(game->win_ptr, 2, KeyPressMask, player_move, game);
	mlx_loop_hook(game->mlx_ptr, &draw_map, game);
	mlx_loop(game->mlx_ptr);
}

//Initialise game window
void	init_game(t_game *game)
{
	int	window_width;
	int	window_height;

	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("%sError\nFailed to initialize mlx%s", RED, DEFAULT);
		exit(0);
	}
	set_img(game);
	game->img_obj.player = game->img_obj.player_down;
	game->img_obj.exit = game->img_obj.exit_close;
	window_width = game->map.tab_col * IMG_SIZE - IMG_SIZE;
	window_height = game->map.tab_row * IMG_SIZE;
	if (window_width > MAX_WINDOW_WIDTH)
	{
		window_width = MAX_WINDOW_WIDTH;
	}
	if (window_height > MAX_WINDOW_HEIGHT)
	{
		window_height = MAX_WINDOW_HEIGHT;
	}
	game->win_width = window_width;
	game->win_height = window_height;
	init_game_loop(game, window_width, window_height);
}
