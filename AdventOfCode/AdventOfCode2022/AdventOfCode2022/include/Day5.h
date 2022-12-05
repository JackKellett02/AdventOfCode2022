#ifndef _DAY5_H_
#define _DAY5_H_

#include <stack>
#include <vector>
#include <string>

class Day5 {
public:

	//Constructor
	Day5();

	//Functions.

	//Public Variables.

	//Structs.
	struct MoveInstruction {
		int numToMove;
		int firstStack;
		int secondStack;
	};

private:
	//Private Variables.
	std::stack<char> s1;
	std::stack<char> s2;
	std::stack<char> s3;
	std::stack<char> s4;
	std::stack<char> s5;
	std::stack<char> s6;
	std::stack<char> s7;
	std::stack<char> s8;
	std::stack<char> s9;

	//Private Functions.
	void Run();
	void AddDataToStack(char data, int a_stackCounter);
	void MoveDataFromStackAtoB(std::stack<char>& a_startStack, std::stack<char>& a_endStack, const int& numToMove);
	std::stack<char>& GetStackFromNumber(const int& number);
	MoveInstruction ParseMoveInstructions(const std::string& a_instruction);
};

#endif // !_DAY5_H_
