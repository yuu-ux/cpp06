#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <cerrno>

class ScalarConverter {
	public:
		static void convert(const std::string& s);
		enum Type {
			T_CHAR,
			T_INT,
			T_FLOAT,
			T_DOUBLE,
			T_PSEUDO_FLOAT,
			T_PSEUDO_DOUBLE,
			T_INVALID
		};

	private:
		ScalarConverter();
		static Type detectType(const std::string& s);
};

void printAll(char c);
void printAll(long c);
void printAll(float c, bool wasPseudo=false);
void printAll(double c, bool wasPseudo=false);

#endif
