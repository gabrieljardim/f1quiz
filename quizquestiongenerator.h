#ifndef QUESTIONGENERATOR_H
#define QUESTIONGENERATOR_H

#include "quizquestion.h"
#include "questiontemplatedata.h"

class QuizQuestionGenerator
{
public:
    QuizQuestionGenerator() = default;
    QuizQuestion generate(const QuestionTemplateData& questionTemplateData);
private:
    std::pair<std::string, std::string> pickCorrectQuestionAnswer(QuestionAnswerList& qaList);
    void pickFalseAnswers(QuestionAnswerList &qaList, std::vector<std::string>& answersVec);
    std::string replaceQuestionTemplateParam(const std::string questionTemplate, const std::string& questionParam);
};

#endif // QUESTIONGENERATOR_H
