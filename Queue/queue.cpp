#include <iostream>
using namespace std;
const int N=6; //������ �������
struct Queue
{
int data[N]; //������ ������
int first; //��������� �� ������
int last; //��������� �� �����
};
void Creation(Queue *Q) //�������� �������
{ Q->first=Q->last=1; }
bool Full(Queue *Q) //�������� ������� �� �������
{
if (Q->last==Q->first) return true;
else return false;
}
void Add(Queue *Q) //���������� ��������
{
int value;
cout<<"\n�������� > "; cin>>value;
if ((Q->last%(N-1))+1==Q->first)
cout<<"\n������� ���������\n\n";
else
{
Q->data[Q->last]=value;
Q->last=(Q->last%(N-1))+1;
cout<<endl<<"������� �������� � �������\n\n";
}
}
void Delete(Queue *Q) //�������� ��������
{
Q->first=(Q->first%(N-1))+1;
cout<<endl<<"������� ������ �� �������\n\n";
}
int Top(Queue *Q) //����� ���������� ��������
{ return Q->data[Q->first]; }
int Size(Queue *Q) //������ �������
{
if (Q->first>Q->last) return (N-1)-(Q->first-Q->last);
else return Q->last-Q->first;
}
void main() //������� �������
{
setlocale(LC_ALL,"Rus");
Queue Q;
Creation(&Q);
char number;
do
{
cout<<"1. �������� �������"<<endl;
cout<<"2. ������� �������"<<endl;
cout<<"3. ������� ������� �������"<<endl;
cout<<"4. ������ ������ �������"<<endl;
cout<<"0. �����\n\n";
cout<<"����� ������� > "; cin>>number;
switch (number)
{
case '1': Add(&Q);
break;
//-----------------------------------------------
case '2':
if (Full(&Q)) cout<<endl<<"������� �����\n\n";
else Delete(&Q);
break;
//-----------------------------------------------
case '3':
if (Full(&Q)) cout<<endl<<"������� �����\n\n";
else cout<<"\n��������� �������: "<<Top(&Q)<<"\n\n";
break;
//-----------------------------------------------
case '4':
if (Full(&Q)) cout<<endl<<"������� �����\n\n";
else cout<<"\n������ �������: "<<Size(&Q)<<"\n\n";
break;
//-----------------------------------------------
case '0': break;
default: cout<<endl<<"������� �� ����������\n\n";
break;
}
} while(number!='0');
system("pause");
}