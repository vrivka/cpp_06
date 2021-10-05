NAME = serialize_test

SRCS =	serialize.cpp \
        deserialize.cpp \
        main.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -std=c++98 -Wall -Werror -Wextra

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
		clang++ $(CFLAGS) -o $(NAME) $^

%.o:	%.cpp
		clang++ $(CFLAGS) -c $< -o $@ -I.

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all bonus clean fclean re