

#include "Zombie.hpp"
int	main(void)
{
	Zombie *z = zombieHorde(50, "SPIDER MAN");
	if (z)
	{
		for (int i = 0; i < 50 ; i++)
			z[i].announce();
		delete [] z;
	}
	return 0;
}