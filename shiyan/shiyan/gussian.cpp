#include <iostream>
#include <random>

void gussian() {
	std::random_device r;
	std::seed_seq seed2{ r() };
	std::mt19937 e2(seed2);
	std::normal_distribution<> normal_dist(5, 1);

	int a[9] = { 0 };

	for (int i = 0; i < 1000; i++) {
		int res = std::round(normal_dist(e2));
		if (res <= 0)
			res = 0;
		if (res >= 9)
			res = 9;
		a[res]++;
	}
	for (int i = 0; i < 9; i++) {
		std::cout << i << " : ";
		for (int j = 0; j < a[i]; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}

}