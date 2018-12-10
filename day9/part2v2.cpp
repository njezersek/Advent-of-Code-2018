#include <iostream>
#include <string>
#include <array>
#include <list>

int main() {
	//std::array<long long, 464> players;
	std::array<long long, 464> players;
	players.fill(0);

	int player = 0;
	int end = 71730*100;
	std::list<int> marbles;
	std::list<int>::iterator current = marbles.begin();
  std::list<int>::iterator tmp;
	marbles.push_back(0);
	int counter = 0;

	for (int i = 0; i < end; i++) {
		counter++;
		if (counter % 23 == 0) {
			players[player] += counter;
			//int index = (marbles.size() + current - 7) % marbles.size();
			//it = marbles.begin() + index;
      for(int j=0; j<7; j++){
        current--;
        if(current == marbles.end())current--;
      }
      current--;
      players[player] += *current;
      current++;
      tmp = current;
      current++;
			marbles.erase(tmp);
		}
		else {
			current++;
			if(current == marbles.begin())current++;
			marbles.insert(current, counter);
		}

		player = (player + 1) % players.size();
		//std::list<int>::iterator it;
		//for (it = marbles.begin(); it != marbles.end(); it++)std::cout << *it << " ";
		//std::cout << "  - " << *current << "\n";
		//if (i % 1000 == 0)std::cout << i << "\n";
	}


	long long result = 0;
  //std::cout << "\n";
	for (int i = 0; i < players.size(); i++) {
    //std::cout << players[i] << " ";
		if (players[i] > result)result = players[i];
	}
  //std::cout << "\n";
	std::cout << result << "\n";

	return 0;
}
