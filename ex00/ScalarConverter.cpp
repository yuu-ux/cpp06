#include "ScalarConverter.h"
#include <cctype>

std::string trim(const std::string& s) {
	size_t start = 0;
	size_t end = s.size();

	while (start < s.size() && std::isspace(s[start])) { start++; }

	while (end > start && std::isspace(s[end-1])) { end--; }
	return s.substr(start, end-start);
}

bool isPseudoFloat(const std::string& s) {
	return (s == "-inff" or s == "+inff" or s == "nanf");
}

bool isPseudoDouble(const std::string& s) {
	return (s == "-inf" or s == "+inf" or s == "nan");
}

bool isChar(const std::string& s) {
	if (s.size() == 1) {
		unsigned char c = static_cast<unsigned char>(s[0]);
		return (std::isprint(c) && !std::isdigit(c));
	}
	return false;
}

bool isSign(int ch) { return (ch == '+' or ch == '-');}

bool isInt(const std::string& s) {
	size_t i = 0;
	size_t sLen = s.size();
	if (isSign(s[i])) {i++;}
	if (i >= sLen) {return false;}
	while (i < sLen) {
		unsigned char c = static_cast<unsigned char>(s[i]);
		if (!std::isdigit(c)) { return false; }
		++i;
	}
	return true;
}

bool isFloat(const std::string& s) {
	size_t sLen = s.size();
	if (sLen < 2 || s[sLen-1] != 'f') { return false; }

	std::string core = s.substr(0, sLen-1);

	size_t i = 0;
	size_t coreLen = core.size();
	if (isSign(core[i])) ++i;
	if (i >= coreLen) return false;

	bool hasDigit = false;
	bool hasDot = false;
	for (; i < coreLen; ++i) {
		unsigned char c = static_cast<unsigned char>(core[i]);
		if (std::isdigit(c)) {
			hasDigit = true;
		} else if (c == '.') {
			if (hasDot) return false;
			hasDot = true;
		} else {
			return false;
		}
	}
	return hasDigit;
}

bool isDouble(const std::string& s) {
	size_t i = 0;
	size_t sLen = s.size();

	if (isSign(s[i])) ++i;
	if (i >= sLen) return false;

	bool hasDigit = false;
	bool hasDot = false;
	for (; i < sLen; ++i) {
		unsigned char c = static_cast<unsigned char>(s[i]);
		if (std::isdigit(c)) {
			hasDigit = true;
		} else if (c == '.') {
			if (hasDot) return false;
			hasDot = true;
		} else {
			return false;
		}
	}
	return hasDigit;
}

ScalarConverter::Type ScalarConverter::detectType(const std::string& raw) {
    const std::string s = trim(raw);
	if (raw.empty()) { return T_INVALID; }

    if (isPseudoFloat(s))  return T_PSEUDO_FLOAT;
    if (isPseudoDouble(s)) return T_PSEUDO_DOUBLE;

    if (isChar(s))  return T_CHAR;

    if (isInt(s))    return T_INT;
    if (isFloat(s))  return T_FLOAT;
    if (isDouble(s)) return T_DOUBLE;

    return T_INVALID;
}

void ScalarConverter::convert(const std::string& s) {
    switch (detectType(s)) {
    case T_CHAR: {
        char c = convertChar(s);
        printAll(c);
        break;
    }
    case T_INT: {
        int i = convertInt(s);
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
        printAll(f, /*wasPseudo=*/true);
        break;
    }
    case T_PSEUDO_DOUBLE: {
        double d = convertPseudoDouble(s);
        printAll(d, /*wasPseudo=*/true);
        break;
    }
    default:
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
    }
}

