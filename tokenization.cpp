#include <iostream>
#include <cctype>
#include <vector>
#include <string>

void input()
{
    int n;
    char c;
    do
    {
        do
        {
            std::cout << "How many categories of tokens do you need to parse:" << std::endl;
            std::cin >> n;
        } while (n <= 0);
        std::cout << n;
        std::cout << "is the number of categories wanted" << std::endl;
        do
        {
            std::cout << "Do you confirm (y/n)" << std::endl;
            std::cin >> c;
            c = tolower(c);
        } while (c != 'y' && c != 'n');
    } while (c == 'n');

    char categories[n][30];
    for (int i = 0; i < n; i++)
    {
        std::cout << i + 1;
        char first[2];
        if (i == 0)
        {
            first[0] = 's';
            first[1] = 't';
        }
        else if (i == 1)
        {
            first[0] = 'n';
            first[1] = 'd';
        }
        else
        {
            first[0] = 't';
            first[1] = 'h';
        }
        std::cout << first;
        std::cout << " category" << std::endl;
        std::cin >> categories[i];
    }

    std::cout << "Here are all the categories you have entered" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << categories[i];
        if (i != n - 1)
            std::cout << " | ";
        else
            std::cout << "\n";
    }
    int numberOfValues[n];
    std::vector<std::vector<std::string>> values;
    for (int i = 0; i < n; i++)
    {
        do
        {
            std::cout << "for the category " << categories[i] << ". How many values can it be? (should be bigger than 0)" << std::endl;
            std::cin >> numberOfValues[i];
        } while (numberOfValues[i] <= 0);
        std::cout << "for the category ";
        std::cout << categories[i];
        std::cout << "enter the values one by one";
        for (int j = 0; j < numberOfValues[i]; j++)
        {
            std::vector<std::string> temp;
            std::string tempVal;
            std::cin >> tempVal;
            temp.push_back(tempVal);
            if (j == numberOfValues[i] - 1)
            {
                values.push_back(temp);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << "category " << categories[i] << std::endl;
        for (int j = 0; j < numberOfValues[i]; j++)
        {
            std::cout << values[i][j];
        }
        std::cout << std::endl;
    }
}

int main(int argc, char **argv)
{
    input();
    return 0;
}