#include "serialize.hpp"

int main()
{
	Data data_serialize;
	Data *datad;
	uintptr_t raw;

	data_serialize.i = 42;

	raw = serialize(&data_serialize);
	datad = deserialize(raw);

	std::cout << std::setbase(16) << raw << ' ' << &data_serialize << std::endl;
	std::cout << std::setbase(10) << datad->i << std::endl;
	datad->i = 3;
	std::cout << datad->i << std::endl;
}
