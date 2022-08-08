#ifndef DISKQUESTIONTEMPLATEREPOSITORY_H
#define DISKQUESTIONTEMPLATEREPOSITORY_H

#include "questiontemplatesatarepository.h"


class QuestionTemplateDiskRepository : public QuestionTemplateDataRepository
{
public:
    QuestionTemplateDiskRepository(std::string&& questionTemplatePath, std::vector<std::string>&& tablePathList) :
        mQuestionTemplatePath(std::move(questionTemplatePath)), mTablePathList(std::move(tablePathList))
    {}
    virtual std::vector<QuestionTemplateData> loadAll();
    ~QuestionTemplateDiskRepository(){}
private:
    std::string mQuestionTemplatePath;
    std::vector<std::string> mTablePathList;

};

#endif // DISKQUESTIONTEMPLATEREPOSITORY_H
