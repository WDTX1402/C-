#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SimpleQuizGame {
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
            string display_questions() {
                
            }

}
