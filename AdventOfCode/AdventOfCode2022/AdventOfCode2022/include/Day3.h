#ifndef _DAY3_H_
#define _DAY3_H_

#include <string>

class Day3 {
public:
	//Constructor
	Day3();

	//Functions.

	//Public Variables.

private:
	//Private Variables.
	

	//Private Functions.
	void Run();
	int ConvertCharToPriority(const char& a_char);
	char FindCommonCharacter(const std::string& a_string1, const std::string& a_string2, const std::string& a_string3);
};


#endif // !_DAY3_H_
