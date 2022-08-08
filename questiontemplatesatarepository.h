#ifndef QUESTIONTEMPLATEDATAREPOSITORY_H
#define QUESTIONTEMPLATEDATAREPOSITORY_H

#include <vector>
#include "questiontemplatedata.h"


class QuestionTemplateDataRepository {
public:
    virtual std::vector<QuestionTemplateData> loadAll() = 0;
    virtual ~QuestionTemplateDataRepository(){};
};

#endif // QUESTIONTEMPLATEDATAREPOSITORY_H
