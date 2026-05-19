#include <iostream>

using namespace std;

void writeToFileAndCount()
{
    const char* path_to_file = "../data.txt";
    const char* mode = "w";

    FILE* file;
    int code = fopen_s(&file, path_to_file, mode);

    if (code != 0)
    {
        cout << "Error opening file: " << code << endl;
        return;
    }

    char ch;

    int upperCount = 0;
    int lowerCount = 0;
    int digitCount = 0;

    while (true)
    {
        cout << "Enter char (s - stop): ";
        ch = getchar();

        if (ch == 's')
        {
            break;
        }

        if (ch >= 'A' && ch <= 'Z')
        {
            upperCount++;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            lowerCount++;
        }
        else if (ch >= '0' && ch <= '9')
        {
            digitCount++;
        }

        fputc(ch, file);

        cin.ignore();
    }

    fclose(file);

    cout << "\nStatistics:\n";
    cout << "Upper letters: " << upperCount << endl;
    cout << "Lower letters: " << lowerCount << endl;
    cout << "Digits: " << digitCount << endl;
}

int main()
{
    writeToFileAndCount();

    return 0;
}
