#include "quizquestiongeneratorusecase.h"


#include <random>
#include "quizquestiongenerator.h"


QuizQuestion QuizQuestionGeneratorUseCase::generate(const std::shared_ptr<QuestionTemplateDataRepository> &questionTemplateRepository)
{
    auto questionCollection = questionTemplateRepository->loadAll();

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, questionCollection.size() - 1);

    return QuizQuestionGenerator().generate(questionCollection[dist(rng)]);

}
