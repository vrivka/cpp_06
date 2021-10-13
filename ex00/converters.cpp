#include "converter.hpp"

void char_convert(char const *arg) {
	unsigned char char_value = arg[1];

	std::cout << "char: \'" << char_value << "\'\n";
	std::cout << "int: " << static_cast<int>(char_value) << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(char_value) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(char_value) << std::endl;
}

void int_convert(char const *arg) {
	long int long_int_value = atol(arg);

	std::cout << "char: ";
	if (long_int_value < CHAR_MIN || long_int_value > CHAR_MAX)
		std::cout << "impossible\n";
	else if (std::isprint(static_cast<int>(long_int_value)))
		std::cout << '\'' << static_cast<char>(long_int_value) << '\'' << std::endl;
	else
		std::cout << "Non displayable\n";
	std::cout << "int: ";
	if (long_int_value < INT_MIN || long_int_value > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(long_int_value) << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(long_int_value) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(long_int_value) << std::endl;
}

bool has_precision(double const &arg) {
	int a = static_cast<int>(arg);
	double b = arg - static_cast<double>(a);

	if (b <= 0 || b > 1)
		return true;
	return false;
}

void float_convert(char const *arg) {
	float float_value = atof(arg);
	long int long_int_value;

	long_int_value = static_cast<long int>(float_value);
	std::cout << "char: ";
	if (long_int_value < CHAR_MIN || long_int_value > CHAR_MAX)
		std::cout << "impossible\n";
	else if (std::isprint(static_cast<int>(long_int_value)))
		std::cout << '\'' << static_cast<char>(float_value) << '\'' << std::endl;
	else
		std::cout << "Non displayable\n";
	std::cout << "int: ";
	if (long_int_value < INT_MIN || long_int_value > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(float_value) << std::endl;
	if (has_precision(static_cast<double>(float_value)))
		std::cout << std::setprecision(1);
	std::cout << "float: " << std::fixed << float_value << 'f' << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(float_value) << std::endl;
}

void double_convert(char const *arg) {
	double double_value = std::strtod(arg, NULL);
	long int long_int_value;

	long_int_value = static_cast<long int>(double_value);
	std::cout << "char: ";
	if (long_int_value < CHAR_MIN || long_int_value > CHAR_MAX)
		std::cout << "impossible\n";
	else if (std::isprint(static_cast<int>(long_int_value)))
		std::cout << '\'' << static_cast<char>(double_value) << '\'' << std::endl;
	else
		std::cout << "Non displayable\n";
	std::cout << "int: ";
	if (long_int_value < INT_MIN || long_int_value > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(double_value) << std::endl;
	if (has_precision(double_value))
		std::cout << std::setprecision(1);
	std::cout << "float: " << std::fixed << static_cast<float>(double_value) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << double_value << std::endl;
}
