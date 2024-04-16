/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:37:25 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 14:53:57 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_check_read(t_game *game)
{
	if (game->map.tab[0] == NULL || !check_valid(game))
	{
		free_map(game);
		return (0);
	}
	game->map.tab_height = game->map.tab_col;
	game->map.tab_width = game->map.tab_row;
	return (1);
}

int	ft_read_map(int fd, t_game *game_init)
{
	int		i;
	char	*buffer;

	game_init->map.tab
		= ft_calloc(game_init->map.tab_read + 1, sizeof(char *));
	if (!game_init->map.tab)
	{
		free_map(game_init);
		return (0);
	}
	i = 0;
	buffer = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		game_init->map.tab[i] = buffer;
		i++;
	}
	game_init->map.tab_col = ft_strlen(game_init->map.tab[0]);
	game_init->map.tab_row = i;
	if (!ft_check_read(game_init))
		return (0);
	return (1);
}

int	ft_count_lines(int fd)
{
	int		count;
	char	buffer[BUFFER_SIZE];
	int		nbytes;
	int		i;

	count = 0;
	while (1)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes < 0)
		{
			ft_printf("%sError\nReading file%s", RED, DEFAULT);
			return (0);
		}
		if (nbytes == 0)
			break ;
		i = 0;
		while (i < nbytes)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
	}
	return (count++);
}

int	ft_read_count_map(char *map)
{
	int	fd;
	int	count;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	count = ft_count_lines(fd);
	if (close(fd) == -1)
		return (0);
	return (count);
}

int	open_map(char *map, t_game *game_init)
{
	int			fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%sError\nOpen file%s\n", RED, DEFAULT);
		return (0);
	}
	game_init->map.tab_read = ft_read_count_map(map);
	if (!game_init->map.tab_read
		|| game_init->map.tab_read < 3 || !ft_read_map(fd, game_init))
	{
		close (fd);
		free_map(game_init);
		return (0);
	}
	close (fd);
	return (1);
}
