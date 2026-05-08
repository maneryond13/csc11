#include <iostream>
using namespace std;

void MoveTxt2File(FILE* file, char words[][50], int count)
{
    if (file != nullptr)
    {
        for (int i = 0; i < count; i++)
        {
            fputs(words[i], file);
            fputs(" ", file);
        }
        fclose(file);
    }
    else
    {
        cout << "Error\n";
    }
}

int main ()
{
    char fname[100];
    cout << "Enter name of file : ";
    cin >> fname;

    FILE* file = fopen(fname, "w"); //перезапис
    if (file == nullptr)
    {
        cout << "Error!\n";
        return 1;
    }

    const int MAX_WORDS = 100;
    const int MAX_LEN = 50;
    char words[MAX_WORDS][MAX_LEN];
    int count = 0;

    cout << "Enter words (when you finish, write 'stop'): \n";

    while (true)
    {
        char input[MAX_LEN];
        cin >> input;

        if (strcmp(input, "stop") == 0)
        {
            break;
        }
        strcpy(words[count], input);
        count++;
    }

    MoveTxt2File(file, words, count);

    cout << "Words successfully written to file: " << fname << endl;
    
}
