NAME = pipex

SRC = 

CFLAGS = -Werror -Wall -Wextra

CC = cc

all: ${NAME}
		${NAME} ${SRC} 

clean: ${CC} 

re: ${NAME} $

.PHONY: all re clean fclean