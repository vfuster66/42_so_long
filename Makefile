# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

# Nom du programme
NAME = so_long

# Bibliothèques
LIB_PATH = ./libft
LIB_NAME = libft.a
LIB_INC = -I$(LIB_PATH)
LIB_LINK = -L$(LIB_PATH) -lft

# MiniLibX (pour Linux seulement)
MLX_PATH = ./mlx_linux
MLX_NAME = libmlx_Linux.a
MLX_INC = -I$(MLX_PATH)
MLX_LINK = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz

# Sources
SRCS = main.c \
	src/input.c \
	src/map.c \
	src/so_long.c \
	src/sprites.c \
	src/tools.c \
	src/check_map.c \
	src/init.c \

# Objets
OBJS = $(SRCS:.c=.o)

# Règles
%.o: %.c
	@$(CC) $(CFLAGS) $(LIB_INC) $(MLX_INC) -c $< -o $@

all: compile

compile: $(OBJS)
		@if ! [ -f $(NAME) ] || [ "$(OBJS)" -nt "$(NAME)" ]; then \
				make -s -C $(LIB_PATH); \
				make -s -C $(MLX_PATH); \
				$(CC) $(CFLAGS) $(OBJS) $(LIB_INC) $(LIB_LINK) $(MLX_INC) $(MLX_LINK) -o $(NAME); \
				echo "✅ So_long compiled\n"; \
				echo "$$ASCII_MANDATORY"; \
		else \
				echo "✅ All is up-to-date"; \
		fi

clean:
		@$(RM) $(OBJS)
		@make -s -C $(LIB_PATH) clean
		@echo "✅ Libft Cleaned\n"

fclean: clean
		@$(RM) $(NAME)
		@make -s -C $(LIB_PATH) fclean
		@echo "✅ So_long Cleaned\n"

re: fclean all

# Colors
RED = \033[0;31m
NO_COLOR = \033[0m

# Ascii
info: ascii

define ASCII_MANDATORY
$(RED) Et merci pour le :
$(NO_COLOR)
$(RED)                       ,         $(NO_COLOR)
$(RED)       ❤            .:/          $(NO_COLOR)
$(RED)         o      ,,///;,   ,;/    $(NO_COLOR)
$(RED)           o   o)::::::;;///     $(NO_COLOR)
$(RED)              >::::::::;;\\\     $(NO_COLOR)
$(RED)                ''\\\\\'" ';\    $(NO_COLOR)
$(RED)                   ';\           $(NO_COLOR)
$(NO_COLOR)
endef
export ASCII_MANDATORY

.PHONY: all clean fclean re bonus




