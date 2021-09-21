#include "serialize.hpp"

int main()
{
	Data data_serialize;
	Data *data_deserialize;
	uintptr_t raw;

	data_serialize.i = 42;

	raw = serialize(&data_serialize);
	data_deserialize = deserialize(raw);

	std::cout << std::setbase(16) << raw << ' ' << &data_serialize << std::endl;
	std::cout << std::setbase(10) << data_deserialize->i << std::endl;
}
