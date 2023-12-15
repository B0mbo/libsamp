#include <string>
#include <cstring>
#include <cstdint>
#include <sstream>
#include <iostream>

#include "SampServersData.h"

namespace sampdata {

SampPacketBackbone::SampPacketBackbone(uint8_t *pData) {
    memcpy(cSAMPWord, pData, 4);
    memcpy(pcServerIpAddress, pData+4, 4);
    sPort = *((uint16_t *) (pData + sizeof(cSAMPWord) + sizeof(pcServerIpAddress)));
    cOpcode = pData[10];
}

SampPacketBackbone::SampPacketBackbone(std::string& in_strAddr, uint16_t in_sPort, uint8_t in_cOpcode) {
    memcpy(cSAMPWord, "SAMP", 4);
    //memcpy(pcServerIpAddress, in_strAddr.c_str(), 4); (!)
    std::vector<std::string> strings;
    std::string s;
    std::istringstream istr(in_strAddr);
    while (std::getline(istr, s, '.')) {
        std::cout << s << std::endl;
        strings.push_back(s);
    }
    pcServerIpAddress[0] = (unsigned char)(std::stoi(strings[0]));
    pcServerIpAddress[1] = (unsigned char)(std::stoi(strings[1]));
    pcServerIpAddress[2] = (unsigned char)(std::stoi(strings[2]));
    pcServerIpAddress[3] = (unsigned char)(std::stoi(strings[3]));
    sPort = in_sPort;
    cOpcode = in_cOpcode;
}

uint8_t SampPacketBackbone::GetStringFromData8(const uint8_t* const in_pData, std::string& out_strData) {
    uint8_t *pBuff;
    uint8_t nSize = in_pData[0];
    pBuff = new uint8_t[nSize+1];
    pBuff[nSize] = '\0';
    memcpy(pBuff, in_pData+sizeof(nSize), nSize);
    out_strData.assign((char *)pBuff, (int) nSize);
    delete [] pBuff;
    return nSize;
}

uint16_t SampPacketBackbone::GetStringFromData16(const uint8_t* const in_pData, std::string& out_strData) {
    uint8_t *pBuff;
    uint16_t nSize = *((uint16_t *) in_pData);
    pBuff = new uint8_t[nSize+1];
    pBuff[nSize] = '\0';
    memcpy(pBuff, in_pData+sizeof(nSize), nSize);
    out_strData.assign((char *)pBuff, (int)nSize);
    delete [] pBuff;
    return nSize;
}

uint32_t SampPacketBackbone::GetStringFromData32(const uint8_t* const in_pData, std::string& out_strData) {
    uint8_t *pBuff;
    uint32_t nSize = *((uint32_t *) in_pData);
    pBuff = new uint8_t[nSize+1];
    pBuff[nSize] = '\0';
    memcpy(pBuff, in_pData+sizeof(nSize), nSize);
    out_strData.assign((char *)pBuff, (int)nSize);
    delete [] pBuff;
    return nSize;
}


Samp_i_Response::Samp_i_Response(uint8_t *pData) :
SampPacketBackbone(pData)
{
    uint8_t *psBuff;

    uint16_t sOffset = sizeof(SampPacketBackbone);

    cIsPasswordSet = pData[sOffset];
    sOffset += sizeof(cIsPasswordSet);

    sPlayers = *((uint16_t *) (pData + sOffset));
    sOffset += sizeof(sPlayers);

    sMaxPlayers = *((uint16_t *) (pData + sOffset));
    sOffset += sizeof(sMaxPlayers);

    nHostNameLen = GetStringFromData32(pData, strHostName);
    sOffset += sizeof(nHostNameLen);
    sOffset += nHostNameLen;

    nGModeNameLen = GetStringFromData32(pData, strGModeName);
    sOffset += sizeof(nGModeNameLen);
    sOffset += nGModeNameLen;

    nLanguageLen = GetStringFromData32(pData, strLanguage);
    sOffset += sizeof(nLanguageLen);
    sOffset += nLanguageLen;
}

Samp_r_Response::Samp_r_Response(uint8_t *pData) :
SampPacketBackbone(pData)
{
    RuleData pdData;
    uint16_t sOffset = sizeof(SampPacketBackbone);
    
    sRuleCount = *((uint16_t *) (pData + sOffset));
    sOffset += sizeof(sRuleCount);
    for(uint16_t sIndex = 0; sIndex < sRuleCount; ++sIndex) {
	pdData.cRuleNameLen = GetStringFromData8(pData, pdData.strRuleName);
	sOffset += sizeof(pdData.cRuleNameLen);
	sOffset += pdData.cRuleNameLen;
	pdData.cValueLen = GetStringFromData8(pData, pdData.strValue);
	sOffset += sizeof(pdData.cValueLen);
	sOffset += pdData.cValueLen;
	vRules.push_back(pdData);
    }
}

Samp_c_Response::Samp_c_Response(uint8_t *pData) :
SampPacketBackbone(pData)
{
    PlayerShortData psdPlayer;
    uint16_t sOffset = sizeof(SampPacketBackbone);
    
    sPlayersCount = *((uint16_t *) (pData + sOffset));
    for(uint16_t sIndex = 0; sIndex < sPlayersCount; ++sIndex) {
	psdPlayer.cPlayerNameLen = GetStringFromData8(pData, psdPlayer.strPlayerName);
	sOffset += sizeof(psdPlayer.cPlayerNameLen);
	sOffset += psdPlayer.cPlayerNameLen;
	psdPlayer.nPlayerScore = *((uint32_t *) (pData + sOffset));
	sOffset += sizeof(psdPlayer.nPlayerScore);
	vPlayers.push_back(psdPlayer);
    }
}

Samp_d_Response::Samp_d_Response(uint8_t *pData) :
SampPacketBackbone(pData)
{
    uint8_t *pcBuff;
    PlayerData pdPlayer;
    uint16_t sOffset = sizeof(SampPacketBackbone);
    
    sPlayersCount = *((uint16_t *) (pData + sOffset));
    sOffset += sizeof(sPlayersCount);
    for(uint16_t sIndex = 0; sIndex < sPlayersCount; ++sIndex) {
	pdPlayer.cPlayerID = pData[sOffset];
	sOffset += sizeof(pdPlayer.cPlayerID);

	pdPlayer.cPlayerNameLen = GetStringFromData8(pData, pdPlayer.strPlayerName);
	sOffset += sizeof(pdPlayer.cPlayerNameLen);
	sOffset += pdPlayer.cPlayerNameLen;

	pdPlayer.nPlayerScore = *((uint32_t *) (pcBuff + sOffset));
	sOffset += sizeof(pdPlayer.nPlayerScore);

	pdPlayer.nPlayerPing = *((uint32_t *) (pcBuff + sOffset));
	sOffset += sizeof(pdPlayer.nPlayerPing);

	vPlayers.push_back(pdPlayer);
    }
}

Samp_RCON_Packet::Samp_RCON_Packet(uint8_t *pData) :
SampPacketBackbone(pData)
{
    uint16_t sOffset = sizeof(SampPacketBackbone);
    
};

Samp_p_Response::Samp_p_Response(uint8_t *pData) :
SampPacketBackbone(pData) {
}

}; //sampdata manespace
