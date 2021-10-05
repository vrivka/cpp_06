#include <iostream>
#include <iomanip>

void print_char(double const &arg)
{
	int int_arg = static_cast<int>(arg);

	std::cout << "char: ";
	if (arg != arg || (int_arg < CHAR_MIN || int_arg > CHAR_MAX))
		std::cout << "impossible\n";
	else if (std::isprint(int_arg))
		std::cout << '\'' << static_cast<char>(arg) << '\'' << std::endl;
	else
		std::cout << "Non displayable\n";
}

void print_int(double const &arg)
{
	long int long_int_arg = static_cast<long int>(arg);

	std::cout << "int: ";
	if (arg != arg || (long_int_arg < INT_MIN || long_int_arg > INT_MAX))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(arg) << std::endl;
}

bool has_precision(double const &arg)
{
	int a = static_cast<int>(arg);
	double b = arg - static_cast<double>(a);

	if (b <= 0 || b > 1)
		return true;
	return false;
}

int main(int ac, char **av)
{
	double arg;

	if (ac < 2)
		std::cerr << av[0] << ": not enough arguments\nNote: only one argument valid, e.g. \"" << av[0] << " 42\"\n";
	else if (ac > 2)
		std::cerr << av[0] << ": too much arguments\nNote: only one argument valid, e.g. \"" << av[0] << " 42\"\n";
	arg = strtod(av[1], NULL);
	print_char(arg);
	print_int(arg);
	if (has_precision(arg))
		std::cout << std::setprecision(1);
	std::cout << "float: " << std::fixed << static_cast<float>(arg) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << arg << std::endl;
}