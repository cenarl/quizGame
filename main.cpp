#include <iostream>
#include <fstream>
using namespace std;

class Question
{
public:
    string question;
    vector<string> options;
    int answer;
};

vector<Question> readQuestion(const string &filename)
{
    vector<Question> questions;
    ifstream file(filename);

    if (!file)
    {
        cout << "Error!" << endl;
    }

    string line;
    while (getline(file, line))
    {
        Question q;
        q.question = line;

        for (int i = 0; i < 4; i++)
        {
            getline(file, line);
            q.options.push_back(line);
        }
        getline(file, line);
        q.answer = stoi(line);
        questions.push_back(q);
    }
    file.close();
    return questions;
}

void printQuestion(const Question &q, int questionNum)
{
    cout << "\n"
         << questionNum << "- " << q.question << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "   " << i + 1 << ") " << q.options[i] << endl;
    }
}

int main()
{
    vector<Question> q = readQuestion("questions.txt");
    vector<int> userAnswers(q.size(), 0);

    int cur = 0, score = 0;
    while (true)
    {
        printQuestion(q[cur], cur + 1);

        if (userAnswers[cur] != 0)
        {
            cout << "\nYour answer is: " << userAnswers[cur] << endl;
        }

        cout << "\nEnter your answer (1-4) ";
        if (cur > 0)
        {
            cout << "'p' for previous question, ";
        }
        cout << "'n' for next question or 'q' to quit: ";

        char userInput;
        cin >> userInput;

        if (userInput == 'q')
            break;

        else if (userInput != 'p' && userInput != 'n')
        {
            int userAnswer = userInput - '0';
            while (userAnswer > 4 || userAnswer < 1)
            {
                cout << "\nPlease enter valid number: ";
                cin >> userAnswer;
            }

            if (userAnswers[cur] == q[cur].answer)
                score--;

            if (userAnswer == q[cur].answer)
            {
                cout << "\nCorrect!\n"
                     << endl;
                score++;
            }
            else
            {
                cout << "\nIncorrect!\n"
                     << endl;
            }
            userAnswers[cur] = userAnswer;
            cur++;
        }

        else if (userInput == 'p')
            cur--;

        else
            cur++;

        if (cur == q.size())
            break;
    }

    cout << "\n**************Quiz completed!**************"
         << endl;
    cout << "\nYour score is " << score << "/" << q.size() << endl;
    return 0;
}
