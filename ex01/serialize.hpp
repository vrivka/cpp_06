#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <iomanip>

typedef struct Data_s {
	int i;
} Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
