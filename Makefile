# Path to libraries
MLX_PATH = ./minilibx-linux/
LIBFT_PATH = ./libft
LIBS_PATH = -L$(LIBFT_PATH) -L$(MLX_PATH)
SRCS_PATH = srcs_mandatory
SRCS_BONUS_PATH = srcs_bonus

# Source
SRCS_MANDATORY = assets.c draw_map.c \
	free.c \
	init_game.c init_map.c init_value.c \
	player_move.c player_move_utils.c \
	check/check_extension.c check/check_map.c \
	check/check_path.c check/check_path_utils.c \
	check/check_wall.c \
	
SRCS_WITH_BONUS = assets_bonus.c draw_map_bonus.c \
	free_bonus.c enemy_move_bonus.c \
	init_game_bonus.c init_map_bonus.c init_value_bonus.c \
	player_move_bonus.c player_move_utils_bonus.c \
	check/check_extension_bonus.c check/check_map_bonus.c \
	check/check_path_bonus.c check/check_path_utils_bonus.c \
	check/check_wall_bonus.c \

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_MANDATORY))
OBJS = $(SRCS_MANDATORY:%.c=$(SRCS_PATH)/%.o)

SRCS_BONUS = $(addprefix $(SRCS_BONUS_PATH)/, $(SRCS_WITH_BONUS))
OBJS_BONUS = $(SRCS_WITH_BONUS:%.c=$(SRCS_BONUS_PATH)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm -lbsd -lft
INCLUDES = -I$(LIBFT_PATH) -I$(MLX_PATH) 

NAME = so_long
NAME_BONUS = so_long_bonus

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS_PATH)/main.c  $(OBJS) $(LIBS_PATH) $(LFLAGS)
	
$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(SRCS_BONUS_PATH)/main_bonus.c  $(OBJS_BONUS) $(LIBS_PATH) $(LFLAGS)

$(SRCS_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	
$(SRCS_BONUS_PATH)/%.o: $(SRCS_BONUS_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f libmlx.a
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re

