#include <iostream>
#include <string>
#include <climits>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251); // кодировка ввода
    SetConsoleOutputCP(1251); // кодировка вывода

    int a;
    int b;
    string operation;
    char target;

    while (true)
    {
        cout << "Введите операцию (+, -, *, /, ++, --) или exit для выхода: ";
        cin >> operation;

        if (operation == "exit")
        {
            break;
        }

        cout << "Введите первое число: ";

        if (!(cin >> a))
        {
            cout << "Ошибка! Введите целое число допустимого размера.\n";
            return 0;
        }

        cout << "Введите второе число: ";

        if (!(cin >> b))
        {
            cout << "Ошибка! Введите целое число допустимого размера.\n";
            return 0;
        }

        if (operation == "+")
        {
            if ((b > 0 && a > INT_MAX - b) ||
                (b < 0 && a < INT_MIN - b))
            {
                cout << "Переполнение!\n";
            }
            else
            {
                cout << "Ответ: " << a + b << "\n";
            }
        }
        else if (operation == "-")
        {
            if ((b < 0 && a > INT_MAX + b) ||
                (b > 0 && a < INT_MIN + b))
            {
                cout << "Переполнение!\n";
            }
            else
            {
                cout << "Ответ: " << a - b << "\n";
            }
        }
        else if (operation == "*")
        {
            bool overflow = false;

            if (a > 0)
            {
                if (b > 0 && a > INT_MAX / b)
                {
                    overflow = true;
                }

                else if (b < 0 && b < INT_MIN / a)
                {
                    overflow = true;
                }
            }
            else if (a < 0)
            {
                if (b > 0 && a < INT_MIN / b)
                {
                    overflow = true;
                }

                else if (b < 0 && a < INT_MAX / b)
                {
                    overflow = true;
                }
            }

            if (overflow)
            {
                cout << "Переполнение!\n";
            }

            else
            {
                cout << "Ответ: " << a * b << "\n";
            }
        }
        else if (operation == "/")
        {
            if (b == 0)
            {
                cout << "На ноль делить нельзя!\n";
            }
            else if (a == INT_MIN && b == -1)
            {
                cout << "Переполнение!\n";
            }
            else
            {
                cout << "Ответ: " << (float)a / b << "\n";
            }
        }
        else if (operation == "++" || operation == "--")
        {
            cout << "Какую переменную изменить (a или b)? ";
            cin >> target;

            if (target == 'a')
            {
                if (operation == "++")
                {
                    if (a == INT_MAX)
                    {
                        cout << "Переполнение!\n";
                    }

                    else
                    {
                        a++;
                        cout << "Новое значение a: " << a << "\n";
                    }
                }
                else
                {
                    if (a == INT_MIN)
                    {
                        cout << "Переполнение!\n";
                    }

                    else
                    {
                        a--;
                        cout << "Новое значение a: " << a << "\n";
                    }
                }
            }
            else if (target == 'b')
            {
                if (operation == "++")
                {
                    if (b == INT_MAX)
                    {
                        cout << "Переполнение!\n";
                    }

                    else
                    {
                        b++;
                        cout << "Новое значение b: " << b << "\n";
                    }
                }
                else
                {
                    if (b == INT_MIN)
                    {
                        cout << "Переполнение!\n";
                    }

                    else
                    {
                        b--;
                        cout << "Новое значение b: " << b << "\n";
                    }
                }
            }
            else
            {
                cout << "Неизвестная переменная!\n";
            }
        }
        else
        {
            cout << "Неизвестная операция!\n";
        }
    }
    return 0;
}