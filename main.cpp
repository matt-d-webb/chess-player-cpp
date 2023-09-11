#include "XMLReader.h"
#include "ChessPlayer.h"
#include <vector>

int main()
{

    std::vector<ChessPlayer> players = XMLReader::readXML("data/players_list_xml_foa.xml");

    return 0;
}