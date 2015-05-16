#include <iostream>
#include <utility>
#include <vector>
#include "selectionsort.h"

class UniqueDataInt
{
private:
	static unsigned int identifier;
public:
	unsigned int id;
	int data;
	UniqueDataInt(int val) : id(identifier), data(val) {++identifier;}

	bool operator>(const UniqueDataInt& otherVal) {
		if(data > otherVal.data)
			return true;
		return false;
	}
};

unsigned int UniqueDataInt::identifier = 1;

int main()
{
	std::vector<int> data = {2,4,5,1,8,9};
	std::vector<std::pair<int,int>> data2 = {std::pair<int,int>(1,2), std::pair<int,int>(3,-1),std::pair<int,int>(-1,3),std::pair<int,int>(0,0),std::pair<int,int>(2,3),std::pair<int,int>(1,2),std::pair<int,int>(1,-2),std::pair<int,int>(8,10)};
	std::vector<std::pair<int,int>> data3 = {std::pair<int,int>(10,2), std::pair<int,int>(-3,-1), std::pair<int,int>(-8,0), std::pair<int,int>(1,1) ,std::pair<int,int>(1,1) ,std::pair<int,int>(0,0) , std::pair<int,int>(10,2) ,std::pair<int,int>(5,5) ,std::pair<int,int>(5,-5) , std::pair<int,int>(0,0), std::pair<int,int>(10,2)};
	std::vector<std::pair<int,int>>data4 = {std::pair<int,int>(-1,3) , std::pair<int,int>(0,0) , std::pair<int,int>(1,-2) , std::pair<int,int>(1,2) , std::pair<int,int>(1,2) , std::pair<int,int>(2,3) , std::pair<int,int>(3,-1) , std::pair<int,int>(8,10)};
	
	//create a unqiue data thing
	std::vector<UniqueDataInt> data5 = {
		/* makes id = 01 */UniqueDataInt(9),
		/* makes id = 02 */UniqueDataInt(9),
		/* makes id = 03 */UniqueDataInt(8),
		/* makes id = 04 */UniqueDataInt(8),
		/* makes id = 05 */UniqueDataInt(7),
		/* makes id = 06 */UniqueDataInt(7),
		/* makes id = 07 */UniqueDataInt(6),
		/* makes id = 08 */UniqueDataInt(6),
		/* makes id = 09 */UniqueDataInt(5),
		/* makes id = 10 */UniqueDataInt(5),
		/* makes id = 11 */UniqueDataInt(4),
		/* makes id = 12 */UniqueDataInt(4),
		/* makes id = 13 */UniqueDataInt(3),
		/* makes id = 14 */UniqueDataInt(3),
		/* makes id = 15 */UniqueDataInt(2),
		/* makes id = 16 */UniqueDataInt(2),
		/* makes id = 17 */UniqueDataInt(1),
		/* makes id = 18 */UniqueDataInt(1)
	};
	// id order should become 17,18,15,16,13,14,11,12,9,10,7,8,5,6,3,4,1,2 to be stable
	selectionsort<std::vector<int>>(data);
	selectionsort<std::vector<std::pair<int,int>>>(data2, true);
	selectionsort<std::vector<std::pair<int,int>>>(data3, true);
	selectionsort<std::vector<std::pair<int,int>>>(data4, true);
	

	std::cout << "Id Order of Data5 Before:";
	for(auto i(data5.begin()); i != data5.end(); ++i)
	{
		std::cout << " " << i->id;
	} std::cout << std::endl;
	selectionsort<std::vector<UniqueDataInt>>(data5,true,true);
	//prints out the id of UniqeueData
	std::cout << "Id Order of Data5 After:";
	for(auto i(data5.begin()); i != data5.end(); ++i)
	{
		std::cout << " " << i->id;
	} std::cout << std::endl;

	return 0;
}