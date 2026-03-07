# Compiler and flags (42 norm required)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
MLX_DIR = minilibx-linux

# Colors
GREEN	:= \033[92m
OFF		:= \033[0m
YELLOW  := \033[33m

# Source files and object files
SRCS = color.c events_utils.c init.c math_utils.c string_utils.c events.c fractal.c main.c render.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Rules
all: mlx_clone $(OBJ_DIR) $(NAME)
	@echo "\n$(GREEN)Project '$(NAME)' compiled successfully!$(OFF)\n"

mlx_clone:
	@if [ ! -d $(MLX_DIR) ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git; \
		make -C $(MLX_DIR); \
	fi

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fractol.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Removed obj files and obj directory...$(OFF)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Removed executable...$(OFF)"

ffclean: fclean 
	@rm -rf $(MLX_DIR)
	@echo "$(YELLOW)Removed minilibx library!$(OFF)"

.PHONY: all clean fclean ffclean mlx_clone

