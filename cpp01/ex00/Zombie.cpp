



#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Zombie " << this->name << " is alive." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " is dead." << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}