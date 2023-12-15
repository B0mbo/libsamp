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
    std::string strAddr = std::string("191.96.53.178");

    if(argc > 1)
    {
	if (strcmp("players", argv[1]) == 0) {
	    lsSamp.getPlayersList(strAddr, 7797, sdr);
	    for(int nIndex = 0; nIndex < sdr.vPlayers.size(); ++nIndex)
	    {
		Samp_d_Response::PlayerData pd = sdr.vPlayers.at(nIndex);
		std::cout << (int)pd.cPlayerID << "\t" << pd.strPlayerName  << "\t" << pd.nPlayerScore << "\t" << pd.nPlayerPing << std::endl;
	    }
	}

	if (strcmp("server", argv[1]) == 0) {
	    lsSamp.getServerInfo(strAddr, 7797, sir);
	    std::cout << sir.strHostName << "\t" << (int)sir.sPlayers << "/" << sir.sMaxPlayers << std::endl;
	}
    }
    return 0;
}
