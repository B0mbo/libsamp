#include "LibSamp.h"

namespace sampdata {

LibSamp::LibSamp()
{    
}

void LibSamp::getServerInfo(std::string& in_strServerIp, uint16_t in_sPort, sampdata::Samp_i_Response& out_sirData)
{
//    LibSocket sock();
    SampPacketBackbone spb(in_strServerIp, in_sPort, (uint8_t)'i'); // server info
    
}

void LibSamp::getPlayersList(std::string& in_strServerIp, uint16_t in_sPort, sampdata::Samp_d_Response& out_sdrData)
{
}

}; //sampdata
