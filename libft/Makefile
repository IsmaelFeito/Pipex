NAME = libft.a
BONUS_NAME = .bonus

SOURCES =		ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c \
				ft_atoi.c ft_isprint.c ft_striteri.c ft_strnstr.c \
				ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
				ft_calloc.c ft_memchr.c ft_strlcat.c ft_strtrim.c \
				ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
				ft_isalpha.c ft_memcpy.c ft_strlen.c ft_tolower.c ft_split.c \
				ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c freedom.c \
				ft_sqrt.c ft_split_pipex.c ft_cleaner.c

OBJECTS = $(SOURCES:.c=.o)

BONUSS =		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

BONUS_OBJS = $(BONUSS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3
REMOVE = rm -f
CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

bonus: $(BONUS_NAME)

clean:
	$(REMOVE) $(OBJECTS) $(BONUS_OBJS)

fclean: clean
	$(REMOVE) $(NAME) $(BONUS_NAME)

re: fclean all

$(BONUS_NAME): $(OBJECTS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJS)
	ar rcs $(BONUS_NAME) $(OBJECTS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus