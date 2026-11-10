// Lab-08.1-Iter.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 8.1
// Варіант 31 — ітераційний метод

#include <iostream>
using namespace std;

// Перевірка трійки символів
bool IsGroupAt(const char s[], int i)
{
    if (s[i] == '\0' || s[i + 1] == '\0')
        return false;

    if (s[i + 2] == '\0')
        return false;

    return
        (s[i] == 'O' &&
            s[i + 1] == 'G' &&
            s[i + 2] == 'O') ||
        (s[i] == 'A' &&
            s[i + 1] == 'G' &&
            s[i + 2] == 'A');
}

// Ітераційний пошук
bool FindIterative(const char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (IsGroupAt(s, i))
            return true;
    }

    return false;
}

// Ітераційна заміна
void ReplaceIterative(const char s[], char result[])
{
    int i = 0;
    int j = 0;

    while (s[i] != '\0')
    {
        if (IsGroupAt(s, i))
        {
            result[j] = '*';
            result[j + 1] = '*';

            i += 3;
            j += 2;
        }
        else
        {
            result[j] = s[i];

            i++;
            j++;
        }
    }

    result[j] = '\0';
}

int main()
{
    const int SIZE = 256;

    char s[SIZE];
    char result[SIZE];

    cout << "Enter string: ";
    cin.getline(s, SIZE);

    cout << "Original: " << s << endl;

    bool found = FindIterative(s);

    cout << "Found: "
        << (found ? "Yes" : "No") << endl;

    ReplaceIterative(s, result);

    cout << "Modified: " << result << endl;

    return 0;
}
