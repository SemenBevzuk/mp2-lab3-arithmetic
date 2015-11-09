#include "stack.h"

Stack::Stack()
{
	pMem = new int[MemSize];
	Size = MemSize;
	Top = -1;
	for (int i = 0; i < Size; i++)
	{
		pMem[i] = 0;
	}
}
Stack::Stack(int n) {
	if (n<0)
	{
		throw invalid_argument("Размер стэка < 0, конструктор");
	}
	pMem = new int[n];
	Size = n;
	Top = -1;
	for (int i = 0; i < Size; i++) {
		pMem[i] = 0;
	}
}
Stack::~Stack()
{
	delete[]pMem;
}

Stack::Stack(const Stack &s)
{
	Size = s.GetSize();
	pMem = new int[Size];
	Top = s.Top;

	for (int i = 0; i < Size; i++) {
		pMem[i] = s.pMem[i];
	}
}

bool Stack::IsEmpty()
{
	if (Top == -1)
	{
		return true;
	}
	return false;
}

bool Stack::IsFull() {
	if (Top == Size-1) {
		return true;
	}
	return false;
}

void Stack::Push(int element)
{
	if (this->IsFull())
	{
		throw ("Стэк переполнен!");
	}
	//Top++;
	pMem[++Top] = element;
}

int Stack::Put()
{
	if (this->IsEmpty())
	{
		throw ("Стэк пуст!");
	}
	return pMem[Top--];
}

int Stack::Peek() const
{
	if (Top == -1)
	{
		throw ("Стэк пуст!");
	}
	return pMem[Top];
}

void Stack::SetSize(int n)
{
	if (n<0) {
		throw invalid_argument("Размер стэка < 0");
	}
	if (n<Top+1)
	{
		throw invalid_argument("New Size < Top");
	}

	int *p = new int[Top+1];
	for (int i = 0; i < Top+1; i++)
	{
		p[i] = pMem[i];
	}

	Size = n;
	delete []pMem;
	pMem = new int[Size];
	for (int i = 0; i < Top+1; i++)
	{
		pMem[i] = p[i];
	}
	for (int i = Top + 1; i < Size;i++)
	{
		pMem[i] = 0;
	}
}

Stack& Stack::operator=(const Stack& s)
{
	if (pMem == s.pMem)
	{
		return *this;
	}
	Size = s.Size;
	Top = s.Top;
	delete[]pMem;
	pMem = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		pMem[i] = s.pMem[i];
	}
	return *this;
}

bool Stack::operator==(const Stack& s) const
{
	if ((Size == s.Size)&&(Top == s.Top))
	{
		for (int i = 0; i < Size; i++)
		{
			if (pMem[i] != s.pMem[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
bool Stack::operator!=(const Stack &s) const 
{
	if ((*this)==s)
	{
		return false;
	}
	return true;
}

