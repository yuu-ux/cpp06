#include "ScalarConverter.h"
#include <cmath>
#include <limits>

bool ft_isfinite(double x) {
	return !std::isnan(x) && !std::isinf(x);
}

// print function
void printChar(char value) {
	std::cout << "char: ";
	if (std::isprint(value)) {
		std::cout << "'" << value << "'" << std::endl;
	} else {
		std::cout << "Non displayable" << std::endl;
	}
}

void printInt(long value) {
	if (!ft_isfinite(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void printFloat(float value) {
	std::cout << "float: " << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void printDouble(double value) {
	std::cout << "double: " << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}

void printAll(char c) {
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void printAll(long c) {
	printChar(static_cast<char>(c));
	printInt(c);
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void printAll(float c, bool wasPseudo) {
	if (!wasPseudo) {
		printChar(static_cast<char>(c));
		printInt(static_cast<int>(c));
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	printFloat(c);
	printDouble(static_cast<double>(c));
}

void printAll(double c, bool wasPseudo) {
	if (!wasPseudo) {
		printChar(static_cast<char>(c));
		printInt(static_cast<int>(c));
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	printFloat(static_cast<float>(c));
	printDouble(c);
}

