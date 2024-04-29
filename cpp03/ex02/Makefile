CXX=c++
SRC = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp
DFS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

OSRC=$(SRC:.cpp=.o)
NAME= FragTrap
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):$(OSRC) 
	@$(CXX) $(CFLAGS) $(OSRC) -o $@

%.o : %.cpp $(DFS)
	@$(CXX) $(CFLAGS) -c $<

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o $(NAME)

re:fclean all

.PHONY: all clean fclean re