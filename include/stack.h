#include <iostream>
using namespace std;

#define MemSize 30						 //стандартный размер

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

	int Put();								//взять и удалить верхний элемент
	void Push(int element);					//добавить элемент
	int Peek() const;						//посмотреть верхний элемент без удаления

	void SetSize(int n);
	
	Stack& operator=(const Stack &s);
	bool operator==(const Stack &s) const;  
	bool operator!=(const Stack &s) const;  
};