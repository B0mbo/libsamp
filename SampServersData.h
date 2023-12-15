#pragma once

#include <vector>

#pragma pack(push,1)

namespace sampdata {

struct SampPacketBackbone {
    uint8_t	cSAMPWord[4];		// 4 bytes
    uint8_t	pcServerIpAddress[4];	// 4 bytes
    uint16_t	sPort;			// 2 bytes
    uint8_t 	cOpcode;		// 1 byte, request type
    
    SampPacketBackbone() = delete;
    SampPacketBackbone(uint8_t *pData);
    SampPacketBackbone(std::string& in_strAddr, uint16_t in_sPort, uint8_t in_cOpcode);

    static uint8_t  GetStringFromData8 (const uint8_t * const in_pData, std::string& out_strData);
    static uint16_t GetStringFromData16(const uint8_t * const in_pData, std::string& out_strData);
    static uint32_t GetStringFromData32(const uint8_t * const in_pData, std::string& out_strData);
};

struct Samp_i_Response : public SampPacketBackbone {
    uint8_t	cIsPasswordSet;
    uint16_t	sPlayers;
    uint16_t	sMaxPlayers;
    uint32_t	nHostNameLen;
    std::string	strHostName;
    uint32_t	nGModeNameLen;
    std::string	strGModeName;
    uint32_t	nLanguageLen;
    std::string	strLanguage;

    Samp_i_Response() = delete;    
    explicit Samp_i_Response(uint8_t *pData);
};

struct Samp_r_Response : public SampPacketBackbone {
    struct RuleData {
	uint8_t		cRuleNameLen;
	std::string	strRuleName;
	uint8_t		cValueLen;
	std::string	strValue;
    };
    
    uint16_t	sRuleCount;
    std::vector<RuleData> vRules;
    
    Samp_r_Response() = delete;
    explicit Samp_r_Response(uint8_t *pData);
};

struct Samp_c_Response : public SampPacketBackbone {
    struct PlayerShortData {
	uint8_t		cPlayerNameLen;
	std::string	strPlayerName;
	uint32_t	nPlayerScore;
    };
    uint16_t	sPlayersCount;
    std::vector<PlayerShortData> vPlayers;
    
    Samp_c_Response() = delete;
    explicit Samp_c_Response(uint8_t *pData);
};

struct Samp_d_Response : public SampPacketBackbone {
    struct PlayerData {
	uint8_t		cPlayerID;
	uint8_t		cPlayerNameLen;
	std::string	strPlayerName;
	uint32_t	nPlayerScore;
	uint32_t	nPlayerPing;
    };

    uint16_t		    sPlayersCount;
    std::vector<PlayerData> vPlayers;
    
    Samp_d_Response() = delete;
    explicit Samp_d_Response(uint8_t *pData);
};

struct Samp_RCON_Packet : public SampPacketBackbone {
    uint16_t	sPassLengh;
    uint8_t	czPassword[8];
    uint16_t	sCommandLengh;
    std::string	strCommandText;		// various lenght
    
    Samp_RCON_Packet() = delete;
    explicit Samp_RCON_Packet(uint8_t *);
};

struct Samp_p_Response : public SampPacketBackbone {

    Samp_p_Response() = delete;
    explicit Samp_p_Response(uint8_t *pData);
};

}; //sampdata manespace

#pragma pack(pop)
