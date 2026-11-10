// Lab-08.1-Rec.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 8.1
// Варіант 31 — рекурсивний метод


#include <iostream>
using namespace std;

// Перевірка трійки символів
bool IsGroupAt(const char s[])
{
    if (s[0] == '\0' || s[1] == '\0')
        return false;

    if (s[2] == '\0')
        return false;

    return
        (s[0] == 'O' &&
            s[1] == 'G' &&
            s[2] == 'O') ||
        (s[0] == 'A' &&
            s[1] == 'G' &&
            s[2] == 'A');
}

// Рекурсивний пошук
bool FindRecursive(const char s[])
{
    if (s[0] == '\0')
        return false;

    if (IsGroupAt(s))
        return true;

    return FindRecursive(s + 1);
}

// Рекурсивна заміна
void ReplaceRecursive(const char s[], char result[])
{
    if (s[0] == '\0')
    {
        result[0] = '\0';
        return;
    }

    if (IsGroupAt(s))
    {
        result[0] = '*';
        result[1] = '*';

        ReplaceRecursive(s + 3, result + 2);
    }
    else
    {
        result[0] = s[0];

        ReplaceRecursive(s + 1, result + 1);
    }
}

int main()
{
    const int SIZE = 256;

    char s[SIZE];
    char result[SIZE];

    cout << "Enter string: ";
    cin.getline(s, SIZE);

    cout << "Original: " << s << endl;

    bool found = FindRecursive(s);

    cout << "Found: "
        << (found ? "Yes" : "No") << endl;

    ReplaceRecursive(s, result);

    cout << "Modified: " << result << endl;

    return 0;
}
