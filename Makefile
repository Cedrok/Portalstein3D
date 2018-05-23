# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bspindle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:32:49 by bspindle          #+#    #+#              #
#    Updated: 2018/04/16 16:41:37 by cvautrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, norm
.SILENT: clean, fclean

NAME = wolf3d

SRC_PATH = srcs

OBJ_PATH = srcs

LIB1_PATH = libgraph

LIB1_NAME = libgraph.a

LIB2_PATH = libgraph/libft

LIB2_NAME = libft.a

CC = gcc 

CPP = -c

CFLAGS = -Wall -Werror -Wextra -Ofast -flto

MLX_PATH = minilibx_macos

CMLX_FLAGS = -L $(MLX_PATH) -lmlx -framework AppKit -framework OpenGL -lpthread

SRC_NAME = main.c			\
		   find_distance.c	\
		   draw_actual_view.c\
		   wolf3d_key_hook.c\
		   find_next_step.c	\
		   first_wall_met.c	\
		   next_wall_forbidden_value.c\
		   mod_2pi.c		\
		   wall_angle_checker.c\
		   parser.c			\
		   wolf3d_move_hook.c\
		   textures.c		\
		   put_wall_texture_ns.c\
		   put_wall_texture_ew.c\
		   anim.c			\
		   thread.c			\
		   clean_data.c		\
		   menu.c			\
		   menu_key_hook.c	\
		   menu_mouse_hook.c\
		   minimap.c		\
		   minimap_squares.c\
		   find_start_pos.c

INCLUDE = includes/

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIB1 = $(addprefix $(LIB1_PATH)/,$(LIB1_NAME))

LIB2 = $(addprefix $(LIB2_PATH)/,$(LIB2_NAME))

MLX = $(addprefix $(MLX_PATH),mlx.a)

NONE = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m

all: $(LIB1) $(MLX) $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(CMLX_FLAGS) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB1) $(LIB2)

%.o:%.c includes/wolf3d.h
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(LIB1):
	@ make -C $(LIB1_PATH)
	@ echo "$(GREEN)$(LIB1_NAME) compiled.$(NONE)"

$(MLX):
	@ make -C $(MLX_PATH)
	@ echo "$(GREEN)mlx.a compiled.$(NONE)"

clean:
	@ rm -f $(OBJ)
	@ make clean -C $(LIB1_PATH)
	@ echo "$(YELLOW)$(LIB1_NAME) : objetcs fiLes deleted.$(NONE)"
	@ make clean -C $(MLX_PATH)
	@ echo "$(RED)mlx.a and objetcs fiLes deleted.$(NONE)"

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C $(LIB1_PATH)
	@ echo "$(RED)$(LIB1_NAME) deleted.$(NONE)"



norm: clean
	@ norminette includes/ libgraph/ libcomplex/ srcs/ | grep -B 1 '^Error' 2> /dev/null || echo '$(GREEN)norme OK !$(NONE)';

re: fclean all
