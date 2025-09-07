#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <iostream>
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
#endif
