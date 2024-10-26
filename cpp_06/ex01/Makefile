CXX=c++
SRC = Serializer.cpp main.cpp
DFS = Serializer.hpp

OSRC=$(SRC:.cpp=.o)
NAME= Serializer
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