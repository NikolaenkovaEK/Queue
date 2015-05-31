#include <iostream>
using namespace std;
const int N=6; //размер очереди
struct Queue
{
int data[N]; //массив данных
int first; //указатель на начало
int last; //указатель на конец
};
void Creation(Queue *Q) //создание очереди
{ Q->first=Q->last=1; }
bool Full(Queue *Q) //проверка очереди на пустоту
{
if (Q->last==Q->first) return true;
else return false;
}
void Add(Queue *Q) //добавление элемента
{
int value;
cout<<"\nЗначение > "; cin>>value;
if ((Q->last%(N-1))+1==Q->first)
cout<<"\nОчередь заполнена\n\n";
else
{
Q->data[Q->last]=value;
Q->last=(Q->last%(N-1))+1;
cout<<endl<<"Элемент добавлен в очередь\n\n";
}
}
void Delete(Queue *Q) //удаление элемента
{
Q->first=(Q->first%(N-1))+1;
cout<<endl<<"Элемент удален из очереди\n\n";
}
int Top(Queue *Q) //вывод начального элемента
{ return Q->data[Q->first]; }
int Size(Queue *Q) //размер очереди
{
if (Q->first>Q->last) return (N-1)-(Q->first-Q->last);
else return Q->last-Q->first;
}
void main() //главная функция
{
setlocale(LC_ALL,"Rus");
Queue Q;
Creation(&Q);
char number;
do
{
cout<<"1. Добавить элемент"<<endl;
cout<<"2. Удалить элемент"<<endl;
cout<<"3. Вывести верхний элемент"<<endl;
cout<<"4. Узнать размер очереди"<<endl;
cout<<"0. Выйти\n\n";
cout<<"Номер команды > "; cin>>number;
switch (number)
{
case '1': Add(&Q);
break;
//-----------------------------------------------
case '2':
if (Full(&Q)) cout<<endl<<"Очередь пуста\n\n";
else Delete(&Q);
break;
//-----------------------------------------------
case '3':
if (Full(&Q)) cout<<endl<<"Очередь пуста\n\n";
else cout<<"\nНачальный элемент: "<<Top(&Q)<<"\n\n";
break;
//-----------------------------------------------
case '4':
if (Full(&Q)) cout<<endl<<"Очередь пуста\n\n";
else cout<<"\nРазмер очереди: "<<Size(&Q)<<"\n\n";
break;
//-----------------------------------------------
case '0': break;
default: cout<<endl<<"Команда не определена\n\n";
break;
}
} while(number!='0');
system("pause");
}
