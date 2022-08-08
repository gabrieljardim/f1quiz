#ifndef QUIZQUESTION_H
#define QUIZQUESTION_H

#include <string>
#include <vector>

class QuizQuestion
{
public:
    QuizQuestion(std::string&& question, std::vector<std::string>&& mPossibleAnswers, int correctAnswerIndex ) :
        mQuestion(std::move(question)), mPossibleAnswers(std::move(mPossibleAnswers)), mCorrectAnswerIndex(correctAnswerIndex)
    {}
    const std::string& question() const;
    const std::vector<std::string>& possibleAnswers() const;
    int correctAnswerIndex() const;

private:
    std::string mQuestion;
    std::vector<std::string> mPossibleAnswers;
    int mCorrectAnswerIndex;
};

#endif // QUIZQUESTION_H
