#include <cstdint>
#include <cstring>
#include <iostream>

#include "LibSamp.h"

using namespace sampdata;

int main(int argc, char *argv[])
{
    LibSamp lsSamp;
    Samp_i_Response sir;
    Samp_d_Response sdr;
    std::string strAddr = std::string("46.174.50.164");

    if(argc > 1)
    {
	if (strcmp("players", argv[1]) == 0) {
	    lsSamp.getPlayersList(strAddr, 7777, sdr);

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
	    lsSamp.getServerInfo(strAddr, 7777, sir);
	    std::cout << sir.strHostName << "\t" << (int)sir.sPlayers << "/" << sir.sMaxPlayers << std::endl;
	}
    }
    return 0;
}
