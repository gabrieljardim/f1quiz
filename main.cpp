//#include "mainwindow.h"

//#include <QApplication>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <tuple>
#include <istream>
#include <sstream>

#include "quizquestiongeneratorusecase.h"
#include "diskquestiontemplaterepository.h"




int main(int argc, char *argv[])
{

    auto questionTemplateRepo = std::shared_ptr<QuestionTemplateDataRepository>(new QuestionTemplateDiskRepository(
                "res/question/questionTemplate",
                {"res/question/question1Table.csv",
                 "res/question/question2Table.csv",
                 "res/question/question3Table.csv",
                 "res/question/question4Table.csv",
                 "res/question/question5Table.csv"}));



    while(true){
        QuizQuestionGeneratorUseCase quizQuestionGeneratorUseCase;
        auto quizQuestion = quizQuestionGeneratorUseCase.generate(questionTemplateRepo);


        std::cout << quizQuestion.question() << std::endl;

        for(int i = 0; i < quizQuestion.possibleAnswers().size(); ++i){
            std::cout << "(" << i+1 <<")" << " " << quizQuestion.possibleAnswers()[i] << std::endl;
        }

        char opt;
        std::cin >> opt;

        if(opt < '1' || opt > '5')
            break;

        if(quizQuestion.correctAnswerIndex() + 1 == (opt - '0')){
            std::cout << "Correct Answer!" << std::endl;
        } else {
            std::cout << "Wrong Answer." << std::endl;
        }

    }






    //std::string testString = "\"f1DriverName\",\"wins\"\n"
    //                         "\"Alan Jones\",12\n"
    //                         "\"(MBE)\",12\n"
    //                         "\"Alberto Ascari\",13\n"
    //                         "\"Alessandro Nannini\",1\n"
    //                         "\"Sam Hanks\",1\n"
    //                         "\"Denny Hulme\",8\n"
    //                         "\"(OBE)\",8\n"
    //                         "\"Didier Pironi\",3\n";




    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();

    //std::cout << ss.str() << std::endl;

}
