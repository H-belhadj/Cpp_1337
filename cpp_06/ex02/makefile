CXX=c++
SRC = Base.cpp main.cpp A.cpp B.cpp C.cpp
DFS = Base.hpp A.hpp B.hpp C.hpp

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