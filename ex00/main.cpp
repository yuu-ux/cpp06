#include "ScalarConverter.h"

// int main(int argc, char **argv) {
// 	if (argc != 2) {
// 		std::cerr << "Usage: ./convert <literal>" <<std::endl;
// 		return 1;
// 	}
// 	std::string s = argv[1];
// 	scalarconverter::convert(s);
// 	return 0;
// }

template <typename T>
class xy {
    public:
        T x;
        T y;
};

int main(void) {
    xy <int> int_xy = {1,2};
    xy <double> double_xy = {1.24, 1.22};
    std::cout << int_xy.x << std::endl;
    std::cout << int_xy.y << std::endl;
    std::cout << double_xy.x << std::endl;
    std::cout << double_xy.y << std::endl;
}
