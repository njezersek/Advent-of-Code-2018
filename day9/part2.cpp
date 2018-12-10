#include <iostream>
#include <string>
#include <array>
#include <vector>

int main() {
	std::array<long long, 464> players;
	players.fill(0);

	int player = 0;
	int end = 71730*100;
	std::vector<int> marbles;
	std::vector<int>::iterator it;
	marbles.push_back(0);
	int current = 0;
	int counter = 0;

	for (int i = 0; i < end; i++) {
		counter++;
		if (counter % 23 == 0) {
			players[player] += counter;
			int index = (marbles.size() + current - 7) % marbles.size();
			it = marbles.begin() + index;
			players[player] += marbles[index];
			marbles.erase(it);
			current = index;
		}
		else {
			int index = (current + 1) % marbles.size() + 1;
			it = marbles.begin() + index;
			marbles.insert(it, counter);
			current = index;
		}

		player = (player + 1) % players.size();

		if (i % 1000 == 0)std::cout << i << "\n";
	}


	long long result = 0;
	for (int i = 0; i < players.size(); i++) {
		if (players[i] > result)result = players[i];
	}

	std::cout << result;

	std::cin >> result;

	return 0;
}
