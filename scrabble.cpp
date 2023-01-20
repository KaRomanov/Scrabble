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

int *mapString(const char *str)
{
    int *map = new int[ALPHABET_SIZE]{0};
    size_t ind = 0;
    while (str[ind] != '\0')
    {
        map[int(str[ind]) - int('a')]++;
        ind++;
    }

    return map;
}

char *strRandomLetters()
{
    char *lettersStr = new char[letters];
    srand(time(NULL));

    for (size_t i = 0; i < letters; i++)
    {
        int currentNum = rand() % 26;
        lettersStr[i] = char(currentNum + 'a');
    }

    return lettersStr;
}

bool isWordValid(const char *letters, const char *word)
{
    int *lettersMap = mapString(letters);
    int *wordMap = mapString(word);
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
        lettersMap[i] -= wordMap[i];
        if (lettersMap[i] < 0)
        {
            delete[] wordMap;
            delete[] lettersMap;
            return false;
        }
    }
    delete[] wordMap;
    delete[] lettersMap;

    return true;
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

        repeat:
        if (isWordInFile(word) && isWordValid(lettersStr, word))
        {
            points += strlen(word);
            std::cout << "Your points so far are: " << points << std::endl;
        }
        else
        {
            std::cout << "Invalid word. Try again with: ";
            printLettersOfStr(lettersStr);
            std::cout << std::endl;
            std::cin >> word;

            goto repeat;
        }

        delete[] lettersStr;
    }
    std::cout << std::endl;
    std::cout << "Your total points are " << points << std::endl << std::endl;
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
        if (rounds < 1 || rounds > 50)
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
