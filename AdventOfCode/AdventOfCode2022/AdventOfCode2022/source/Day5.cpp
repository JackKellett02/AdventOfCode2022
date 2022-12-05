//CPP header file.
#include "Day5.h"

//Includes.
#include "Timer.h"
#include <fstream>
#include <iostream>
#include <vector>


Day5::Day5() {
	Run();
}

void Day5::Run() {
	//Start code.
	std::cout << "-------------------" << std::endl;
	std::cout << "Day5 code running: " << std::endl;
	Timer timer;

	//Get the input file.
	std::ifstream file("D:\\Github\\AdventOfCode2022\\AdventOfCode\\AdventOfCode2022\\Resources\\day5input.txt");
	std::string line;
	std::vector<std::string> instructions;


	while (std::getline(file, line)) {
		//Construct the stacks.
		//std::cout << line << std::endl;

		if (line.empty()) {
			continue;
		}
		else if (line[0] == 'm') {
			//Add to the set of instructions.
			instructions.push_back(line);
		}
		else if (line[1] != '1') {
			//Parse the stack data.
			int stackCounter = 1;
			for (int i = 1; i < line.size(); i += 4) {
				if (line[i] != ' ') {
					AddDataToStack(line[i], stackCounter);
				}
				stackCounter++;
			}
		}

	}


	//Parse the instructions.
	for (int i = 0; i < instructions.size(); i++) {
		MoveInstruction instruction = ParseMoveInstructions(instructions[i]);
		MoveDataFromStackAtoB(
			GetStackFromNumber(instruction.firstStack),
			GetStackFromNumber(instruction.secondStack),
			instruction.numToMove);
	}


	//Output crate at the top of each stack.
	std::cout << "s1 top: " << s1.top() << std::endl;
	std::cout << "s2 top: " << s2.top() << std::endl;
	std::cout << "s3 top: " << s3.top() << std::endl;
	std::cout << "s4 top: " << s4.top() << std::endl;
	std::cout << "s5 top: " << s5.top() << std::endl;
	std::cout << "s6 top: " << s6.top() << std::endl;
	std::cout << "s7 top: " << s7.top() << std::endl;
	std::cout << "s8 top: " << s8.top() << std::endl;
	std::cout << "s9 top: " << s9.top() << std::endl;
}

void Day5::AddDataToStack(char data, int a_stackCounter) {
	switch (a_stackCounter)
	{
	case 1:
		s1.push(data);
		break;
	case 2:
		s2.push(data);
		break;
	case 3:
		s3.push(data);
		break;
	case 4:
		s4.push(data);
		break;
	case 5:
		s5.push(data);
		break;
	case 6:
		s6.push(data);
		break;
	case 7:
		s7.push(data);
		break;
	case 8:
		s8.push(data);
		break;
	case 9:
		s9.push(data);
		break;
	default:
		std::cout << "ERROR: STACK COUNTER WAS OUT OF RANGE" << std::endl;
		break;
	}

}

void Day5::MoveDataFromStackAtoB(std::stack<char>& a_startStack, std::stack<char>& a_endStack, const int& numToMove) {
	for (int i = 0; i < numToMove; i++) {
		if (a_startStack.empty()) {
			return;
		}
		//Get the next character.
		char character = a_startStack.top();
		a_startStack.pop();

		//Move the character to the new stack.
		a_endStack.push(character);
	}
}

std::stack<char>& Day5::GetStackFromNumber(const int& number) {
	switch (number)
	{
	case 1:
		return s1;
		break;
	case 2:
		return s2;
		break;
	case 3:
		return s3;
		break;
	case 4:
		return s4;
		break;
	case 5:
		return s5;
		break;
	case 6:
		return s6;
		break;
	case 7:
		return s7;
		break;
	case 8:
		return s8;
		break;
	case 9:
		return s9;
		break;
	default:
		std::cout << "ERROR: STACK COUNTER WAS OUT OF RANGE" << std::endl;
		break;
	}
}

Day5::MoveInstruction Day5::ParseMoveInstructions(const std::string& a_instruction) {
	MoveInstruction instruction;

	//Split the string at the space character.
	int counter = 0;
	std::string newString = "";
	std::vector<std::string> instructionData;
	bool pushAfterNewString = false;
	for (int i = 0; i < a_instruction.size(); i++) {
		if (a_instruction[i] == ' ') {
			counter++;
			instructionData.push_back(newString);
			pushAfterNewString = newString == "to";
			newString = "";
		}
		else {
			newString = newString + a_instruction[i];
			if (pushAfterNewString) {
				instructionData.push_back(newString);
			}
		}
	}

	instruction.numToMove = std::stoi(instructionData[1]);
	instruction.firstStack = std::stoi(instructionData[3]);
	instruction.secondStack = std::stoi(instructionData[5]);

	return instruction;
}