



#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string  name)
{
    Zombie  *Z = new Zombie[N];
    int i = 0;
    while(i < N)
    {
        Z[i].setName(name);
        i++;
    }
    return (Z);
}