#ifndef _BLOCK_CONFIG_H
#define _BLOCK_CONFIG_H
#include <random>
#include <stdexcept>

namespace block
{
    const float PI = 3.1415;
    const int SHIPWIDTH = 99;
    const int SHIPHEIGHT = 75;
    const int SAUCERWIDTH = 93;
    const int SAUCERHEIGHT = 84;

    /**
     * @brief Creates random number between min to max.
     *        https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
     * 
     * @param min 
     * @param max 
     * @return int 
     */
    int random_range(int min, int max);

    
} // namespace block





#endif // _BLOCK_CONFIGURATION_H