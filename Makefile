SRCS = $(addprefix mandatory/, main.c srcs/list/list.c srcs/list/list2.c srcs/parsing/check_file_name.c srcs/parsing/check_map.c srcs/parsing/get_color.c srcs/parsing/get_map_info.c srcs/parsing/get_raw_map.c srcs/parsing/get_texture.c srcs/parsing/parsing.c srcs/raycasting/cub3d.c srcs/raycasting/draw.c srcs/raycasting/init.c srcs/raycasting/key_hooks.c srcs/raycasting/raycast.c srcs/raycasting/player_moves.c srcs/utils/free_array.c srcs/utils/ft_atoi.c srcs/utils/ft_isdigit.c srcs/utils/ft_memcpy.c srcs/utils/ft_memset.c srcs/utils/ft_strchr.c srcs/utils/ft_strcmp.c srcs/utils/ft_strdup.c srcs/utils/ft_strlcpy.c srcs/utils/ft_strlen.c srcs/utils/ft_strtrim.c srcs/utils/ft_substr.c srcs/utils/get_color.c srcs/utils/is_empty_line.c srcs/utils/puterr.c srcs/parsing/utils/fill_spaces.c srcs/parsing/utils/free_map.c srcs/parsing/utils/is_player_spawn.c srcs/raycasting/crosshair.c)

HEADERS = includes/error.h includes/parsing.h includes/cub3d.h

SRCS_BONUS = $(addprefix bonus/, main.c srcs/list/list.c srcs/list/list2.c srcs/parsing/check_file_name.c srcs/parsing/check_map.c srcs/parsing/get_color.c srcs/parsing/get_map_info.c srcs/parsing/get_raw_map.c srcs/parsing/get_texture.c srcs/parsing/parsing.c srcs/raycasting/cub3d.c srcs/raycasting/draw.c srcs/raycasting/init.c srcs/raycasting/key_hooks.c srcs/raycasting/raycast.c srcs/raycasting/player_moves.c srcs/utils/free_array.c srcs/utils/ft_atoi.c srcs/utils/ft_isdigit.c srcs/utils/ft_memcpy.c srcs/utils/ft_memset.c srcs/utils/ft_strchr.c srcs/utils/ft_strcmp.c srcs/utils/ft_strdup.c srcs/utils/ft_strlcpy.c srcs/utils/ft_strlen.c srcs/utils/ft_strtrim.c srcs/utils/ft_substr.c srcs/utils/get_color.c srcs/utils/is_empty_line.c srcs/utils/puterr.c srcs/parsing/utils/fill_spaces.c srcs/parsing/utils/free_map.c srcs/parsing/utils/is_player_spawn.c srcs/mini_map/mini_map.c srcs/raycasting/crosshair.c srcs/raycasting/open_door.c srcs/raycasting/gun.c)

HEADERS_BONUS = includes/error_bonus.h includes/parsing_bonus.h includes/cub3d_bonus.h

GNL_HEADER = gnl/get_next_line.h

GNL = gnl/gnl.a

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

NAME = cub3d

NAME_BONUS = cub3d_bonus

COMP = cc

MLX = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror -O3 -mavx2 -flto -I includes #-ggdb3 -fsanitize=address

all : $(NAME)

%.o : %.c $(HEADERS_BONUS) $(HEADERS)
	@$(COMP) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) $(GNL)
	@echo "Compiling mandatory ..."
	@$(COMP) $(MLX)  -I includes $(OBJS) $(GNL) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) $(GNL)
	@echo "Compiling bonus ..."
	@$(COMP) $(MLX) $(CFLAGS) $(OBJS_BONUS) $(GNL) -o $(NAME_BONUS)

$(GNL) : $(GNL_HEADER)
	@$(MAKE) -C gnl/

clean :
	@echo "Deleting object files ..."
	@$(MAKE) clean -C gnl
	@rm -rf $(OBJS_BONUS) $(OBJS)

fclean :
	@echo "Deleting all ..."
	@$(MAKE) fclean -C gnl
	@rm -rf $(OBJS_BONUS) $(NAME_BONUS) $(OBJS) $(NAME)

re : fclean all