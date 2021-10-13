NAME = type_info

HEADER = A.hpp \
         B.hpp \
         Base.hpp \
         C.hpp

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -std=c++98 -Wall -Werror -Wextra

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
		clang++ $(CFLAGS) -o $(NAME) $(OBJS)

%.o:	%.cpp
		clang++ $(CFLAGS) -c $< -o $@ -I.

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all bonus clean fclean re