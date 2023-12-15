#pragma once

#include<iostream>

#include "CLibSamp.h"
#include "LibSocket.h"
#include "SampServersData.h"

extern "C++" {

namespace sampdata {

class LibSamp : public CLibSamp
{

//socket realising
public:
    LibSamp();

    void getServerInfo(std::string& in_strServerIp, uint16_t in_sPort, sampdata::Samp_i_Response& out_sirData);
    void getPlayersList(std::string& in_strServerIp, uint16_t in_sPort, sampdata::Samp_d_Response& out_sdrData);
};

}; //sampdata

}