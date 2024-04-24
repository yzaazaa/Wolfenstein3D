SRCS = main.c srcs/list/list.c srcs/list/list2.c srcs/parsing/check_file_name.c srcs/parsing/check_map.c srcs/parsing/get_color.c srcs/parsing/get_map_info.c srcs/parsing/get_raw_map.c srcs/parsing/get_texture.c srcs/parsing/parsing.c srcs/utils/ft_atoi.c srcs/utils/ft_isdigit.c srcs/utils/ft_memcpy.c srcs/utils/ft_memset.c srcs/utils/ft_strchr.c srcs/utils/ft_strcmp.c srcs/utils/ft_strdup.c srcs/utils/ft_strlcpy.c srcs/utils/ft_strlen.c srcs/utils/ft_strtrim.c srcs/utils/ft_substr.c srcs/utils/get_color.c srcs/utils/is_empty_line.c srcs/utils/puterr.c srcs/parsing/utils/fill_spaces.c srcs/parsing/utils/free_map.c srcs/parsing/utils/is_player_spawn.c srcs/parsing/utils/print_map.c

HEADERS = includes/list.h includes/error.h includes/parsing.h includes/raycast.h

GNL_HEADER = srcs/gnl/get_next_line.h

GNL = srcs/gnl/gnl.a

OBJS = ${SRCS:.c=.o}

NAME = cub3d

COMP = cc

CFLAGS = -Wall -Wextra -Werror -ggdb3 -fsanitize=address


all : $(NAME)

$(NAME) : $(OBJS) $(GNL)
	$(COMP) -fsanitize=address -lmlx -framework OpenGL -framework AppKit $(OBJS) $(GNL) -o $(NAME)

$(GNL) : $(GNL_HEADER)
	$(MAKE) -C srcs/gnl/

%.o : %.c $(HEADERS)
	$(COMP) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(OBJS) $(NAME)

re : fclean all