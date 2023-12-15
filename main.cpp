#include <cstdint>
#include <iostream>

#include "LibSamp.h"

using namespace sampdata;

int main()
{
    LibSamp lsSamp;
    uint8_t *pBuff = new uint8_t[1024];
    struct Samp_i_Response bb(((unsigned char *)pBuff));
    delete [] pBuff;

    return 0;
}

