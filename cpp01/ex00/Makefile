CXX=c++
SRC = newZombie.cpp randomChump.cpp main.cpp Zombie.cpp
DFS = Zombie.hpp 

OSRC=$(SRC:.cpp=.o)
NAME= zombie
CFLAGS = -Wall -Wextra -Werror -std=c++98

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m


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