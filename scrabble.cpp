/**
 *
 * Solution to course project # 8
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2022/2023
 *
 * @author Kaloyan Romanov
 * @idnumber 7MI0600185
 * @compiler GCC
 *
 * main file
 *
 */

#include <iostream>
#include <fstream>
#include "helper.h"
#include "time.h"

size_t rounds = 10;
size_t letters = 10;
const size_t MAX_SIZE = 32;
const size_t ALPHABET_SIZE = 26;

void printMainMenu()
{
    std::cout << "1. Start new game" << std::endl;
    std::cout << "2. Settings" << std::endl;
    std::cout << "3. Add word to dictionary" << std::endl;
    std::cout << "Press [q] to quit" << std::endl;
}

char *strRandomLetters()
{
    char *lettersStr = new char[MAX_SIZE];
    srand(time(NULL));
    for (size_t i = 0; i < letters; i++)
    {
        int currentNum = rand() % 26;
        lettersStr[i] = char(currentNum + 'a');
    }

    return lettersStr;
}

int isWordInFile(const char *str)
{
    char buffer[MAX_SIZE];
    std::fstream dictionary;
    dictionary.open("dictionary.txt", std::fstream::in);

    if (dictionary.is_open() == false)
    {
        std::cout << "Something went wrong" << std::endl;
        return -1;
    }

    while (dictionary >> buffer)
    {
        if (!strcomp(str, buffer))
        {
            return 1;
        }
    }
    dictionary.close();

    return 0;
}

bool isWordValid(const char *letters, const char *word)
{
}

int startGame()
{
    size_t points = 0;

    for (size_t i = 1; i <= rounds; i++)
    {
        char word[MAX_SIZE];
        std::cout << "Round " << i << ". Available letters: ";
        char *lettersStr = strRandomLetters();
        printLettersOfStr(lettersStr);
        std::cout << std::endl;
        std::cin >> word;

        while (!isWordInFile(word) && !isWordValid(lettersStr, word))
        {
            std::cout << "Invalid word. Try again with: ";
            printLettersOfStr(lettersStr);
            std::cout << std::endl;
            std::cin >> word;
        }

        points += strlen(word);
        delete[] lettersStr;
        std::cout << "Your points so far are: " << points << std::endl;
    }

    std::cout << "Your total points are " << points << std::endl;
    return 0;
}

int editSettings()
{
    char input;

    std::cout << "1. Change letters count" << std::endl;
    std::cout << "2. Changes rounds count" << std::endl;
    std::cin >> input;

    switch (input)
    {
    case '1':
        std::cout << "How many letters do you want?" << std::endl;
        std::cin >> letters;
        if (letters < 3 || letters > 30)
        {
            std::cout << "Not a valid number" << std::endl;
            letters = 10;
        }
        break;
    case '2':
        std::cout << "How many rounds do you want?" << std::endl;
        std::cin >> rounds;
        if (rounds < 1 || rounds > 100)
        {
            std::cout << "Not a valid number" << std::endl;
            rounds = 10;
        }
        break;
    default:
        std::cout << "Wrong input!" << std::endl;
        break;
    }

    return 0;
}

int addWord()
{
    char word[16];
    std::cout << "Input the word you want to add: " << std::endl;
    std::cin >> word;

    std::fstream dictionary;
    dictionary.open("dictionary.txt", std::fstream::out | std::fstream::app);
    if (dictionary.is_open() == false)
    {
        std::cout << "Failed to open file" << std::endl;
        return -1;
    }

    dictionary << word << '\n';
    dictionary.close();

    return 0;
}

void mainMenuLogic()
{
    char input;

    do
    {
        printMainMenu();
        std::cin >> input;
        switch (input)
        {
        case '1':
            startGame();
            break;
        case '2':
            editSettings();
            break;
        case '3':
            if (!addWord())
            {
                std::cout << "Successfully added word to the dictionary" << std::endl;
            }
            break;
        case 'q':
            return;
        default:
            std::cout << "wrong input" << std::endl;
            break;
        }
    } while (input != 'q');
}

int main()
{

    mainMenuLogic();

    return 0;
}
