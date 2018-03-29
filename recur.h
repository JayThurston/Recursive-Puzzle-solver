
/**********************
RecursivePuzzleSolver.h
********
**************/
#pragma once
#include <vector>
using namespace std;
class RecursivePuzzleSolver
{
private:
vector<int> puzzle;
// stores the puzzle as passed in by user
vector<char> solution;
// stores the solution to the puzzle if solvable

bool solvable(unsigned int top, vector<int>& puzzle, vector<bool> unused);
void printRow(const vector<int> & puzzle, unsigned int);
public:
RecursivePuzzleSolver(vector<int> &);
~RecursivePuzzleSolver();
bool solvable(unsigned int top, vector<int>& puzzle);
void printPuzzle(const vector<int> &);
};

RecursivePuzzleSolver::RecursivePuzzleSolver(vector<int> & puzzle)
{
	cout<<"Enter a list of numbers (enter 0 to end)";
	int input;
	cin>>input;

	while (input > 0)
	{
	puzzle.push_back(input);
	cin>>input;
	}
	puzzle.push_back(0);
	cout<<endl;
}
void RecursivePuzzleSolver::printRow(const vector<int> & puzzle, unsigned int x)
{
	for (unsigned int i=0; i < puzzle.size(); i++){
		if (x==puzzle[i+1])
		{
			cout<<"[";
			cout<<puzzle[i];
			cout<<"]"<<" ";
			}
		if(x!=puzzle[i+1])
			{
			cout<<puzzle[i]<<" ";
			}
		}
		cout<<endl;
}

void RecursivePuzzleSolver::printPuzzle(const vector<int> & puzzle)
{


	for (unsigned int i=0; i < solution.size(); i++){
			cout<<solution[i]<<" ";
		}
	cout<<endl;
	}

RecursivePuzzleSolver::~RecursivePuzzleSolver()
{
}

bool RecursivePuzzleSolver::solvable(unsigned int top, vector<int> & puzzle, vector<bool> unused)
{
	if (top == puzzle.size())
	{
		return true;
	}

	unsigned int left = top - puzzle[top-1];
	if  (left > 0 && puzzle[left-1]){
		unused[left-1] = false;
		if (solvable(left,puzzle,unused))
		{
			printRow(puzzle,left);
			solution.push_back('L');
			return true;
		}
	}

	unsigned int right = top + puzzle[top-1];

		if  (right <= puzzle.size() && unused[right-1]){
			unused[right-1] = false;
			if (solvable(right,puzzle,unused))
			{
				printRow(puzzle,right);
				solution.push_back('R');
				return true;
			}
		}
		return false;
}

bool RecursivePuzzleSolver::solvable(unsigned int top, vector<int>& puzzle)
{
	vector<bool> unused;
	for (unsigned int i=0; i < puzzle.size(); i++ )
	{
	unused.push_back(true);
	}
	return solvable(top, puzzle, unused);
}


