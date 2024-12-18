



#include "Zombie.hpp"

int	main(void)
{
		Zombie	*z1 = newZombie("Spider_Man");
		z1->announce();
		delete z1;
		randomChump("Iron_man");
		return (0);
}
