#include <iostream>
#include <iomanip>
#include <locale>
#include <cstring>

using namespace std;

struct Data
{
    char property[20];
    char propertytype[9];
    int square;
    int quantity;
    char date[10];
} Data[3];

void my_center(const char* s, int wLine)
{
    int w = strlen(s);
    int delta = (wLine - w) / 2 - 1;
    cout << left;
    cout.width(delta); cout << " ";
    cout << s;
    cout.width(delta); cout << " ";
}

void draw_line()
{
    cout << "+--------------------------------------------------------------------------------------------+" << endl;
}

void header()
{
    draw_line();
    cout.width(125); cout << left << "|Сельскохозяйственные предприятия"; cout << "|" << endl;
    draw_line();
    cout << "| Название |";
    cout << " Вид собственности |";
    cout << " Площадь земли (га) |";
    cout << " Кол. работников |";
    my_center("Дата", 18); cout << "|" << endl;
    draw_line();
}

void note()
{
    cout.width(132); cout << left << "|Вид собственности: Д - государственная, Ч - частная, К - кооперативная"; cout << "|" << endl;
    draw_line();
}

void inputValues(int i)
{
    cout << "Ввод значений " << i << " записи" << endl;
    cout << "Название: ";
    cin >> Data[i].property;
    cout << "Вид собственности: ";
    cin >> Data[i].propertytype;
    cout << "Площадь земли (га): ";
    cin >> Data[i].square;
    cout << "Кол. работников: ";
    cin >> Data[i].quantity;
    cout << "Дата: ";
    cin >> Data[i].date;
}

void printStrings(int i)
{
    cout << "|" << left << setw(16) << Data[i].property;
    cout << "|" << left << setw(9) << Data[i].propertytype;
    cout.precision(3); cout << "|" << right << fixed << setw(29) << Data[i].square;
        cout << "|" << left << setw(22) << Data[i].quantity;
    cout << "| " << left << setw(11) << Data[i].date;
    cout << "|" << endl;
    draw_line();
}

int main()
{

    setlocale(LC_ALL, "Russian");

    inputValues(0);
    cout << endl;
    inputValues(1);
    cout << endl;
    inputValues(2);
    cout << endl;

    header();

    printStrings(0);
    printStrings(1);
    printStrings(2);

    note();

    cout << endl;

    return 0;
}