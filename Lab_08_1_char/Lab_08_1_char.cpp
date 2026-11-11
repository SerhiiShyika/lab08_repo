// Lab-08.1-char.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 8.1
// Варіант 31 — char-символьний метод

#include <iostream>
#include <cstring>
using namespace std;

// Пошук стандартними функціями C
bool FindChar(const char s[])
{
    return
        strstr(s, "OGO") != nullptr ||
        strstr(s, "AGA") != nullptr;
}

// Заміна стандартними функціями C
void ReplaceChar(char s[])
{
    char* current = s;

    while (true)
    {
        char* p1 = strstr(current, "OGO");
        char* p2 = strstr(current, "AGA");

        char* p = nullptr;

        if (p1 == nullptr)
        {
            p = p2;
        }
        else if (p2 == nullptr)
        {
            p = p1;
        }
        else
        {
            p = (p1 < p2) ? p1 : p2;
        }

        if (p == nullptr)
            break;

        // Видаляємо третій символ трійки,
        // зсуваючи решту разом із '\0'
        memmove(p + 2, p + 3, strlen(p + 3) + 1);

        p[0] = '*';
        p[1] = '*';

        current = p + 2;
    }
}

int main()
{
    const int SIZE = 256;

    char s[SIZE];

    cout << "Enter string: ";
    cin.getline(s, SIZE);

    cout << "Original: " << s << endl;

    bool found = FindChar(s);

    cout << "Found: "
        << (found ? "Yes" : "No") << endl;

    ReplaceChar(s);

    cout << "Modified: " << s << endl;

    return 0;
}
