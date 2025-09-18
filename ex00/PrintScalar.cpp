#include "ScalarConverter.h"
#include <cmath>
#include <limits>

const int ASCII_PRINTABLE_MIN = 32;
const int ASCII_PRINTABLE_MAX = 126;
bool ft_isfinite(double x) {
	return !std::isnan(x) && !std::isinf(x);
}

// print function
void printChar(int value) {
	std::cout << "char: ";
	if (value >= ASCII_PRINTABLE_MIN && value <= ASCII_PRINTABLE_MAX) {
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	} else if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
		std::cout << "impossible" << std::endl;
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

void printFloat(double value) {
	std::cout << "float: ";
	if (!ft_isfinite(value)) {
		std::cout << static_cast<float>(value) << 'f' << std::endl;
		return ;
	}

	const double fmax = std::numeric_limits<float>::max();
	if (value > fmax || value < -fmax)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	std::cout << static_cast<float>(value);
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void printDouble(double value) {
	std::cout << "double: ";
	if (!ft_isfinite(value)) {
		std::cout << static_cast<double>(value) << std::endl;;
		return ;
	}

	const double dmax = std::numeric_limits<double>::max();
	if (value > dmax || value < -dmax)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	std::cout << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}

void printAll(char c) {
	printChar(static_cast<int>(c));
	printInt(static_cast<long>(c));
	printFloat(static_cast<double>(c));
	printDouble(static_cast<double>(c));
}

void printAll(long c) {
	printChar(static_cast<int>(c));
	printInt(c);
	printFloat(static_cast<double>(c));
	printDouble(static_cast<double>(c));
}

void printAll(double c, bool wasPseudo) {
	if (!wasPseudo) {
		printChar(static_cast<int>(c));
		printInt(static_cast<long>(c));
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	printFloat(c);
	printDouble(c);
}
