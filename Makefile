NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	collectables.c handlers.c hooks.c init_images_1.c \
				init_images_2.c init_map.c init_window.c main.c \
				map_valid_1.c map_valid_2.c utils.c \
				valid_path_utils.c valid_path.c
OBJS		=	$(SRCS:.c=.o)
HEADER		=	so_long.h
GLFW_DIR	=	/Users/fshields/.brew/opt/glfw/lib
MLX			=	MLX42/build/libmlx42.a
MLX_HEADER	=	MLX42/include/MLX42/MLX42.h
LIBFT		=	libft/libft.a

all:			$(NAME)

$(LIBFT):
					@make -C ./libft

$(MLX):
					@cd MLX42 && cmake -B build && cmake --build build -j4

$(NAME):		$(OBJS) $(MLX) $(LIBFT) $(HEADER)
					@$(CC) $(OBJS) $(MLX) $(LIBFT) -ldl -pthread -lm -L$(GLFW_DIR) -lglfw -I $(MLX_HEADER) -o $(NAME)
					@echo "  .............  "
					@echo "  .. so_long ..  "
					@echo "  .............  "
					@echo "Compilation successful 👍"

%.o:			%.c
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@rm -f $(OBJS)
					@rm -rf MLX42/build
					make fclean -C ./libft

fclean:			clean
					@rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re