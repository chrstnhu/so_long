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

//Initialize and allocate memory for the priority queue
t_queue	init_queue(int size)
{
	t_queue	queue;

	queue.array = malloc(size * sizeof(t_node));
	queue.front = 0;
	queue.back = 0;
	queue.size = 0;
	queue.max_size = size;
	return (queue);
}

//Initialize and allocate memory for the distances array tab 2d
int	**init_distances(int rows, int cols)
{
	int	**distances;
	int	i;
	int	j;

	i = 0;
	distances = malloc(rows * sizeof(int *));
	while (i < rows)
	{
		j = 0;
		distances[i] = malloc(cols * sizeof(int));
		while (j < cols)
		{
			distances[i][j] = -1;
			j++;
		}
		i++;
	}
	return (distances);
}

//Initialize the possible moves (up, down, left, right)
void	initialize_moves(int moves[4][2])
{
	moves[0][0] = -1;
	moves[0][1] = 0;
	moves[1][0] = 1;
	moves[1][1] = 0;
	moves[2][0] = 0;
	moves[2][1] = -1;
	moves[3][0] = 0;
	moves[3][1] = 1;
}

int	is_valid_move(t_game *game, int row, int col, int **distances)
{
	return (row >= 0 && row < game->map.tab_row
		&& col >= 0 && col < game->map.tab_col
		&& (distances != NULL && distances[row] != NULL)
		&& (distances[row][col] == -1));
}
