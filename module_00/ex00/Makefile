NAME = megaphone

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

CPP = c++

SRCS = megaphone.cpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
