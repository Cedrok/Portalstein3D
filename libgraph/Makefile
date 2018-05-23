# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bspindle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:32:49 by bspindle          #+#    #+#              #
#    Updated: 2018/02/23 10:25:46 by bspindle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libgraph.a

SRC_PATH = .

OBJ_PATH = .

LIB_PATH = libft

LIB_NAME = libft.a

CC = gcc 

CPP = -c

CFLAGS = -Wall -Werror -Wextra

SRC_NAME = ft_vect_new.c			\
		   ft_fill_pixel.c			\
		   ft_put_seg.c				\
		   ft_zoom.c				\
		   ft_matrix_vector_prod.c	\
		   lambda_product.c			\
		   ft_vector_sum.c			\
		   ft_put_half_right.c		\
		   ft_new_seg.c				\
		   ft_vd4_new.c				\
		   ft_vd3_sum.c				\
		   ft_create_new_data.c		\
		   ft_free_data.c			\
		   distance_d2.c

INCLUDE = ../includes/

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@ ar rcs  $(NAME) $(OBJ) $(LIB)

%.o: %.c
	@ $(CC)  $(CFLAGS) -c $(SRC_NAME) -I $(INCLUDE)

$(LIB):
	@ make -C $(LIB_PATH)

clean:
	@ rm -f $(OBJ)
	@ make clean -C $(LIB_PATH)

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C $(LIB_PATH)

re: fclean all

