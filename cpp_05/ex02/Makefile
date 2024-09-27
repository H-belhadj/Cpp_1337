CXX=c++
SRC = AForm.cpp main.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
DFS = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

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