/*Student Name: Sarah Toll Email Id: stoll
Due Date: October 6th Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity.
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all
material that I have used, whether directly quoted or paraphrased. Furthermore,
I certify that this assignment was prepared by me specifically for this course.
 */

#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(void) {
    //initialize variables - reward is prize
    //question is the current question you are on, count is number of lifelines
    int reward, question;
    int count = 0;
    //array of correct answers in same order as corresponding questions
    char correctAnswers[8] = "CBCBACA";
    //initialize variables - life for if they select yes or no, answer is what the user guesses
    bool life;
    char answer = 'A';

    //initializing variables, of digits and number to add together
    int birthYear, luckyNum, firstDigit, secondDigit, thirdDigit, fourthDigit;
    //prompting for year of birth and validating
    do {
        printf("Enter your year of birth(yyyy): ");
        scanf("%d", &birthYear);
        if (birthYear < 999 || birthYear > 10000) {
            printf("Please enter a valid 4 digit number.\n");
        }
    } while (birthYear < 999 || birthYear > 10000);

    printf("*************************\n");

    //find lucky number by getting each of the digits and adding
    firstDigit = birthYear / 1000;
    birthYear = birthYear % 1000;
    secondDigit = birthYear / 100;
    birthYear = birthYear % 100;
    thirdDigit = birthYear / 10;
    birthYear = birthYear % 10;
    fourthDigit = birthYear;
    luckyNum = firstDigit + secondDigit + thirdDigit + fourthDigit;

    //print introduction to the game
    printf("Welcome - Let us play millionEh! \n");
    printf("Your lucky number is %d\n", luckyNum);
    printf("*************************\n\n");

    //for loop to run through questions
    for (question = 1; question < 8; question++) {

        //prints question based on the number, sets reward as reward get if fail that question
        switch (question) {
            case 1:
                printf("Question 1: Here is the $100 question: \n\n"
                       "Which one of the following programming languages is taught in CIS1300 at the University of Guelph?\n\n");
                printf("A. Python\nB. Cobra\nC. C\nD. Java\n ");
                reward = 0;
                break;
            case 2:
                printf("Question 2: Here is the $500 question: \n\n"
                       "Which Canadian chain first opened in Hamilton in 1964?\n\n");
                printf("A. McDonalds\nB. Tim Hortons\nC. Wendys\nD. Mr. Sub\n");
                reward = 100;
                break;
            case 3:
                printf("Question 3: Here is the $1000 question: \n\n"
                       "What is Canada's national sport?\n\n");
                printf("A. Hockey\nB. Lacrosse\nC. Hockey and Lacrosse\nD. Baseball\n");
                reward = 500;
                break;
            case 4:
                printf("Question 4: Here is the $5000 question: \n\n"
                       "Which Canadian city ranks as the most educated in the country?\n\n");
                printf("A. Montreal\nB. Ottawa\nC. Vancouver\nD. Toronto\n");
                reward = 1000;
                break;
            case 5:
                printf("Question 5: Here is the $10000 question: \n\n"
                       "What is Canada's highest mountain?\n\n");
                printf("A. Mount Logan, Yukon\nB. Whistler Mountain, BC\nC. Mont Tremblant, Quebec\nD. Tip Top Mountain, Ontario\n");
                reward = 5000;
                break;
            case 6:
                printf("Question 6: Here is the $50000 question: \n\n"
                       "What is the easternmost province of Canada?\n\n");
                printf("A. Ontario\nB. Prince Edward Island\nC. Newfoundland\nD. Nova Scotia\n");
                reward = 10000;
                break;
            case 7:
                printf("Question 7: Here is the $100000 question: \n\n"
                       "The southernmost point of mainland Canada is called Point Pelee. Which province is it located in?\n\n");
                printf("A. Ontario\nB. Quebec\nC. Newfoundland\nD. Nova Scotia\n");
                reward = 50000;
                break;

        }




        //checks if lifeline has been used- if has not prompts user if they want to use lifeline
        //validates user input
        if (count == 0) {
            printf("\nWould you like to use a lifeline (50-50)?\n");
            do {
                printf("Enter Y or y, N or n: ");
                scanf(" %c", &answer);
                answer = toupper(answer);
                if (answer == 'Y') {
                    life = true;
                    break;
                } else if (answer == 'N') {
                    life = false;
                    break;
                }
                printf("Invalid option entered\n");
            } while (answer != 'Y' && answer != 'N');
        }
        //if lifeline hasn't been used, and they select yes, prints new choices
        if (count == 0) {
            if (life == true) {
                count++;
                printf("Reminder- you only have one lifeline and you are using it now\n");
                printf("\nOk - here are your two choices after lifeline used\n");
                switch (question) {
                    case 1:
                        printf("C. C\nD. Java\n ");
                        break;
                    case 2:
                        printf("A. McDonalds\nB. Tim Hortons\n");
                        break;
                    case 3:
                        printf("C. Hockey and Lacrosse\nD. Baseball\n");
                        break;
                    case 4:
                        printf("B. Ottawa\nC. Vancouver\n");
                        break;
                    case 5:
                        printf("A. Mount Logan, Yukon\nB. Whistler Mountain, BC\n");
                        break;
                    case 6:
                        printf("C. Newfoundland\nD. Nova Scotia\n");
                        break;
                    case 7:
                        printf("A. Ontario\nB. Quebec\n");
                        break;
                    default:
                        break;
                }
            }
        }

        //ask for final answer and validates user input
        do {
            printf("\nEnter your FINAL ANSWER (‘A’, ‘B’, ‘C’ OR ‘D’) here: ");
            scanf(" %c", &answer);
            answer = toupper(answer);
        } while (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D');
        //check if answer is correct against array of correct answers
        //if incorrect, prints amount they won and ends game
        if (correctAnswers[question - 1] != answer) {
            if (question == 1) {
                printf("\nWow, you lost on question one. congrats on winning absolutely nothing!");
                exit(0);
            } else {
                printf("\nOops - you dont get to be a millionaire today. Somehow you were smart enough to earn $%d though. "
                       "\nThanks for playing.\n", reward);
                exit(0);
            }
        }

            //if correct, prints greeting by generating random number
        else {
            srand((int) time(0));
            char greet[15];
            char string1[15] = "hello";
            int num = rand() % 5 + 1;
            switch (num) {
                case 1:
                    strcpy(string1, "Bravo");
                    break;
                case 2:
                    strcpy(string1, "Congrats");
                    break;
                case 3:
                    strcpy(string1, "Well done");
                    break;
                case 4:
                    strcpy(string1, "Very nice");
                    break;
                case 5:
                    strcpy(string1, "Proud of you");
                    break;

            }
            //sets reward to print with greeting
            strcpy(greet, string1);
            switch (question) {
                case 1:
                    reward = 100;
                    break;
                case 2:
                    reward = 500;
                    break;
                case 3:
                    reward = 1000;
                    break;
                case 4:
                    reward = 5000;
                    break;
                case 5:
                    reward = 10000;
                    break;
                case 6:
                    reward = 50000;
                    break;
                case 7:
                    reward = 100000;
                    break;
                default:
                    return 0;
            }
            printf("\n%s - you just won $%d\n\n", greet, reward);
            if(reward == 100000){
                return 0;
            }
            printf("Time for the next question!\n");
        }
    }
}

