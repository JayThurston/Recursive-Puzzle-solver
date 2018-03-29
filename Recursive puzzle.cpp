

#include <iostream>
#include <vector>
#include "recur.h"
using namespace std;
int main()
{
vector<int> puzzle;
RecursivePuzzleSolver game(puzzle);

if (game.solvable(1,puzzle))
	game.printPuzzle(puzzle);
else
	cout<<"Not a solvable puzzle"<<endl;
return 0;
}
