#include "block_configuration.h"

int block::random_range(int min, int max) {
    if(min >= max) {
        throw std::runtime_error("Min greater equal max");
    }
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}