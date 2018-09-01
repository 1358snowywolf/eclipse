#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Blocked{
public:
	int billboards(pair<pair<int, int>, pair<int, int>> billboard1, pair<pair<int, int>, pair<int, int>> billboard2, pair<pair<int, int>, pair<int, int>> truck){
		return area(billboard1) + area(billboard2) - covered(billboard1, truck) - covered(billboard2, truck);
	}

private:
	int covered(pair<pair<int, int>, pair<int, int>> billboard, pair<pair<int, int>, pair<int, int>> truck){
		return max(min(billboard.second.second, truck.second.second) - max(billboard.first.second, truck.first.second), 0) *
				max(min(billboard.second.first, truck.second.first) - max(billboard.first.first, truck.first.first), 0);
	}

	int area(pair<pair<int, int>, pair<int, int>> billboard){
		int height = billboard.second.second - billboard.first.second;
		int width = billboard.second.first - billboard.first.first;

		return height * width;
	}
};

int main() {
	ifstream fin("billboard.in");
	ofstream fout("billboard.out");
	int x;
	int y;

	fin >> x;
	fin >> y;
	pair<int, int> x1y1 (x, y);
	fin >> x;
	fin >> y;
	pair<int, int> x2y2 (x, y);
	pair<pair<int, int>, pair<int, int>> billboard1 (x1y1, x2y2);
	fin >> x;
	fin >> y;
	pair<int, int> x3y3 (x, y);
	fin >> x;
	fin >> y;
	pair<int, int> x4y4 (x, y);
	pair<pair<int, int>, pair<int, int>> billboard2 (x3y3, x4y4);
	fin >> x;
	fin >> y;
	pair<int, int> x5y5 (x, y);
	fin >> x;
	fin >> y;
	pair<int, int> x6y6 (x, y);
	pair<pair<int, int>, pair<int, int>> truck (x5y5, x6y6);

	Blocked* ioi = new Blocked();
	int thing = ioi->billboards(billboard1, billboard2, truck);

	fout << thing << endl;
	return 0;
}
