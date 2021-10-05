#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <iomanip>

typedef struct s_list {
	int i;
	struct s_list *next;
} t_list;

typedef t_list Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
