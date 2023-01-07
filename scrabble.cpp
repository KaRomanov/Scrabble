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
 * <file with helper functions>
 *
 */

#include <iostream>
#include <fstream>

const short defaultRounds = 10;
const short defaultLettersCount = 10;

void printMainMenu()
{
    std::cout << "1. Start new game" << std::endl;
    std::cout << "2. Settings" << std::endl;
    std::cout << "3. Add word to dictionary" << std::endl;
    std::cout << "Press [q] to quit" << std::endl;
}

int startGame()
{
    return 0;
}

int editSettings()
{
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
            break;
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
