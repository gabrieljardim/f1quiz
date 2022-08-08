#ifndef QQUESTIONTEMPLATEDATA_H
#define QQUESTIONTEMPLATEDATA_H

#include <string>
#include <list>
#include <tuple>


using QuestionAnswerList = std::list<std::pair<std::string, std::string>> ;

class QuestionTemplateData
{
public:
    QuestionTemplateData(std::string&& questionTemplate, QuestionAnswerList&& qaList) :
        mQuestionTemplate(std::move(questionTemplate)), mQuestionAnswerList(std::move(qaList)){}

    const std::string& questionTemplate() const;
    const QuestionAnswerList& questionAnswerList() const;

private:
    std::string mQuestionTemplate;
    QuestionAnswerList mQuestionAnswerList;

};

#endif // QUIZQUESTIONTEMPLATEDATA_H
