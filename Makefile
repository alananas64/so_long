# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nosman <nosman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 08:54:28 by nosman            #+#    #+#              #
#    Updated: 2024/05/17 13:40:06 by nosman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
NAME_B	=	so_long_bonus
CC		=	cc
RM		=	rm -fr
MLX		=	./mlx/libmlx.a
CFLAGS	=	-Wall -Wextra -Werror -Imlx -g3 -O2 -fsanitize=address
MLXFLAG	=	-Lmlx -lmlx -framework OpenGL -framework AppKit

SRC		=	./so_long.c \
			./utils/ft_printf/ft_char.c \
			./utils/ft_printf/ft_hexa.c \
			./utils/ft_printf/ft_nbr.c \
			./utils/ft_printf/ft_perr.c \
			./utils/ft_printf/ft_printf.c \
			./utils/ft_printf/ft_ptr.c \
			./utils/ft_printf/ft_putchar_fd.c \
			./utils/ft_printf/ft_putendl_fd.c \
			./utils/ft_printf/ft_putnbr_fd.c \
			./utils/ft_printf/ft_putstr_fd.c \
			./utils/gnl/get_next_line.c \
			./utils/gnl/get_next_line_utils.c \
			./utils/map_prep.c \
			./utils/map_utils.c \
			./utils/map_validity.c \
			./utils/utils.c \
			./utils/valid_path.c \
			./utils/graphics/player_movments.c \
			./utils/graphics/check_images.c \
			./utils/graphics/put_images.c

SRC_B	=	./Bonus/so_long_bonus.c \
			./Bonus/utils/ft_printf/ft_char.c \
			./Bonus/utils/ft_printf/ft_hexa.c \
			./Bonus/utils/ft_printf/ft_nbr.c \
			./Bonus/utils/ft_printf/ft_perr.c \
			./Bonus/utils/ft_printf/ft_printf.c \
			./Bonus/utils/ft_printf/ft_ptr.c \
			./Bonus/utils/ft_printf/ft_putchar_fd.c \
			./Bonus/utils/ft_printf/ft_putendl_fd.c \
			./Bonus/utils/ft_printf/ft_putnbr_fd.c \
			./Bonus/utils/ft_printf/ft_putstr_fd.c \
			./Bonus/utils/gnl/get_next_line.c \
			./Bonus/utils/gnl/get_next_line_utils.c \
			./Bonus/utils/graphics/check_images.c \
			./Bonus/utils/graphics/player_movments.c \
			./Bonus/utils/graphics/put_images.c \
			./Bonus/utils/map_prep.c \
			./Bonus/utils/map_utils.c \
			./Bonus/utils/map_validity.c \
			./Bonus/utils/utils.c \
			./Bonus/utils/valid_path.c

REMOVE	=	a.out \
			a.out.dSYM \
			so_long.dSYM \
			so_long_bonus.dSYM

EXE		=	so_long

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(ARCHIVE)
	@make -s -C ./mlx
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAG) $(MLX) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(NAME_B) $(EXE) $(REMOVE)

re: fclean all

bonus:
	$(CC) $(CFLAGS) $(MLXFLAG) $(MLX) $(SRC_B) -o $(NAME_B)

norm:
	@norminette $(SRC)

.PHONY: all clean fclean re norm bonus
