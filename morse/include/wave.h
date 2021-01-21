#include <vector>
#include <string>
#include <iostream>
#include <string>
using namespace std;

class wave
{
public:
    wave(){};
    ~wave(){};

private:


private:
public:
    void EncodeMorseCodesAsSound(const std::string &filename, std::string &morse);
    std::string DecodeMorseWavFile(std::string filename);

    
    void test_write_binary(std::uint32_t v);
    std::uint32_t test_read_binary();
}; 
