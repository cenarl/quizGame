# Quiz Game

This is a simple quiz game implemented in C++. It presents a series of multiple-choice questions and allows players to test their knowledge and score points based on their answers.

## How to Play

1. The game presents a series of multiple-choice questions.
2. Each question has four options (labeled 1, 2, 3, and 4).
3. Players select their answer by entering the corresponding option letter.
4. After answering a question, the game provides feedback on the correctness of the answer.
5. Players accumulate points based on the number of correct answers.
6. At the end of the quiz, the game displays the final score.

## Features

- The game reads questions and options from a file for easy customization.
- Players receive immediate feedback on the correctness of their answers.
- The game keeps track of the score throughout the quiz.
- It allows players to navigate between questions and change their answers.
- Error handling is included for invalid input.


## Question Format

The quiz questions and options are stored in a text file named `questions.txt` in the following format:
[Question]
[Option 1]
[Option 2]
[Option 3]
[Option 4]
[Correct Option]


Each question and its options are separated by a blank line. The correct option is denoted by a number (1-4) indicating the correct answer.
Feel free to customize the questions and options in the `questions.txt` file to create your own quizzes.
Enjoy playing the Quiz Game and test your knowledge!
