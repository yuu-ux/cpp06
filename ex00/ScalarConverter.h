#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <iostream>
class scalarconverter {
	public:
		static int convert(std::string& target);

	private:
		scalarconverter();
		scalarconverter(const scalarconverter& other);
		scalarconverter& operator=(const scalarconverter &other);
		~scalarconverter();
};

#endif
