#pragma once
#include <string>

enum class RatingType
{
    standard,
    rapid,
    blitz
};

enum class Sex 
{
    male,
    female,
    unknown
};

class ChessPlayer
{
public:
    double id;
    std::string name;
    std::string federation;
    Sex sex;
    std::string title;
    int standardRating;
    int rapidRating;
    int blitzRating;
    int birthYear;
    static Sex stringToSex(std::string sex);
    static RatingType stringToRatingType(std::string ratingType);

    ChessPlayer(
        double _id, 
        std::string _name, 
        std::string _federation,
        Sex _sex,
        std::string _title,
        int _standardRating,
        int _rapidRating,
        int _blitzRating,
        int _birthYear
    );
};