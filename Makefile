NAME		=	containers

SRCS	=	./tester/test_vector.cpp ./tester/main.cpp ./tester/test_list.cpp ./tester/test_queue.cpp \
				./tester/test_stack.cpp ./tester/test_map.cpp

CC		=	clang++

SANI	=	-fsanitize=address -g3

CPP1FLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.cpp=.o)

RM		= rm -rf

all	:	$(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

c1	:
		$(CC) -o $(NAME) $(OBJS) $(SRCS)

s1	:
		$(CC) -o $(NAME) $(SANI) $(SRCS)

w1	:
		$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	clean fclean all c1 s1 w1
