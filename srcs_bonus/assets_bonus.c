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

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_obj.floor);
	mlx_destroy_image(game->mlx_ptr, game->img_obj.player_left);
	mlx_destroy_image(game->mlx_ptr, game->img_obj.player_right);
	mlx_destroy_image(game->mlx_ptr, game->img_obj.player_down);
	mlx_destroy_image(game->mlx_ptr, game->img_obj.player_up);
	mlx_destroy_image(game->mlx_ptr, game->img_obj.wall);
	mlx_destroy_image(game->mlx_ptr, game->img_obj.collect);
	mlx_destroy_image(game->mlx_ptr, game->img_obj.exit_open);
	mlx_destroy_image(game->mlx_ptr, game->img_obj.exit_close);
	mlx_destroy_image(game->mlx_ptr, game->img_obj.enemy);
	game->img_obj = (t_obj){0};
}

void	check_img(t_game *game, void **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (!(*img))
	{
		ft_printf("%sError\nFail init sprite (xpm)\n", RED);
		free_exit_prog(game);
	}
}

void	set_img(t_game *game)
{
	check_img(game, &game->img_obj.floor, FLOOR_PATH);
	check_img(game, &game->img_obj.player_left, PLAYER_LEFT_PATH);
	check_img(game, &game->img_obj.player_right, PLAYER_RIGHT_PATH);
	check_img(game, &game->img_obj.player_down, PLAYER_DOWN_PATH);
	check_img(game, &game->img_obj.player_up, PLAYER_UP_PATH);
	check_img(game, &game->img_obj.wall, WALL_PATH);
	check_img(game, &game->img_obj.collect, COLLECT_PATH);
	check_img(game, &game->img_obj.exit_open, EXIT_OPEN_PATH);
	check_img(game, &game->img_obj.exit_close, EXIT_CLOSE_PATH);
	check_img(game, &game->img_obj.enemy, ENEMY01_PATH);
}

void	anim_collect(t_game *game)
{
	if (game->data.anim_enemy >= 121)
		game->data.anim_enemy = 0;
	mlx_destroy_image(game->mlx_ptr, game->img_obj.collect);
	if (game->data.anim_enemy <= 40)
		check_img(game, &game->img_obj.collect, COLLECT_PATH);
	else if (game->data.anim_enemy <= 80)
		check_img(game, &game->img_obj.collect, COLLECT02_PATH);
	else if (game->data.anim_enemy <= 120)
		check_img(game, &game->img_obj.collect, COLLECT03_PATH);
	game->data.anim_enemy++;
	draw_map(game);
}
