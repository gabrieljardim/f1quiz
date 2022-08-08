#include "questiontemplatedata.h"



const std::string &QuestionTemplateData::questionTemplate() const
{
    return mQuestionTemplate;
}

const QuestionAnswerList &QuestionTemplateData::questionAnswerList() const
{
    return mQuestionAnswerList;
}
