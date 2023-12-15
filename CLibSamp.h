#pragma once

#include <cstdint>

#include "SampServersData.h"

namespace sampdata {

class CLibSamp
{
public:
    virtual void getServerInfo(std::string& in_strServerIp, uint16_t in_sPort, sampdata::Samp_i_Response& out_sirData) = 0;
    virtual void getPlayersList(std::string& in_strServerIp, uint16_t in_sPort, sampdata::Samp_d_Response& out_sdrData) = 0;
};

}; //sampdata
