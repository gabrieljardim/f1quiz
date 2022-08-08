#include "quizquestion.h"

const std::string &QuizQuestion::question() const
{
    return mQuestion;
}

const std::vector<std::string> &QuizQuestion::possibleAnswers() const
{
    return mPossibleAnswers;
}

int QuizQuestion::correctAnswerIndex() const
{
    return mCorrectAnswerIndex;
}
