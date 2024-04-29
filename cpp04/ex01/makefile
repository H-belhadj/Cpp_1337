CXX=c++
SRC = Animal.cpp brain.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp 
DFS = Animal.hpp brain.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp 

OSRC=$(SRC:.cpp=.o)
NAME= Brain
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

all: $(NAME)

$(NAME):$(OSRC) 
	@$(CXX) $(CFLAGS) $(OSRC) -o $@

%.o : %.cpp $(DFS)
	@$(CXX) $(CFLAGS) -c $<

clean:
	@rm -rf $(OSRC)

fclean: clean
	@rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re