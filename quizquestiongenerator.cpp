#include <random>
#include "quizquestiongenerator.h"
#include <list>
#include <iterator>
#include <regex>
#include <set>


namespace {
    constexpr int NUMBER_OF_ANSWERS = 5;
}


int generateRandomInt(int min, int max) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(min,max);
    return dist(rng);
}

QuizQuestion QuizQuestionGenerator::generate(const QuestionTemplateData& questionTemplateData)
{
    std::vector<std::string> answerVector;
    auto questionAnswerList = questionTemplateData.questionAnswerList();
    auto [questionParam, answer] = pickCorrectQuestionAnswer(questionAnswerList);


    //remove rows with same answer
    std::set<std::string> uniqueAnswersSet;
    uniqueAnswersSet.insert(answer);

    auto it = questionAnswerList.begin();
    while(it != questionAnswerList.end()){
        if(uniqueAnswersSet.find(it->second) != uniqueAnswersSet.end()){
            questionAnswerList.erase(it++);
        }else {
            uniqueAnswersSet.insert(it->second);
            it++;
        }
    }


    answerVector.push_back(std::move(answer));
    pickFalseAnswers(questionAnswerList, answerVector);

    int correctAnswerIndex = generateRandomInt(0, answerVector.size() - 1);
    std::string aux = answerVector[correctAnswerIndex];
    answerVector[correctAnswerIndex] = answerVector[0];
    answerVector[0] = aux;

    auto question = replaceQuestionTemplateParam(questionTemplateData.questionTemplate(), questionParam);
    return QuizQuestion{std::move(question), std::move(answerVector), correctAnswerIndex};

}

std::pair<std::string, std::string> QuizQuestionGenerator::pickCorrectQuestionAnswer(QuestionAnswerList &qaList)
{
    int chosenRowIndex = generateRandomInt(0, qaList.size() - 1);

    auto answerIte = qaList.begin();
    std::advance(answerIte, chosenRowIndex);

    auto questionAnswer = std::move(*answerIte);
    qaList.erase(answerIte);


    return questionAnswer;
}

void QuizQuestionGenerator::pickFalseAnswers(QuestionAnswerList &qaList, std::vector<std::string>& answersVec)
{
    for(int i = 0; i < NUMBER_OF_ANSWERS - 1; ++i){
        if(qaList.empty())
            break;

        int chosenRowIndex = generateRandomInt(0, qaList.size() - 1);
        auto falseAnswerIte = qaList.begin();
        std::advance(falseAnswerIte, chosenRowIndex);

        answersVec.push_back(std::move(falseAnswerIte->second));
        qaList.erase(falseAnswerIte);
    }

}

std::string QuizQuestionGenerator::replaceQuestionTemplateParam(const std::string questionTemplate,
                                                                const std::string &questionParam)
{
    return std::regex_replace(questionTemplate, std::regex("<questionParam>"), questionParam);
}
