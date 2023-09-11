#include "ChessPlayer.h"

ChessPlayer::ChessPlayer(
    double _id,
    std::string _name,
    std::string _federation,
    Sex _sex,
    std::string _title,
    int _standardRating,
    int _rapidRating,
    int _blitzRating,
    int _birthYear) : id{_id},
                      name{_name},
                      federation{_federation},
                      sex{_sex},
                      title{_title},
                      standardRating{_standardRating},
                      rapidRating{_rapidRating},
                      blitzRating{_blitzRating},
                      birthYear{_birthYear} {}

Sex ChessPlayer::stringToSex(std::string sex) {
    return Sex::male;
};

RatingType ChessPlayer::stringToRatingType(std::string ratingType) {
    return RatingType::standard;
};