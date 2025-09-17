#include "ScalarConverter.h"
#include <cctype>
#include <limits>

// convert function
char convertChar(const std::string& s) {
	return static_cast<char>(s[0]);
}

long convertInt(const std::string& s) {
	char *end = 0;
	long res = std::strtol(s.c_str(), &end, 10);
	return res;
}

double convertDouble(const std::string& s) {
	errno = 0;
	char *end = 0;
	double res = std::strtod(s.c_str(), &end);

	// 不正な文字が入った場合の処理
	// if (*end != '\0') {}
	// オーバーフローアンダーフローの処理
	return static_cast<double>(res);
}

float convertFloat(const std::string& s) {
	double d = convertDouble(s);
	return static_cast<float>(d);
}

float convertPseudoFloat(const std::string& s) {
	if (s == "+inff") return std::numeric_limits<float>::infinity();
	if (s == "-inff") return -std::numeric_limits<float>::infinity();
	return std::numeric_limits<float>::quiet_NaN();
}

double convertPseudoDouble(const std::string& s) {
	if (s == "+inf") return std::numeric_limits<double>::infinity();
	if (s == "-inf") return -std::numeric_limits<double>::infinity();
	return std::numeric_limits<double>::quiet_NaN();
}


void ScalarConverter::convert(const std::string& s) {
    switch (detectType(s)) {
    case T_CHAR: {
        char c = convertChar(s);
        printAll(c);
        break;
    }
    case T_INT: {
		long i = convertInt(s);
		printAll(i);
        break;
    }
    case T_FLOAT: {
        float f = convertFloat(s);
        printAll(f);
        break;
    }
    case T_DOUBLE: {
        double d = convertDouble(s);
        printAll(d);
        break;
    }
    case T_PSEUDO_FLOAT: {
        float f = convertPseudoFloat(s);
        printAll(f, true);
        break;
    }
    case T_PSEUDO_DOUBLE: {
        double d = convertPseudoDouble(s);
        printAll(d, true);
        break;
    }
    default:
        std::cout << "Invalid input\n";
    }
}
