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

#include "../../includes/so_long.h"

//Check down wall
int	check_down(t_game *game)
{
	int	i;
	int	j;
	int	check_down;

	i = game->map.tab_row - 1;
	j = 0;
	check_down = 0;
	while (j < game->map.tab_col)
	{
		if (game->map.tab[i][j] == WALL)
			check_down++;
		j++;
	}
	if (check_down == game->map.tab_col - 1)
		return (1);
	else
	{
		ft_printf("%sError\nInvalid check_down%s\n", RED, DEFAULT);
		return (0);
	}
}

//Check up wall
int	check_up(t_game *game)
{
	int	j;
	int	count_top;

	j = 0;
	count_top = 0;
	while (j < game->map.tab_col)
	{
		if (game->map.tab[0][j] == WALL)
			count_top++;
	j++;
	}
	if (count_top == game->map.tab_col - 1)
		return (1);
	else
	{
		ft_printf("%sError\nInvalid check_top%s\n", RED, DEFAULT);
		return (0);
	}
}

//Check left wall
int	check_left(t_game *game)
{
	int	i;
	int	count_left;

	i = 0;
	count_left = 0;
	while (i < game->map.tab_row)
	{
		if (i > 0 && game->map.tab[i][0] == WALL)
			count_left++;
		i++;
	}
	if (count_left == game->map.tab_row - 1)
		return (1);
	else
	{
		ft_printf("%sError\nInvalid check_left%s\n", RED, DEFAULT);
		return (0);
	}
}

//Check right wall
int	check_right(t_game *game)
{
	int	i;
	int	count_right;

	i = 0;
	count_right = 0;
	while (i < game->map.tab_row)
	{
		if (i > 0 && game->map.tab[i][game->map.tab_col - 2] == WALL)
			count_right++;
	i++;
	}
	if (count_right == game->map.tab_row - 1)
		return (1);
	else
	{
		ft_printf("%sError\nInvalid check_right%s\n", RED, DEFAULT);
		return (0);
	}
}

//Check path valid
int	check_path(t_game *game)
{
	t_node	start;
	t_node	end;
	int		i;
	int		j;

	i = 0;
	while (i < game->map.tab_row)
	{
		j = 0;
		while (j < game->map.tab_col)
		{
			if (game->map.tab[i][j] == PLAYER)
				start = (t_node){i, j};
			else if (game->map.tab[i][j] == EXIT)
				end = (t_node){i, j};
			j++;
		}
		i++;
	}
	if (is_path_valid(game, start, end))
		return (1);
	else
		ft_printf("%sError\nNo valid path form P to E%s\n", RED, DEFAULT);
	return (0);
}
