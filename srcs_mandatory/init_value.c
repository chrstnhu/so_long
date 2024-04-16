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

//Initialize all the value
void	init_value(t_game *game)
{
	t_obj	*obj;

	*game = (t_game){0};
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map.tab = NULL;
	game->map.tab_row = 0;
	game->map.tab_col = 0;
	game->map.tab_height = 0;
	game->map.tab_width = 0;
	game->data.move = 0;
	obj = malloc(sizeof(t_obj));
	if (!obj)
	{
		ft_printf("%s Error\nFail init object!%s", RED, DEFAULT);
		return ;
	}
	game->img_obj = *obj;
	free (obj);
	return ;
}
