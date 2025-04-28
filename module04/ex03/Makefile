NAME = AMateria

CPPFLAGS = -Wall -Wextra -Werror \
	-std=c++98 #-fsanitize=address

CPP = c++

HEADERS =	Ice.hpp \
			Cure.hpp \
			AMateria.hpp \
			Character.hpp \
			ICharacter.hpp \
			MateriaSource.hpp \
			IMateriaSource.hpp \

SRCS =	Ice.cpp \
		main.cpp \
		Cure.cpp \
		AMateria.cpp \
		Character.cpp \
		MateriaSource.cpp \

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
