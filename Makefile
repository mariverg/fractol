NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MINILIBX_LINUX_PATH = minilibx-linux
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
MLXFLAG = -L $(MINILIBX_LINUX_PATH) -lmlx -lXext -lX11 -lm
MLX_PATH = $(MINILIBX_LINUX_PATH)
endif
INCLUDES = -I . -I include -I $(MLX_PATH)

FRACTOL_SRCS = events.c \
				init.c \
				main.c \
				map.c \
				math_utils.c \
				render.c \
				utils.c
FRACTOL_OBJS = $(FRACTOL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(FRACTOL_OBJS) $(UNAME_S)
	 $(CC) $(CFLAGS) $(INCLUDES) $(FRACTOL_OBJS) $(MLXFLAG) -o fractol

$(UNAME_S):
	@$(MAKE) -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(FRACTOL_OBJS)
	@$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re