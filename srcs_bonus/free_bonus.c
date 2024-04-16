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

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map.tab)
		return ;
	while (game->map.tab[i])
	{
		free(game->map.tab[i]);
		i++;
	}
	free(game->map.tab);
	game->map.tab = NULL;
	return ;
}

int	free_exit_prog(t_game *game)
{
	ft_printf("Window closed.\n");
	free_img(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

int	free_exit_prog_close(t_game *game)
{
	free_map(game);
	free_exit_prog(game);
	return (0);
}

// Libérer la mémoire allouée à la file de priorité
void	free_queue_distances(t_queue *queue, int **distances, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(distances[i]);
		i++;
	}
	free(distances);
	free(queue->array);
}
