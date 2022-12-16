SRCS	=	pipex.c utils.c libft/ft_split.c \
			libft/ft_strjoin.c libft/ft_strlen.c \
			libft/ft_strnstr.c libft/ft_strchr.c \
			libft/ft_split_quote.c libft/ft_split_doublequote.c
SRCS_BONUS = pipex_bonus.c utils.c utils_bonus.c libft/ft_split.c \
			libft/ft_strjoin.c libft/ft_strlen.c \
			libft/ft_strnstr.c libft/ft_strchr.c \
			libft/ft_split_quote.c libft/ft_split_doublequote.c \
			libft/ft_strncmp.c libft/ft_putstr_fd.c

NAME = pipex
NAME_BONUS = pipex_bonus
CC	= gcc
RM	= rm -f
INCLUDES	= -I pipex.h
CFLAGS 	= -Wall -Wextra -Werror
${NAME}:	${OBJS}
			${CC} -o  ${NAME} ${INCLUDES} ${CFLAGS} ${SRCS}
bonus : 	
			${CC} -o  ${NAME_BONUS} ${INCLUDES} ${CFLAGS} ${SRCS_BONUS}
all:		${NAME}
clean:
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME} ${NAME_BONUS}
re:	fclean all
.PHONY: all clean fclean re bonus

