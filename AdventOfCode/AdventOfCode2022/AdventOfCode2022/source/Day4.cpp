//header file include.
#include "Day4.h"

//Includes.
#include "Timer.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Day4::Day4() {
	Run();
}

void Day4::Run() {
	//Start code.
	std::cout << "-------------------" << std::endl;
	std::cout << "Day4 code running: " << std::endl;
	Timer timer;

	//Get the input file.
	std::ifstream file("D:\\Github\\AdventOfCode2022\\AdventOfCode\\AdventOfCode2022\\Resources\\day4input.txt");
	std::string line;
	int numPairContainsOther = 0;
	int numOverlaps = 0;
	while (std::getline(file, line)) {
		//Split the string into it's two parts.
		bool onSecondHalf = false;
		std::string firstHalf = "";
		std::string secondHalf = "";
		for (int i = 0; i < line.size(); i++) {
			char character = line[i];
			if (character == ',') {
				onSecondHalf = true;
			}
			else if (!onSecondHalf) {

				firstHalf = firstHalf + character;
			}
			else {
				secondHalf = secondHalf + character;
			}
		}

		//Create arrays of numbers for each elf.
		std::vector<int> elf1;
		Day4::ElfData elf1Data = ParseElf(firstHalf);
		for (int i = elf1Data.min; i <= elf1Data.max; i++) {
			elf1.push_back(i);
		}

		std::vector<int> elf2;
		Day4::ElfData elf2Data = ParseElf(secondHalf);
		for (int i = elf2Data.min; i <= elf2Data.max; i++) {
			elf2.push_back(i);
		}

		//Process line.
		if (OnePairContainsOther(elf1Data, elf2Data, elf1.size() > elf2.size())) {
			numPairContainsOther++;
		}
		if (OnePairOverlaps(elf1Data, elf2Data)) {
			numOverlaps++;
		}
	}

	std::cout << "Number of pairs that contains the other: " << numPairContainsOther << std::endl;
	std::cout << "Number of pairs that overlap: " << numOverlaps << std::endl;
}


bool Day4::OnePairContainsOther(const ElfData& a_elf1, const ElfData& a_elf2, bool elf1Bigger) {
	//Check if the larger array fully contains the smaller array.
	bool containsOther;
	if (elf1Bigger) {
		containsOther = OnePairFullyContainsOther(a_elf1, a_elf2);
	}
	else {
		containsOther = OnePairFullyContainsOther(a_elf2, a_elf1);
	}


	return containsOther;
}

Day4::ElfData Day4::ParseElf(const std::string& a_elfData) {
	ElfData data;

	//Split the input at the '-' character.
	bool onSecondHalf = false;
	std::string firstHalf = "";
	std::string secondHalf = "";
	for (int i = 0; i < a_elfData.size(); i++) {
		char character = a_elfData[i];
		if (character == '-') {
			onSecondHalf = true;
		}
		else if (!onSecondHalf) {
			firstHalf = firstHalf + character;
		}
		else {
			secondHalf = secondHalf + character;
		}
	}

	//Parse the data into ints.
	data.min = std::stoi(firstHalf);
	data.max = std::stoi(secondHalf);
	//std::cout << "min: " << data.min << " max: " << data.max << std::endl;

	return data;
}

bool Day4::OnePairFullyContainsOther(const  ElfData& a_bigger, const  ElfData& a_smaller) {
	if (a_smaller.min >= a_bigger.min && a_bigger.max >= a_smaller.max) {
		return true;
	}


	return false;
}

bool Day4::OnePairOverlaps(const ElfData& a_elf1, const ElfData& a_elf2) {
	const ElfData& elf1 = a_elf1;
	const ElfData& elf2 = a_elf2;
	for (int i = elf1.min; i <= elf1.max; i++) {
		for (int j = elf2.min; j <= elf2.max; j++) {
			if (i == j) {
				return true;
			}
		}
	}

	return false;;
}