#include <iostream>
using namespace std;

#define MemSize 30						 //����������� ������

class Stack
{
private:
	int *pMem;
	int Size;
	int Top;

	int GetSize() const { return Size; }
	int* GetpMem() const { return pMem; }
public:
	Stack();
	Stack(int n);
	Stack(const Stack &s);
	~Stack();
	
	bool IsFull();
	bool IsEmpty();

	int Put();								//����� � ������� ������� �������
	void Push(int element);					//�������� �������
	int Peek() const;						//���������� ������� ������� ��� ��������

	void SetSize(int n);
	
	Stack& operator=(const Stack &s);
	bool operator==(const Stack &s) const;  
	bool operator!=(const Stack &s) const;  
};