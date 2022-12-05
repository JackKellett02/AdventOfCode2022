#ifndef _DAY4_H_
#define _DAY4_H_

#include <string>
#include <vector>

class Day4 {
public:

	//Constructor
	Day4();

	//Functions.

	//Public Variables.

	//Structs.
	struct ElfData {
		int min;
		int max;
	};
private:
	//Private Variables.


	//Private Functions.
	void Run();
	bool OnePairContainsOther(const ElfData& a_elf1, const ElfData& a_elf2, bool elf1Bigger);
	bool OnePairFullyContainsOther(const ElfData& a_bigger, const ElfData& a_smaller);
	bool OnePairOverlaps(const ElfData& a_elf1, const ElfData& a_elf2);
	Day4::ElfData ParseElf(const std::string& a_elfData);

};

#endif // !_DAY4_H_
