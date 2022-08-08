#ifndef QUIZQUESTIONGENERATORUSECASE_H
#define QUIZQUESTIONGENERATORUSECASE_H

#include <vector>
#include <memory>

#include "questiontemplatesatarepository.h"
#include "quizquestion.h"

class QuizQuestionGeneratorUseCase
{
public:
    QuizQuestionGeneratorUseCase() = default;
    QuizQuestion generate(const std::shared_ptr<QuestionTemplateDataRepository>& questionTemplateRepository);

};

#endif // QUIZQUESTIONGENERATORUSECASE_H
