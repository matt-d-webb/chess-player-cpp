#pragma once
#include <vector>
#include <string>
#include "ChessPlayer.h"

class XMLReader
{
public:
    XMLReader();

    static std::vector<ChessPlayer> readXML(std::string filename);
    static std::vector<std::string> tokenise(std::string line, char separator);

private:
    static ChessPlayer stringsToChessPlayer(std::vector<std::string> strings);
     
};