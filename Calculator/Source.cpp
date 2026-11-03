#include <iostream>
#include <string>
#include <climits>
#include <windows.h>

using namespace std;

/**
 * Выполняет сложение двух чисел с проверкой переполнения
 */
void addition(int a, int b)
{
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
    {
        cout << "Переполнение!\n";
    }

    else
    {
        cout << "Ответ: " << a + b << "\n";
    }
}

/**
 * Выполняет вычитание двух чисел с проверкой переполнения
 */
void subtraction(int a, int b)
{
    if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b))
    {
        cout << "Переполнение!\n";
    }

    else
    {
        cout << "Ответ: " << a - b << "\n";
    }
}

/**
 * Выполняет умножение двух чисел с проверкой переполнения
 */
void multiplication(int a, int b)
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

/**
 * Выполняет деление двух чисел с проверкой ошибок
 */
void division(int a, int b)
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

/**
 * Увеличивает число на единицу с проверкой переполнения.
 */
int increment(int a)
{
    if (a == INT_MAX)
    {
        cout << "Переполнение!\n";
    }
    else
    {
        a++;
    }

    return a;
}
/**
 * Уменьшает число на единицу с проверкой переполнения.
 */
int decrement(int a)
{
    if (a == INT_MIN)
    {
        cout << "Переполнение!\n";
    }
    else
    {
        a--;
    }

    return a;
}

/**
 * Главная функция программы
 * Организует ввод данных, выполнение операций и вывод результатов
 */
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

        // Выход из программы
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

        if (operation == "+" || operation == "-" || operation == "*" || operation == "/")
        {
            switch (operation[0])
            {
            case '+':
                addition(a, b);
                break;

            case '-':
                subtraction(a, b);
                break;

            case '*':
                multiplication(a, b);
                break;

            case '/':
                division(a, b);
                break;
            }
        }
        else if (operation == "++" || operation == "--")
        {
            // Запрашиваем, какую переменную нужно изменить.
            cout << "Какую переменную изменить (a или b)? ";
            cin >> target;

            if (target == 'a')
            {
                if (operation == "++")
                {
                    a = increment(a);
                    cout << "Новое значение a: " << a << "\n";
                }
                else
                {
                    a = decrement(a);
                    cout << "Новое значение a: " << a << "\n";
                }
            }

            else if (target == 'b')
            {
                if (operation == "++")
                {
                    b = increment(b);
                    cout << "Новое значение b: " << b << "\n";
                }

                else
                {
                    b = decrement(b);
                    cout << "Новое значение b: " << b << "\n";
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