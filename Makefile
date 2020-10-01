NAME		=	containers_tester

SRCS	=	./tester/test_vector.cpp ./tester/main.cpp ./tester/test_list.cpp ./tester/test_queue.cpp \
				./tester/test_stack.cpp ./tester/test_map.cpp

CC		=	clang++

SANI	=	-fsanitize=address -g3

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

OBJS	=	$(SRCS:.cpp=.o)

RM		= rm -rf

all	:	$(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

c	:
		$(CC) -o $(NAME) $(OBJS) $(SRCS)

s	:
		$(CC) -o $(NAME) $(SANI) $(SRCS)

w	:
		$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	clean fclean all c s w
