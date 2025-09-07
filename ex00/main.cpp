#include "ScalarConverter.h"


int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./convert <literal>" <<std::endl;
		return 1;
	}
	std::string s = argv[1];
	ScalarConverter::convert(s);
	return 0;
}
