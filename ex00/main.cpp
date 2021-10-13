#include "converter.hpp"

static void print_impossible() {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

int main(int ac, char **av) {
	char const *s;

	if (ac < 2)
		std::cerr << av[0] << ": not enough arguments\nNote: only one argument valid, e.g. \"" << av[0] << " 42\"\n";
	else if (ac > 2)
		std::cerr << av[0] << ": too much arguments\nNote: only one argument valid, e.g. \"" << av[0] << " 42\"\n";
	if (!(s = detect_literals_type(av[1])))
		print_impossible();
	else if (s[0] == 'c')
		char_convert(av[1]);
	else if (s[0] == 'i')
		int_convert(av[1]);
	else if (s[0] == 'f')
		float_convert(av[1]);
	else if (s[0] == 'd')
		double_convert(av[1]);
}
