#include "FrameworkImplementation.h"

int main(int argc, char* argv[])
{


	int enemies = 10, amo = 10, width = 800, height = 800;
	run(new FrameworkImplementation(enemies, amo, width, height));

	std::cin.get();
	return 0;
}