CXX=c++
SRC = main.cpp 
DFS = Array.hpp Array.tpp

OSRC=$(SRC:.cpp=.o)
NAME=Array
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OSRC) 
	@$(CXX) $(CFLAGS) $(OSRC) -o $@

%.o : %.cpp $(DFS)
	@$(CXX) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OSRC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

