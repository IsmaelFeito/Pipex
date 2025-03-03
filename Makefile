NAME = pipex

SRC = 	src/pipex.c \
		src/pipex_utils.c \
		src/pipex_utils2.c

RM = rm -rf
CFLAGS = -Werror -Wall -Wextra -g3 -fsanitize=address
CC = cc
LIBFT = libft.a
LIBFT_PATH = libft/

OBJS_P = ${SRC:.c=.o}

all: ${NAME}
		
${NAME}: ${OBJS_P} ${LIBFT_PATH}${LIBFT}
	@${CC} ${CFLAGS} ${OBJS_P} ${LIBFT_PATH}${LIBFT} -o ${NAME}

${LIBFT_PATH}${LIBFT}:
	@make bonus -C ${LIBFT_PATH} --silent

clean:
	@${RM} ${OBJS_P}
	@make fclean -C ${LIBFT_PATH}

fclean: clean
	@${RM} ${NAME} ${LIBFT_PATH}${LIBFT}

re: fclean all

.PHONY: all re clean fclean
