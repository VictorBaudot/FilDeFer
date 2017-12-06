# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 08:32:05 by vbaudot           #+#    #+#              #
#    Updated: 2017/12/06 14:18:39 by vbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fdf
SRC = main.c\
		print_usage.c\
		draw_segment.c\
		fdf.c\
		print_map_points.c\
		events.c\
		create_map.c\
		get_center.c\

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIBFLAG = -Ilibft/
DLIB = libft/
LIBFT = libft.a
MAIFLAG = -I./

YEL="\\033[33m"
BLU="\\033[34m"
RED="\\033[31m"
NC="\\033[0m"
MAG="\\033[35m"
CYA="\\033[36m"
GRE="\\033[32m"
BOL="\\033[1m"
CHE="\\xE2\\x9C\\x94"
OK="$(GRE)$(CHE)$(NC)"

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C minilibx
	@mv minilibx/libmlx.a .
	@printf "\n[$(NAME)] linking $(CYA)$(BOL)$(OBJ)$(NC)\n"
	@printf "to make the binary $(MAG)$(BOL)$(NAME)$(NC)"
	@gcc -Wall -Werror -Wextra -g -fsanitize=address -L./libft -lmlx -lft -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)
	@printf '\t\t'$(OK)'\n'

%.o: %.c
	@printf "\r\033[0K[$(NAME)] compile $(BOL)$(YEL)$<$(NC)..."
	@$(CC) $(CFLAGS) -I./libft -I./minilibx -c $<
	@printf '\t'$(OK)

clean:
	@make -C minilibx clean
	@make -C libft clean
	@printf "[$(NAME)] rm all $(BOL)$(RED) obj file$(NC)"
	@rm -rf $(OBJ) libmlx.a
	@printf '\t\t'$(OK)'\n'

fclean: clean
	@make -C minilibx clean
	@make -C libft fclean
	@printf "[$(NAME)] rm $(BOL)$(CYA)$(NAME)$(NC)"
	@rm -rf $(NAME)
	@printf '\t\t'$(OK)'\n'

re: fclean all

proper: all clean

.PHONY: re proper
