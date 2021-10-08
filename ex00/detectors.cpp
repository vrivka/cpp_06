#include "converter.hpp"

static bool detect_char(std::string const &arg) {
	if (arg.length() == 3)
		if (arg[0] == '\'' && arg[2] == '\'')
			return true;
	return false;
}

static bool detect_int(char const *arg) {
	int i = arg[0] == '-' || arg[0] == '+' ? 1 : 0;

	for (; arg[i]; i++)
		if (!std::isdigit(arg[i]))
			return false;
	return true;
}

static bool detect_float(char const *arg) {
	int i = arg[0] == '-' || arg[0] == '+' ? 1 : 0;

	if (!std::strcmp(&arg[i], "inff") || !std::strcmp(&arg[i], "nanf"))
		return true;
	for (; arg[i]; i++)
		if (!std::isdigit(arg[i]))
			break ;
	if (arg[i] == '.')
		for (i += 1; arg[i]; i++)
			if (!std::isdigit(arg[i]))
				break ;
	if (arg[i] == 'f' && !arg[i + 1])
		return true;
	return false;
}

static bool detect_double(char const *arg) {
	int i = arg[0] == '-' || arg[0] == '+' ? 1 : 0;

	if (!std::strcmp(&arg[i], "inf") || !std::strcmp(&arg[i], "nan"))
		return true;
	for (; arg[i]; i++)
		if (!std::isdigit(arg[i]))
			break ;
	if (arg[i] == '.') {
		for (i += 1; arg[i]; i++)
			if (!std::isdigit(arg[i]))
				return false;
	}
	else
		return false;
	return true;
}

char const *detect_literals_type(char const *arg) {
	if (detect_char(arg))
		return typeid(char).name();
	else if (detect_int(arg))
		return typeid(int).name();
	else if (detect_float(arg))
		return typeid(float).name();
	else if (detect_double(arg))
		return typeid(double).name();
	else
		return NULL;
}
