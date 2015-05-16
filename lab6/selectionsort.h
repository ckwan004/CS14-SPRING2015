#include <iterator>
#include <iostream>
#include <utility>
#include <cassert>

template<typename L>
void selectionsort(L &l)
{
	std::cout << "pre: ";
	for(auto i = l.begin(); i != l.end(); ++i)
		std::cout << " " << *i;
	std::cout << std::endl;

	// actual swap algorithm
	for(auto i = l.begin(); i != l.end(); ++i) {
		auto min = i;
		for(auto j = i; j != l.end(); ++j)
		{
			if(*min > *j) {
				min = j;
			}
		}
		if(min != i)
			std::swap(*min,*i);
	}

	std::cout << "post:";
	for(auto i = l.begin(); i != l.end(); ++i)
		std::cout << " " << *i;
	std::cout << std::endl;
}

template<typename L>
void selectionsort(L &l, bool multi)
{
	assert(multi);
	int move(0);
	int copies(0);

	std::cout << "pre: ";
	for(auto i = l.begin(); i != l.end(); ++i)
		std::cout << " (" << i->first << "," << i->second << ")";
	std::cout << std::endl;

	// actual swap algorithm
	for(auto i = l.begin(); i != l.end(); ++i) {
		auto min = i;
		for(auto j = i; j != l.end(); ++j)
		{
			if(*min > *j) {
				min = j;
			}
		}
		if(min != i) {
			std::swap(*min,*i);
			move += 3;
		}
	}

	std::cout << "post:";
	for(auto i = l.begin(); i != l.end(); ++i)
		std::cout << " (" << i->first << "," << i->second << ")";
	std::cout << std::endl;
	std::cout << copies << " copies and " << move << " moves" << std::endl;	
}

template<typename L>
void selectionsort(L &l, bool multi, bool test)
{
	assert(multi);
	assert(test);
	int move(0);
	int copies(0);

	std::cout << "pre: ";
	for(auto i = l.begin(); i != l.end(); ++i)
		std::cout << " " << i->data;
	std::cout << std::endl;

	// actual swap algorithm
	for(auto i = l.begin(); i != l.end(); ++i) {
		auto min = i;
		for(auto j = i; j != l.end(); ++j)
		{
			if(*min > *j) {
				min = j;
			}
		}
		if(min != i) {
			std::swap(*min,*i);
			move += 3;
		}
	}

	std::cout << "post:";
	for(auto i = l.begin(); i != l.end(); ++i)
		std::cout << " " << i->data;
	std::cout << std::endl;
	std::cout << copies << " copies and " << move << " moves" << std::endl;	
}