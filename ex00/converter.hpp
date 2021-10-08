#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <iomanip>

char const *detect_literals_type(char const *arg);
void char_convert(char const *arg);
void int_convert(char const *arg);
void float_convert(char const *arg);
void double_convert(char const *arg);

#endif
