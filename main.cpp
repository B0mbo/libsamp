#include <cstdint>
#include <cstring>
#include <iostream>

#include "LibSamp.h"

using namespace sampdata;

void show_server(LibSamp& lsSamp, std::string& strAddr, int nPort);
void show_players(LibSamp& lsSamp, std::string& strAddr, int nPort);

int main(int argc, char *argv[])
{
    LibSamp lsSamp;
    Samp_i_Response sir;
    Samp_d_Response sdr;
    std::string strAddr = std::string("191.96.53.178");

    if(argc > 1)
    {
	if (strcmp("players", argv[1]) == 0) {
	    show_players(lsSamp, strAddr, 7797);
	}

	if (strcmp("server", argv[1]) == 0) {
	    show_server(lsSamp, strAddr, 7797);
	}
    } else {
	show_server(lsSamp, strAddr, 7797);
	show_players(lsSamp, strAddr, 7797);
    }
    return 0;
}

void show_players(LibSamp& lsSamp, std::string& strAddr, int nPort)
{
	    Samp_i_Response sir;
	    Samp_d_Response sdr;
	    lsSamp.getPlayersList(strAddr, nPort, sdr);

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

void show_server(LibSamp& lsSamp, std::string& strAddr, int nPort)
{
	    Samp_i_Response sir;
	    Samp_d_Response sdr;
	    lsSamp.getServerInfo(strAddr, nPort, sir);
	    std::cout << sir.strHostName << "\t" << (int)sir.sPlayers << "/" << sir.sMaxPlayers << std::endl;    
}
