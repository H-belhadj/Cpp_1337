



#include "Zombie.hpp"

Zombie::Zombie( void ){}


Zombie::~Zombie()
{
    std::cout << this->name << ": IS DEAD" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}