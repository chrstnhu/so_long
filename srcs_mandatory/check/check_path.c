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

void	enqueue(t_queue *queue, t_node node)
{
	if (queue->size < queue->max_size)
	{
		queue->array[queue->back++] = node;
		queue->size++;
	}
	else
		ft_printf("%sError\n Invalid queue%s\n", RED, DEFAULT);
}

t_node	dequeue(t_queue *queue)
{
	t_node	node;

	node = queue->array[queue->front++];
	queue->size--;
	return (node);
}

//Check if neighbors is a WALL
void	check_neighbors(t_neighbors_data *data, t_node *current)
{
	int	i;
	int	new_row;
	int	new_col;
	int	new_distance;

	i = 0;
	while (i < 4)
	{
		new_row = current->row + data->moves[i][0];
		new_col = current->col + data->moves[i][1];
		if (is_valid_move(data->game, new_row, new_col, data->distances)
			&& !(data->game->map.tab[new_row][new_col] == WALL))
		{
			new_distance = data->distances[current->row][current->col] + 1;
			data->distances[new_row][new_col] = new_distance;
			if (data->game->map.tab[new_row][new_col] == COLLECTIBLE)
				data->collected_collectibles++;
			enqueue(data->queue, (t_node){new_row, new_col});
		}
		i++;
	}
}

//Check if a valid path exists between start and end nodes in the game map
int	is_path_valid(t_game *game, t_node start, t_node end)
{
	int					**distances;
	t_queue				queue;
	t_node				current;
	t_neighbors_data	data;
	int					result;

	data = (t_neighbors_data){game, &queue, NULL, {0}, 0};
	initialize_moves(data.moves);
	queue = init_queue(game->map.tab_row * game->map.tab_col);
	enqueue(&queue, start);
	distances = init_distances(game->map.tab_row, game->map.tab_col);
	data.distances = distances;
	distances[start.row][start.col] = 0;
	while (queue.size > 0)
	{
		current = dequeue(&queue);
		check_neighbors(&data, &current);
	}
	result = distances[end.row][end.col];
	free_queue_distances(&queue, distances, game->map.tab_row);
	if (data.collected_collectibles != data.game->data.collect)
		return (0);
	return (result != -1);
}
