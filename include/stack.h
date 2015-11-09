#define MemSize 30
#include <iostream>
using namespace std;

class Stack
{
private:
	int *pMem;
	int Size;
	int Top;
public:
	Stack();
	Stack(int n);
	Stack(const Stack &s);
	~Stack();
	
	void SetSize(int n);
	int GetSize() const { return Size; }
	int* GetpMem() const { return pMem; }
	bool IsEmpty();
	bool IsFull();
	int Put();								//c ��������� �������� ��������
	void Push(int element);					//�������� �������
	int Peek() const;								//���������� ������� �������
	Stack& operator=(const Stack &s);
	bool operator==(const Stack &s) const;  // ���������
	bool operator!=(const Stack &s) const;  // ���������
};