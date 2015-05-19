#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <iostream>
#include <chrono>

int main(int argv, char * argc[])
{
	std::ifstream inFS;
	std::ofstream ouFS;
	inFS.open("words.txt");
	ouFS.open("data.txt");

	if(!inFS.is_open())
		return -1;

	std::vector<std::string> data;
	std::string tempString;
	while(inFS >> tempString)
		data.push_back(tempString);

	int n;
	std::cout << "What is n: ";
	std::cin >> n;
	std::cout << std::endl;

	int nStop(n);
	bool endRun(false);
	std::chrono::duration<double> time_span;
	std::set<std::string> tree;
	std::unordered_set<std::string> htable;
	while(nStop < 50000 || endRun)
	{
  		using namespace std::chrono;
  		ouFS << nStop << " ";

		// tree insert data
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for(int j(0); j < nStop; ++j) {
			tree.insert(data.at(j));
		}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);
		ouFS << time_span.count() << " ";
		
		// hash insert data
		t1 = high_resolution_clock::now();
		for(int j(0); j < nStop; ++j) {
			htable.insert(data.at(j));
		}
		t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);
		ouFS << time_span.count() << " ";
		
		// tree find data
		t1 = high_resolution_clock::now();
		for(int j(0); j < nStop; ++j) {
			tree.find(data.at(j));
		}
		t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);
		ouFS << time_span.count() << " ";
		
		// hash find data
		t1 = high_resolution_clock::now();
		for(int j(0); j < nStop; ++j) {
			htable.find(data.at(j));
		}
		t2 = high_resolution_clock::now();
		time_span = duration_cast<duration<double>>(t2 - t1);
		ouFS << time_span.count() << "\n";

		// ending stuff
		if(nStop < 50000)
			nStop += 5000;
		if(nStop >= 50000 && !endRun)
			endRun = true;
		else if(endRun)
			endRun = false;
	}

	inFS.close();
	ouFS.close();
	return 0;
}