#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <iostream>
class ScalarConverter {
	public:
        typedef struct {
            char *charPtr;
            int *intPtr;
            float *floatPtr;
            double *doublePtr;
        } ConvertResult;
		static ConvertResult convert(std::string& target);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter &other);
		~ScalarConverter();
};

#endif
