#pragma once
#include <string>

class morse
{
public:
    morse();
    ~morse();

public:
    std::string encode(std::string ascii_string);
    std::string decode(std::string morse_string);

};
