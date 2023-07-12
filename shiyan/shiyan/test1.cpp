#include <iostream>

#include <random>
#include <vector>



struct persons
{
	bool exist = 0;
	int ability = 0;
	int rich = 0;
};

struct opportunity
{
	bool type;
	bool exist=0;
};
int main() {

	long total = 0;

	//persons map[100][100];
	persons* map = (persons*)malloc(sizeof(persons) * 10000);
	//persons* map = (persons*)new persons[100][100];

	std::random_device rd;  // a seed source for the random number engine
	std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(0, 9999);
	std::uniform_int_distribution<> distrib_ability(1, 9);
	std::uniform_int_distribution<> distrib_oppo(0, 1);

	std::seed_seq seed2{ rd() };
	std::mt19937 e2(seed2);
	std::normal_distribution<> normal_dist(5, 1);
	std::normal_distribution<> normal_rich(500, 30);
	
	for (int i = 0; i < 1000; i++) {
		int coord = distrib(gen);
		//int x = coord / 100;
		//int y = coord % 100;
		while (map[coord].exist)
		{
			coord = distrib(gen);
			//x = coord / 100;
			//y = coord % 100;
		}
		map[coord].exist = 1;
		map[coord].ability = std::round(normal_dist(e2));
		map[coord].rich = std::round(normal_rich(e2));
		total += std::round(normal_rich(e2));
	}

	
	for (int i = 0; i < 30; i++)
	{
		opportunity* oppo = (opportunity*) new opportunity[10000];
		for (int j = 0; j < 1000; j++)
		{
			int coord = distrib(gen);
			if (!map[coord].exist)
			{
				coord = distrib(gen);
			}
			oppo
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			std::cout << distrib(gen) << std::endl;
	}

	
	





	return 0;
}