#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>



size_t split(const std::string &txt, std::vector<std::string> &strs, char ch){
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}

struct Point{
    int x;
    int y;

    Point(int xx, int yy){
        x = xx;
        y = yy;
    }

    Point(std::string s){
        std::vector<std::string> temp;
        split(s, temp, ' ');
        x = std::stoi(temp[0]);
        y = std::stoi(temp[1]);
    }
};

int main()
{
    std::vector<Point> input;
    std::string line;
    while (std::getline(std::cin, line)){
        input.push_back(Point(line));
    }

    int d = 10000;

	int maxx = 1;
	int maxy = 1;
	for(int i=0; i<input.size(); i++){
		if(input[i].x > maxx)maxx = input[i].x;
		if(input[i].y > maxy)maxy = input[i].y;
	}

	int area = 0;
	for(int x = -d-1; x < maxx+d+1; x++){
		for(int y = -d-1; y < maxy+d+1; y++){
			int totald = 0;
			for(int i=0; i<input.size(); i++){
				totald += abs(x-input[i].x) + abs(y-input[i].y);
			}
			if(totald < d)area++;
		}
	}
	std::cout << area;
}
