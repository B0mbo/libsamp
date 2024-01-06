#include <cstdint>
#include <cstring>
#include <iostream>

#include "LibSamp.h"

#define SERVER_ADDR "191.96.53.178"
#define SERVER_PORT 7797

//#define SERVER_ADDR "46.174.50.164"
//#define SERVER_PORT 7777

using namespace sampdata;

int main(int argc, char *argv[])
{
    LibSamp lsSamp;
    Samp_i_Response sir;
    Samp_d_Response sdr;
    std::string strAddr = std::string(SERVER_ADDR);

    if(argc > 1)
    {
	if (strcmp("players", argv[1]) == 0) {
	    lsSamp.getPlayersList(strAddr, SERVER_PORT, sdr);

	    for(int nIndex = 0; nIndex < sdr.vPlayers.size(); ++nIndex)
	    {
		std::cout << sdr.vPlayers.at(nIndex).strPlayerName << std::endl;
	    }

//	    for(int nIndex = 0; nIndex < sdr.vPlayers.size(); ++nIndex)
//	    {
//		Samp_d_Response::PlayerData pd = sdr.vPlayers.at(nIndex);
//		if(pd.strPlayerName.length() > 15)
//		    std::cout << (int)pd.cPlayerID << "\t" << pd.strPlayerName  << "\t" << pd.nPlayerScore << "\t" << pd.nPlayerPing << std::endl;
//		else
//		    std::cout << (int)pd.cPlayerID << "\t" << pd.strPlayerName  << "\t\t" << pd.nPlayerScore << "\t" << pd.nPlayerPing << std::endl;
//	    }
	}

	if (strcmp("server", argv[1]) == 0) {
	    lsSamp.getServerInfo(strAddr, SERVER_PORT, sir);
	    std::cout << sir.strHostName << "\t" << (int)sir.sPlayers << "/" << sir.sMaxPlayers << std::endl;
	}
    } else {
	    lsSamp.getServerInfo(strAddr, SERVER_PORT, sir);
	    std::cout << sir.strHostName << "\t" << (int)sir.sPlayers << "/" << sir.sMaxPlayers << std::endl;
	    lsSamp.getPlayersList(strAddr, SERVER_PORT, sdr);
	    for(int nIndex = 0; nIndex < sdr.vPlayers.size(); ++nIndex)
	    {
		std::cout << sdr.vPlayers.at(nIndex).strPlayerName << std::endl;
	    }
    }
    return 0;
}
