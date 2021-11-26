#include <iostream>
#include <ctime>
#include "../Utils/Utils.h"
using namespace std;

/*Find an efficient algorithm to rotate an array to k-positions to right*/
void shiftArrayRight(int arr[], int size, int positions)
{
	ReverseArray(arr,0,size -1,size);
	ReverseArray(arr,0,positions -1,size);
	ReverseArray(arr,positions,size-1,size);
}

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	int *a = new int[n];
	for(int i = 0; i <n; i++)
		a[i] = i+1;
	time_t start, end;
	time(&start);
	shiftArrayRight(a,n,n-1);
	time(&end);
	cout << "Time taken:" << to_string(difftime(end,start)) << "secs" << endl;
	return 0;
}
