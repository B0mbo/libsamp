#include "LibSamp.h"

namespace sampdata {

LibSamp::LibSamp()
{
}

void LibSamp::getServerInfo(std::string& in_strServerIp, uint16_t in_sPort, sampdata::Samp_i_Response& out_sirData)
{
    uint8_t *pData;
    int32_t nDataLen, nRet;
    libsocket::LibSocket sock(in_strServerIp, in_sPort);
    SampPacketBackbone spb(in_strServerIp, in_sPort, (uint8_t)'i'); // server info

    //send ping here
    //...
    sock.SendUDPData((uint8_t *)&spb, sizeof(spb));
    pData = new uint8_t[1024*1024];
    if((nRet = sock.SendUDPRequest((uint8_t *)&spb, sizeof(spb), pData, nDataLen)) > 0)
	out_sirData.initData(pData);
    delete [] pData;
}

void LibSamp::getPlayersList(std::string& in_strServerIp, uint16_t in_sPort, sampdata::Samp_d_Response& out_sdrData)
{
    uint8_t *pData;
    int32_t nDataLen, nRet;
    libsocket::LibSocket sock(in_strServerIp, in_sPort);
    SampPacketBackbone spb(in_strServerIp, in_sPort, (uint8_t)'d'); // server info

    //send ping here
    //...
    sock.SendUDPData((uint8_t *)&spb, sizeof(spb));
    pData = new uint8_t[1024*1024];
    if((nRet = sock.SendUDPRequest((uint8_t *)&spb, sizeof(spb), pData, nDataLen)) > 0)
	out_sdrData.initData(pData);
    delete [] pData;
}

}; //sampdata
