SRCS = $(addprefix mandatory/srcs/, init.c main.c drawing/draw.c drawing/put_pixel.c drawing/textures.c events/key_hooks.c events/player_moves.c list/list.c list/list2.c parsing/check_file_name.c parsing/check_map.c parsing/get_map_info.c parsing/get_raw_map.c parsing/get_texture.c parsing/get_color.c parsing/parsing.c raycasting/raycast.c utils/free_array.c utils/ft_atoi.c utils/ft_isdigit.c utils/ft_memcpy.c utils/ft_memset.c utils/ft_strchr.c utils/ft_strcmp.c utils/ft_strdup.c utils/ft_strlcpy.c utils/ft_strlen.c utils/ft_strtrim.c utils/ft_substr.c utils/is_empty_line.c utils/puterr.c parsing/utils/fill_spaces.c parsing/utils/free_map.c parsing/utils/is_player_spawn.c)

HEADERS = $(addprefix includes/, error.h parsing.h cub3d.h)

SRCS_BONUS = $(addprefix bonus/srcs/, init.c main.c door/open_door.c drawing/crosshair.c drawing/draw.c drawing/put_pixel.c drawing/textures.c events/key_hooks.c events/mouse.c events/player_moves.c gun/gun.c list/list.c list/list2.c mini_map/mini_map.c parsing/check_file_name.c parsing/check_map.c parsing/get_color.c parsing/get_map_info.c parsing/get_raw_map.c parsing/get_texture.c parsing/parsing.c raycasting/raycast.c utils/free_array.c utils/ft_atoi.c utils/ft_isdigit.c utils/ft_memcpy.c utils/ft_memset.c utils/ft_strchr.c utils/ft_strcmp.c utils/ft_strdup.c utils/ft_strlcpy.c utils/ft_strlen.c utils/ft_strtrim.c utils/ft_substr.c utils/is_empty_line.c utils/puterr.c parsing/utils/fill_spaces.c parsing/utils/free_map.c parsing/utils/is_player_spawn.c)

HEADERS_BONUS = $(addprefix includes/, error_bonus.h parsing_bonus.h cub3d_bonus.h)

GNL_HEADER = $(addprefix gnl/, get_next_line.h)

GNL = $(addprefix gnl/, gnl.a)

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

NAME = cub3D

NAME_BONUS = cub3D_bonus

COMP = cc

MLX = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror -O3 -mavx2 -flto -I includes -g3

all : $(NAME)

%.o : %.c $(HEADERS_BONUS) $(HEADERS)
	@$(COMP) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) $(GNL)
	@echo "Compiling mandatory ..."
	@$(COMP) $(MLX) $(CFLAGS) -I includes $(OBJS) $(GNL) -o $(NAME)

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