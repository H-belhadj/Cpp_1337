CXX=c++
SRC = Bureaucrat.cpp main.cpp Form.cpp
DFS = Bureaucrat.hpp Form.hpp

OSRC=$(SRC:.cpp=.o)
NAME= BrainBureaucrat
CFLAGS = -Wall -Wextra -Werror -std=c++98 

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