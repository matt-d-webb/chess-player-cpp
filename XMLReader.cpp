#include "XMLReader.h"
#include "ChessPlayer.h"
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "rapidxml.hpp"

XMLReader::XMLReader()
{
}

std::vector<ChessPlayer> XMLReader::readXML(std::string filename)
{
    std::vector<ChessPlayer> _players;
    struct Player
    {
        std::string fideid;
        std::string name;
        std::string country;
        std::string sex;
        std::string title;
        std::string w_title;
        std::string o_title;
        std::string foa_title;
        std::string rating;
        std::string games;
        std::string k;
        std::string rapid_rating;
        std::string rapid_games;
        std::string rapid_k;
        std::string blitz_rating;
        std::string blitz_games;
        std::string blitz_k;
        std::string birthday;
        std::string flag;
    };

    std::string filePath = filename;

    // Open the XML file for reading
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open the XML file." << std::endl;
        //return 1;
        throw;
    }

    // Read the XML content into a string
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string xmlData = buffer.str();

    // Create an XML document object
    rapidxml::xml_document<> doc;
    doc.parse<0>(&xmlData[0]);

    // Create a vector to store player information
    std::vector<Player> players;

        // Iterate through <player> nodes
    for (rapidxml::xml_node<>* playerNode = doc.first_node("playerslist")->first_node("player"); playerNode; playerNode = playerNode->next_sibling()) {
        Player player;
        player.fideid = playerNode->first_node("fideid")->value();
        player.name = playerNode->first_node("name")->value();
        player.country = playerNode->first_node("country")->value();
        player.sex = playerNode->first_node("sex")->value();
        player.title = playerNode->first_node("title")->value();
        player.w_title = playerNode->first_node("w_title")->value();
        player.o_title = playerNode->first_node("o_title")->value();
        player.foa_title = playerNode->first_node("foa_title")->value();
        player.rating = playerNode->first_node("rating")->value();
        player.games = playerNode->first_node("games")->value();
        player.k = playerNode->first_node("k")->value();
        player.rapid_rating = playerNode->first_node("rapid_rating")->value();
        player.rapid_games = playerNode->first_node("rapid_games")->value();
        player.rapid_k = playerNode->first_node("rapid_k")->value();
        player.blitz_rating = playerNode->first_node("blitz_rating")->value();
        player.blitz_games = playerNode->first_node("blitz_games")->value();
        player.blitz_k = playerNode->first_node("blitz_k")->value();
        player.birthday = playerNode->first_node("birthday")->value();
        player.flag = playerNode->first_node("flag")->value();

        players.push_back(player);
    }

    // Print player information
    for (const Player& player : players) {
        std::cout << "Player Name: " << player.name << std::endl;
        std::cout << "FIDE ID: " << player.fideid << std::endl;
        std::cout << "Country: " << player.country << std::endl;
        std::cout << "Sex: " << player.sex << std::endl;
        std::cout << "Title: " << player.title << std::endl;
        std::cout << "W Title: " << player.w_title << std::endl;
        std::cout << "O Title: " << player.o_title << std::endl;
        std::cout << "FOA Title: " << player.foa_title << std::endl;
        std::cout << "Rating: " << player.rating << std::endl;
        std::cout << "Games: " << player.games << std::endl;
        std::cout << "K: " << player.k << std::endl;
        std::cout << "Rapid Rating: " << player.rapid_rating << std::endl;
        std::cout << "Rapid Games: " << player.rapid_games << std::endl;
        std::cout << "Rapid K: " << player.rapid_k << std::endl;
        std::cout << "Blitz Rating: " << player.blitz_rating << std::endl;
        std::cout << "Blitz Games: " << player.blitz_games << std::endl;
        std::cout << "Blitz K: " << player.blitz_k << std::endl;
        std::cout << "Birthday: " << player.birthday << std::endl;
        std::cout << "Flag: " << player.flag << std::endl;
        std::cout << "====================================" << std::endl;
    }
    return _players;
};

std::vector<std::string> XMLReader::tokenise(std::string line, char separator)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(line);

    while (std::getline(tokenStream, token, separator))
    {
        tokens.push_back(token);
    }
    return tokens;
};

ChessPlayer XMLReader::stringsToChessPlayer(std::vector<std::string> strings)
{
    double id;
    int standardRating, rapidRating, blitzRating, birthYear;
    std::string name, federation, title;

    try
    {
        id = std::stod(strings[0]);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error converting ID string to double" << strings[0] << std::endl;
        throw e;
    }

    try
    {
        standardRating = std::stoi(strings[6]);
        rapidRating = std::stoi(strings[7]);
        blitzRating = std::stoi(strings[8]);
        birthYear = std::stoi(strings[9]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error converting string to int" << std::endl;
    }

    name = strings[1];
    federation = strings[2];
    Sex sex = ChessPlayer::stringToSex(strings[4]);
    title = strings[5];

    ChessPlayer player{
        id,
        name,
        federation,
        sex,
        title,
        standardRating,
        rapidRating,
        blitzRating,
        birthYear};

    return player;
};