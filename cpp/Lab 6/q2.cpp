#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class QuizQuestion {
    private:
        vector<string> questions {
        "woo",
        "What is the capital of France?\na) Berlin\nb) Paris\nc) London\n",
        "Which planet is known as the Red Planet?\na) Mars\nb) Jupiter\nc) Saturn\n",
        "What is the largest mammal??\na) Elephant\nb) Blue Whale\nc) Giraffe\n",
        "Who wrote 'Hamlet'?\na) Mark Twain\nb) Charles Dickens\nc) William Shakespere\n",
        "What is the chemical symbol for water?\na) H2O\nb) CO2\nc) O2\n",
        };
        vector<char> soultions {
        'e',
        'b', // {0, 1, 0}
        'a',
        'b',
        'c',
        'a'
        };
        int score = 0;


    public:
        string displayQuestions (int i) {
            return questions[i];
        }
        
        string checkAnswer (int i, string ans) {    
            for (auto ans1 : ans) {
                switch (ans1) {
                    case('a'):
                        if (i == 2|| i == 5) {
                            score ++;
                            return "Correct!";
                        } else {
                            return "Wrong Answer!";
                        };
                    case('b'):
                        if (i == 1|| i == 3) {
                            score ++;
                            return "Correct!";
                        } else {
                            return "Wrong Answer!";
                        };
                    case('c'):
                        if (i == 4) {
                            score ++;
                            return "Correct!";
                        } else {
                            return "Wrong Answer!";
                        };

                }
            } 
        }

        int displayscore () {
            return score;
        }

};

int main () {
    QuizQuestion quiz;
    unsigned int i = 1;
    string answer;
    while (i <= 5) {
        cout << "Question " << i << ": " << quiz.displayQuestions(i) << endl;
        cout << "Your answer (a,b,c): ";
        cin >> answer;
        while(!(cin >> answer)) {
             cout << "Invalid Input, Please enter a, b, or c: ";
             cin.clear();
             cin.ignore();
             }

        while(answer != "a" && answer == "b" && answer != "c") {
             cout << "Invalid Input, Please enter a, b, or c: ";
             cin >> answer;
             }
        
            
        cout << endl;
        cout << quiz.checkAnswer(i, answer) << "\n" << endl;

        i++;
        if (i == 6) {
            cout << "Your Total Score:" << quiz.displayscore() << "/5" << endl;
        }
    }
};