#include <iostream>
using namespace std;

#define MemSize 30						 //����������� ������

template <class Type>
class Stack
{
private:
	Type *pMem;
	int Size;
	int Top;

	int GetSize() const { return Size; }
	//int* GetpMem() const { return pMem; }
public:
	Stack();
	Stack(int n);
	Stack(const Stack &s);
	~Stack();
	
	bool IsFull();
	bool IsEmpty();

	Type Put();								//����� � ������� ������� �������
	void Push(int element);					//�������� �������
	Type Peek() const;						//���������� ������� ������� ��� ��������

	void SetSize(int n);
	
	Stack& operator=(const Stack &s);
	bool operator==(const Stack &s) const;  
	bool operator!=(const Stack &s) const;  
};

template <class Type>
Stack<Type>::Stack() {
	pMem = new Type[MemSize];
	Size = MemSize;
	Top = -1;
	for (int i = 0; i < Size; i++) {
		pMem[i] = 0;
	}
}

template <class Type>
Stack<Type>::Stack(int n) {
	if (n<0) {
		throw invalid_argument("������ ����� < 0, �����������");
	}
	pMem = new Type[n];
	Size = n;
	Top = -1;
	for (int i = 0; i < Size; i++) {
		pMem[i] = 0;
	}
}

template <class Type>
Stack<Type>::~Stack() {
	delete[]pMem;
}

template <class Type>
Stack<Type>::Stack(const Stack &s) {
	Size = s.GetSize();
	pMem = new Type[Size];
	Top = s.Top;

	for (int i = 0; i < Size; i++) {
		pMem[i] = s.pMem[i];
	}
}

template<class Type>
bool Stack<Type>::IsEmpty() {
	if (Top == -1) {
		return true;
	}
	return false;
}

template<class Type>
bool Stack<Type>::IsFull() {
	if (Top == Size - 1) {
		return true;
	}
	return false;
}

template <class Type>
void Stack<Type>::Push(int element) {
	if (this->IsFull()) {
		throw ("���� ����������!");
	}
	//Top++;
	pMem[++Top] = element;
}

template <class Type>
Type Stack<Type>::Put() {
	if (this->IsEmpty()) {
		throw ("���� ����!");
	}
	return pMem[Top--];
}

template <class Type>
Type Stack<Type>::Peek() const {
	if (Top == -1) {
		throw ("���� ����!");
	}
	return pMem[Top];
}

template <class Type>
void Stack<Type>::SetSize(int n) {
	if (n<0) {
		throw invalid_argument("������ ����� < 0");
	}
	if (n<Top + 1) {
		throw invalid_argument("New Size < Top");
	}

	Type *p = new Type[Top + 1];
	for (int i = 0; i < Top + 1; i++) {
		p[i] = pMem[i];
	}

	Size = n;
	delete[]pMem;
	pMem = new Type[Size];
	for (int i = 0; i < Top + 1; i++) {
		pMem[i] = p[i];
	}
	for (int i = Top + 1; i < Size; i++) {
		pMem[i] = 0;
	}
}

template <class Type>
Stack<Type>& Stack<Type>::operator=(const Stack& s) {
	if (pMem == s.pMem) {
		return *this;
	}
	Size = s.Size;
	Top = s.Top;
	delete[]pMem;
	pMem = new Type[Size];
	for (int i = 0; i < Size; i++) {
		pMem[i] = s.pMem[i];
	}
	return *this;
}

template <class Type>
bool Stack<Type>::operator==(const Stack& s) const {
	if ((Size == s.Size) && (Top == s.Top)) {
		for (int i = 0; i < Size; i++) {
			if (pMem[i] != s.pMem[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

template <class Type>
bool Stack<Type>::operator!=(const Stack &s) const {
	if ((*this) == s) {
		return false;
	}
	return true;
}

