// Lab-08.1-String.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 8.1
// Варіант 31 — string-метод

#include <iostream>
#include <string>

using namespace std;

// Пошук OGO або AGA
bool FindString(const string& s)
{
    return s.find("OGO") != string::npos ||
        s.find("AGA") != string::npos;
}

// Заміна кожної трійки OGO або AGA на **
void ReplaceString(string& s)
{
    size_t start = 0;

    while (true)
    {
        size_t p1 = s.find("OGO", start);
        size_t p2 = s.find("AGA", start);

        size_t pos = string::npos;

        if (p1 == string::npos)
        {
            pos = p2;
        }
        else if (p2 == string::npos)
        {
            pos = p1;
        }
        else
        {
            pos = (p1 < p2) ? p1 : p2;
        }

        if (pos == string::npos)
            break;

        s.replace(pos, 3, "**");

        start = pos + 2;
    }
}

int main()
{
    string s;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Original: " << s << endl;

    bool found = FindString(s);

    cout << "Found: "
        << (found ? "Yes" : "No") << endl;

    ReplaceString(s);

    cout << "Modified: " << s << endl;

    return 0;
}
