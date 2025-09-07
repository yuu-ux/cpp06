#include "ScalarConverter.h"
#include <cctype>
#include <limits>

// convert function
char convertChar(const std::string& s) {
	return static_cast<char>(s[0]);
}

int convertInt(const std::string& s) {
	errno = 0;
	char *end = 0;
	long res = std::strtol(s.c_str(), &end, 10);

	// 不正な文字が入っていた場合の処理
	// if (*end != '\0') {
	//
	// }

	// オーバーフローしたときの処理
	// if (errno =- ERANGE || v < INT_MIN || v > INT_MAX) {
	//
	// }
	return static_cast<int>(res);
}

int convertDouble(const std::string& s) {
	errno = 0;
	char *end = 0;
	double res = std::strtod(s.c_str(), &end);

	// 不正な文字が入った場合の処理
	// if (*end != '\0') {}
	// オーバーフローアンダーフローの処理
	return static_cast<double>(res);
}

int convertFloat(const std::string& s) {
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

// print function
// void printAll(char c) {}
// void printAll(int c) {}
// void printAll(double c) {}
// void printAll(float c) {}

void ScalarConverter::convert(const std::string& s) {
    switch (detectType(s)) {
    case T_CHAR: {
        char c = convertChar(s);
		std::cout << c << std::endl;
        // printAll(c);
        break;
    }
    case T_INT: {
        int i = convertInt(s);
		std::cout << i << std::endl;
        // printAll(i);
        break;
    }
    case T_FLOAT: {
        float f = convertFloat(s);
		std::cout << f << 'f' << std::endl;
        // printAll(f);
        break;
    }
    case T_DOUBLE: {
        double d = convertDouble(s);
		std::cout << "double: " << d << std::endl;
        // printAll(d);
        break;
    }
    case T_PSEUDO_FLOAT: {
        float f = convertPseudoFloat(s);
		std::cout << f << std::endl;
        // printAll(f, /*wasPseudo=*/true);
        break;
    }
    case T_PSEUDO_DOUBLE: {
        double d = convertPseudoDouble(s);
		std::cout << d << std::endl;
        // printAll(d, /*wasPseudo=*/true);
        break;
    }
    default:
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
    }
}
