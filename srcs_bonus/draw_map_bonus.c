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

static void	init_scroll_offsets(t_game *game, t_scroll *offsets)
{
	int	window_width;
	int	window_height;

	offsets->scroll_x = (game->pos.player_col * IMG_SIZE)
		- (game->win_width / 2);
	offsets->scroll_y = (game->pos.player_row * IMG_SIZE)
		- (game->win_height / 2);
	window_width = game->map.tab_col * IMG_SIZE;
	window_height = game->map.tab_row * IMG_SIZE;
	if (game->win_width < MAX_WINDOW_WIDTH || offsets->scroll_x < 0)
		offsets->scroll_x = 0;
	else if (offsets->scroll_x > window_width - game->win_width)
		offsets->scroll_x = window_width - game->win_width;
	if (game->win_height < MAX_WINDOW_HEIGHT || offsets->scroll_y < 0)
		offsets->scroll_y = 0;
	else if (offsets->scroll_y > window_height - game->win_height)
		offsets->scroll_y = window_height - game->win_height;
}

static void	draw_collect(t_game *game, int row, int col, t_scroll *offsets)
{
	int	x;
	int	y;

	x = col * IMG_SIZE - offsets->scroll_x;
	y = row * IMG_SIZE - offsets->scroll_y;
	if (x >= 0 && x < game->win_width && y >= 0 && y < game->win_height)
	{
		if (game->map.tab[row][col] == PLAYER)
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, game->img_obj.player, x, y);
		else if (game->map.tab[row][col] == COLLECTIBLE)
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, game->img_obj.collect, x, y);
		else if (game->map.tab[row][col] == ENEMY)
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, game->img_obj.enemy, x, y);
	}
}

static void	draw_texture(t_game *game, int row, int col, t_scroll *offsets)
{
	int	x;
	int	y;

	x = col * IMG_SIZE - offsets->scroll_x;
	y = row * IMG_SIZE - offsets->scroll_y;
	if (x >= 0 && x < game->win_width && y >= 0 && y < game->win_height)
	{
		if (game->map.tab[row][col] == EMPTY)
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, game->img_obj.floor, x, y);
		else if (game->map.tab[row][col] == WALL)
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, game->img_obj.wall, x, y);
		else if (game->map.tab[row][col] == EXIT && game->img_obj.collect != 0)
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, game->img_obj.exit, x, y);
	}
}

int	draw_move(t_game *game)
{
	int		black;
	int		white;
	char	*move_str;
	char	*collect;

	white = 0xffffff;
	black = 0x000000;
	move_str = ft_itoa(game->data.move);
	collect = ft_itoa(game->data.collect);
	if (!move_str)
	{
		ft_printf("%sError\nPrint move\n%s", RED, DEFAULT);
		return (0);
	}
	mlx_string_put(game->mlx_ptr, game->win_ptr, 9, 19, black, "Move :");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, white, "Move :");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 49, 19, black, move_str);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 50, 20, white, move_str);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 99, 19, black, "Collect :");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 20, white, "Collect :");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 159, 19, black, collect);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 160, 20, white, collect);
	free(move_str);
	free(collect);
	return (1);
}

int	draw_map(t_game *game)
{
	int			row;
	int			col;
	t_scroll	offsets;

	init_scroll_offsets(game, &offsets);
	row = 0;
	while (game->map.tab[row] != NULL)
	{
		col = 0;
		while (game->map.tab[row][col] != '\0')
		{
			draw_texture(game, row, col, &offsets);
			draw_collect(game, row, col, &offsets);
			draw_move(game);
			col++;
		}
		row++;
	}
	return (0);
}
