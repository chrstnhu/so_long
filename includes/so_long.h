/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:26:53 by chrhu             #+#    #+#             */
/*   Updated: 2024/02/09 14:26:56 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/X.h>

//Max window
# define MAX_WINDOW_WIDTH 1920
# define MAX_WINDOW_HEIGHT 1080

//Color
# define DEFAULT "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"

//Game Objet
# define TEXTURE "PCE10"
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define WALL '1'
# define EMPTY '0'

//Texture Path
# define FLOOR_PATH "./assets/floor.xpm"
# define PLAYER_LEFT_PATH "./assets/player_left_01.xpm"
# define PLAYER_RIGHT_PATH "./assets/player_right_01.xpm"
# define PLAYER_DOWN_PATH "./assets/player_down_01.xpm"
# define PLAYER_UP_PATH "./assets/player_up_01.xpm"
# define WALL_PATH "./assets/wall.xpm"
# define COLLECT_PATH "./assets/collect_01.xpm"
# define EXIT_OPEN_PATH "./assets/exit_open_01.xpm"
# define EXIT_CLOSE_PATH "./assets/exit_close_01.xpm"
# define IMG_SIZE 30

typedef struct s_map
{
	char	**tab;
	int		tab_read;
	int		tab_col;
	int		tab_row;
	int		tab_size;
	int		tab_height;
	int		tab_width;
}	t_map;

typedef struct s_pos
{
	int	x;
	int	y;
	int	player_col;
	int	player_row;
	int	exit_col;
	int	exit_row;
}	t_pos;

typedef struct s_data
{
	int	collect;
	int	exit_close;
	int	exit_open;
	int	height;
	int	width;
	int	move;
}	t_data;

typedef struct s_obj
{
	void	*floor;
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*player_up;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*exit_close;
	void	*exit_open;
	int		height;
	int		width;
	int		scroll_pos;
}	t_obj;

typedef struct s_game
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img_ptr;
	char	*addr;
	int		win_width;
	int		win_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		height;
	int		width;
	t_obj	img_obj;
	t_data	data;
	t_pos	pos;
	t_map	map;
}	t_game;

typedef struct s_scroll
{
	int	scroll_x;
	int	scroll_y;
}	t_scroll;

//Structure to find valid path
typedef struct s_node
{
	int	row;
	int	col;
}	t_node;

typedef struct s_queue
{
	t_node	*array;
	int		front;
	int		back;
	int		size;
	int		max_size;
}	t_queue;

typedef struct t_neighbors_data
{
	t_game			*game;
	t_queue			*queue;
	int				**distances;
	int				moves[4][2];
	int				collected_collectibles;
}	t_neighbors_data;

//Check valid
int				check_extension(char *argv);
int				check_valid(t_game *game);
int				check_char(t_game *game, int letter);
int				check_collectible(t_game *game);
int				check_letter(t_game *game);
int				check_rectangle(t_game *game);
int				check_right(t_game *game);
int				check_left(t_game *game);
int				check_up(t_game *game);
int				check_down(t_game *game);
int				check_path(t_game *game);

//Check valid path
int				is_path_valid(t_game *game, t_node start, t_node end);
int				is_valid_move(t_game *game, int row, int col, int **distances);
int				**init_distances(int rows, int cols);
void			check_neighbors(t_neighbors_data *data, t_node *current);
void			enqueue(t_queue *queue, t_node node);
void			initialize_moves(int moves[4][2]);
t_node			dequeue(t_queue *queue);
t_queue			init_queue(int size);

//Read map
int				open_map(char *map, t_game *game);

//Init game
void			init_value(t_game *game);
void			init_game(t_game *game);
void			initialize_moves(int moves[4][2]);
int				draw_map(t_game *game);

//Free
int				free_exit_prog(t_game *game);
int				free_exit_prog_close(t_game *game);
void			free_map(t_game *game);
void			free_queue_distances(t_queue *queue, int **distances, int rows);

//SPRITE
void			check_img(t_game *game, void **img, char *path);
void			set_img(t_game *game);
void			free_img(t_game *game);

//MOVE
int				player_move(int keysym, t_game *game);
int				key_move(t_game *game, int col, int row);
void			locate_player(t_game *game);

#endif
