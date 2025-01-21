# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 12:03:47 by ciestrad          #+#    #+#              #
#    Updated: 2025/01/16 11:07:31 by aszamora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = CUB3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
LIBFT_PATH	:=	libft
LIBFT		:=	libft.a

MLX			:=	libmlx42.a
MLX_PATH	:=	MLX42/build
LIBMLX		:=	./MLX42
OBJS_FAGS	:=	$(MLX) -ldl -lglfw -pthread -lm
CC			:=	gcc
CFLAGS		:=	-Wextra -Wall -Werror -Wunreachable-code -Ofast -Iincludes -g3

FILES = get_next_line/get_next_line \
		src/main \
		src/errors \
		src/parseo/ft_parseo \
		src/parseo/parse_struct \
		src/parseo/parsing_check \
		src/parseo/parse_grid \
		src/utils/utils_parse \
		src/utils/utils_parse02 \
		src/rayos/ray_casting \
		src/rayos/ray_select \
		src/rayos/ray_utils \
		src/draw/draw_walls\
		src/draw/draw_utils \
		src/draw/init_textures \
		src/draw/textures \
		src/movimiento/movement \

SRCS = $(addsuffix .c,$(FILES))
OBJS = $(addsuffix .o,$(FILES))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@clear
	@printf "\033[0;32;3mLIBFT\t\t\033[0;32;0m✅\n"
	@sleep 0.2;
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_FAGS) $(MLX) $(LIBFT) -o $(NAME)
	@printf "\033[0;32;3mCubed\t\033[0;32;0m✅\033[0;32;3m\n\n"

$(OBJ_DIR)%.o: $(SRC_PATH)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)
	@mv $(LIBFT_PATH)/$(LIBFT) ./

$(MLX):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@mv $(MLX_PATH)/$(MLX) ./

clean:
	@rm -fr $(OBJ_DIR)
	@make clean -C $(LIBFT_PATH)

fclean:
	@rm -fr $(OBJS)
	@rm -f $(NAME)
	@rm -f $(MLX)
	@rm -fr $(MLX_PATH)
	@rm -f $(LIBFT)
	@make fclean -C $(LIBFT_PATH)
	
re: fclean all

.PHONY: all clean fclean re