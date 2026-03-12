NAME		=	sudoku

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	main.c sudoku.c check.c

all:			$(NAME)

$(NAME):
				gcc	$(CFLAGS) $(SRCS) -o $(NAME)

fclean:
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all fclean re