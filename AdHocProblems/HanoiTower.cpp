#include <iostream>
using namespace std;

/*
3 pegs - A B C 
A: From Peg, B - Aux Peg, C - To peg
N Disks placed in the ascending order on peg A
At anypoint of time, the discs on any of the pegs shoudld 
be in the ascending order.
Move all the disks from A to C
*/

// A , B , C
void TowerOfHanoi(int n, char fromPeg, char auxPeg, char toPeg)
{
	// base condition : move fromPeg to toPeg
	if (n == 1)
	{
		cout << "Move Disk " << n << " from " <<fromPeg << " to " << toPeg << endl; 
		return;
	}
	// Move n-1 discs from A to B using C
	TowerOfHanoi(n-1, fromPeg, toPeg, auxPeg);
	//Move nth disc from A to C
	cout << "Move Disk " << n << " from " <<fromPeg << " to " << toPeg << endl;
	//Moev the pegs from B to A using C
	TowerOfHanoi(n-1,auxPeg,fromPeg,toPeg);
}

int main()
{
	TowerOfHanoi(3,'A','B','C');
	return 0;
}



