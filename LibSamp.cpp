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
    std::cerr << "Sending UDP request to " << in_strServerIp << ":" << in_sPort << std::endl;
    for(int j = 0; j < sizeof(spb); ++j) {
	std::cerr << "spb[" << j << "]=" << ((unsigned char)(((char *)&spb)[j])) << std::endl;
    }
    if((nRet = sock.SendUDPRequest((uint8_t *)&spb, sizeof(spb), pData, nDataLen)) > 0)
    {
	sampdata::Samp_i_Response *sip = new sampdata::Samp_i_Response(pData);
	out_sirData = *sip;
	std::cout << "nRet=" << nRet << ", Palyers: " << out_sirData.sPlayers << std::endl;
	delete sip;
    } else {
	std::cerr << "Error: nRet=" << nRet << " sending UDP request to " << in_strServerIp << std::endl;
    }
}

void LibSamp::getPlayersList(std::string& in_strServerIp, uint16_t in_sPort, sampdata::Samp_d_Response& out_sdrData)
{
    uint8_t *pData;
    int32_t nDataLen, nRet;
    libsocket::LibSocket sock(in_strServerIp, in_sPort);
    SampPacketBackbone spb(in_strServerIp, in_sPort, (uint8_t)'d'); // server info
    if((nRet = sock.SendUDPRequest((uint8_t *)&spb, sizeof(spb), pData, nDataLen)) > 0)
    {
	sampdata::Samp_d_Response *sdp = new sampdata::Samp_d_Response(pData);
	out_sdrData = *sdp;
	delete sdp;
    }
}

}; //sampdata
