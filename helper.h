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
 * file with helper functions
 *
 */

int strlen(const char *str)
{
    int ind = 0;

    while (str[ind] != '\0')
    {
        ind++;
    }

    return ind;
}

int strcomp(const char *str1, const char *str2)
{
    int ind = 0;

    if (strlen(str1) != strlen(str2))
    {
        return -1;
    }

    while (str1[ind] != '\0' || str2[ind] != '\0')
    {
        if (str1[ind] != str2[ind])
        {
            return -1;
        }
        ind++;
    }

    return 0;
}

void printLettersOfStr(const char *str)
{
    int ind = 0;

    while (str[ind] != '\0')
    {
        std::cout << str[ind] << " ";
        ind++;
    }
}