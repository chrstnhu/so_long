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

#include "../../includes/so_long_bonus.h"

int	check_rectangle(t_game *game)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	len1 = ft_strlen(game->map.tab[i]);
	len2 = ft_strlen(game->map.tab[i + 1]);
	while (i < game->map.tab_row - 2)
	{
		if (len1 != len2)
		{
			ft_printf("%sError\nInvalid check rectangle%s\n", RED, DEFAULT);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_letter(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.tab_row)
	{
		j = 0;
		while (j < game->map.tab_col)
		{
			if (game->map.tab[i][j] == ENEMY)
				game->data.enemy++;
			else if (!(ft_strchr(TEXTURE, game->map.tab[i][j])
				|| game->map.tab[i][j] == '\n'))
			{
				ft_printf("%sError\nInvalid check letter%s\n", RED, DEFAULT);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_collectible(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.tab_row)
	{
		j = 0;
		while (j < game->map.tab_col)
		{
			if (game->map.tab[i][j] == COLLECTIBLE)
				game->data.collect++;
			j++;
		}
		i++;
	}
	if (game->data.collect >= 1)
		return (1);
	else
	{
		ft_printf("%sError\nInvalid check collectible%s\n", RED, DEFAULT);
		return (0);
	}
}

int	check_char(t_game *game, int letter)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < game->map.tab_row)
	{
		j = 0;
		while (j < game->map.tab_col)
		{
			if (game->map.tab[i][j] == letter)
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	else
	{
		ft_printf("%sError\nInvalid check char%s\n", RED, DEFAULT);
		return (0);
	}
}

int	check_valid(t_game *game)
{
	return (check_rectangle(game) && check_letter(game)
		&& check_char(game, PLAYER) && check_char(game, EXIT)
		&& check_collectible(game)
		&& check_up(game) && check_left(game)
		&& check_right(game) && check_down(game)
		&& check_path(game));
}
