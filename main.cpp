#include <cstdint>
#include <iostream>

#include "LibSamp.h"

using namespace sampdata;

int main()
{
    LibSamp lsSamp;
    Samp_i_Response sir;
    std::string strAddr = std::string("191.96.53.178");

    lsSamp.getServerInfo(strAddr, 7797, sir);

    return 0;
}

