NAME = claptrap

CPPFLAGS = -Wall -Wextra -Werror \
	-std=c++98 #-fsanitize=address

CPP = c++

HEADERS =	ClapTrap.hpp \
			ScavTrap.hpp \
			FragTrap.hpp

SRCS =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp

OBJ_DIR = objects/

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
