#include <iostream>
#include <ctime>
#include "../Utils/Utils.h"
using namespace std;

int main(int argc, char *argv[])
{
	char cArray[] = {'a', 'b', 'c', 'd', 'e'};
	int iArray[] = {1, 2, 3, 4, 5};

	ReverseArray(cArray,0,4,5);
	PrintArray(cArray,5);

	ReverseArray(iArray,0,4,5);
	PrintArray(iArray,5);
}
