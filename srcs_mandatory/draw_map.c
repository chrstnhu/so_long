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

//Initialize a scroll if MAP > MAX_height || MAP > MAX_WIDHT
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

//Draw : PLAYER, COLLECT
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
	}
}

//Draw : EMPTY, WALL, EXIT
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

//Draw map with all the texture
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
			col++;
		}
		row++;
	}
	return (0);
}
