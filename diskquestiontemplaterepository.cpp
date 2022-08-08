#include "diskquestiontemplaterepository.h"

#include <fstream>
#include <stdexcept>
#include <regex>


std::string filterKnownQuestionParamIssues(const std::string& questionParam){
    return std::regex_replace(questionParam, std::regex("in Formula One "), "");
}

//fix table known inconsistencies
bool isValid(const std::string& rowEntry){
    if(rowEntry.empty() || (rowEntry == " "))
        return false;
    if(rowEntry.find("OBE") != std::string::npos)
        return false;
    if(rowEntry.find("CBE") != std::string::npos)
        return false;
    if(rowEntry.find("MBE") != std::string::npos)
        return false;
    if(rowEntry.find("OAM") != std::string::npos)
        return false;

    return true;

}

std::pair<std::string, std::string> splitComma(const std::string& str){
    std::string delimiter = ",";

    size_t pos = 0;
    std::string question;
    std::string answer;

    if ((pos = str.find(delimiter)) != std::string::npos) {
        question = str.substr(0, pos);
        answer = str.substr(pos + 1, str.length() - 1);
    }

    return std::make_pair<std::string, std::string>(std::move(question), std::move(answer));
}

std::string removeQuote(const std::string& str){
    std::string quote = "\"";

    if (str.find(quote) != std::string::npos) {
        return str.substr(1, str.length() - 2);
    } else {
        return str;
    }
}

std::vector<std::string> parseQuestionTemplate(std::istream& is){
    std::vector<std::string> templateList;

    while(!is.eof()){
        std::string line;
        std::getline(is, line);

        if(!line.empty()){
            templateList.push_back(std::move(line));
        }
    }

    return templateList;
}

QuestionAnswerList parseQuestionAnswer(std::istream& is) {
    QuestionAnswerList qaList;
    while(!is.eof()){
        std::string line;
        std::getline(is, line);

        auto [question, answer] = splitComma(line);
        question = removeQuote(question);
        question = filterKnownQuestionParamIssues(question);
        answer = removeQuote(answer);


        if(isValid(question) && isValid(answer)){
            qaList.push_back(std::make_pair<std::string, std::string>(std::move(question), std::move(answer)));
        }
    }

    //removing columns titles
    if(qaList.size() > 0) {
        qaList.pop_front();
    }

    return qaList;
}

std::vector<QuestionTemplateData> QuestionTemplateDiskRepository::loadAll()
{
    std::ifstream questionTemplateFile(mQuestionTemplatePath);
    std::vector<QuestionTemplateData> questionTemplateVector;


    if(!questionTemplateFile.is_open()){
        throw std::runtime_error("Error while opening question template file");
    }

    auto questionTemplateList = parseQuestionTemplate(questionTemplateFile);

    if(mTablePathList.size() < questionTemplateList.size()){
        throw std::runtime_error("Error: Number of table files is smaller than question templates");
    }

    for(int i = 0; i < mTablePathList.size(); ++i){
        std::ifstream qaTableFile(mTablePathList[i]);
        if(!qaTableFile.is_open()){
            throw std::runtime_error("Error while question and answer table file");
        }

        auto qaTable = parseQuestionAnswer(qaTableFile);

        questionTemplateVector.emplace_back(std::move(questionTemplateList[i]), std::move(qaTable));
    }


    return questionTemplateVector;

}
