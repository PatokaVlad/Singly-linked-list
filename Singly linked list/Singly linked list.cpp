#include <iostream>

using namespace std;

template <typename T>
class List
{
public:
	List();
	~List();
	void PopFront();
	void PopBack();
	void Clear();
	void RemoveAt(int index);
	void PushBack(T data);
	void PushFront(T data);
	void Insert(T value, int index);
	int GetSize() { return Size; }

	T& operator[](const int index);

private:
	template <typename T>
	class Node
	{

	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;
};

template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()
{
	Clear();
}

template<typename T>
void List<T>::PopFront()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::PopBack()
{
	RemoveAt(Size - 1);
}

template<typename T>
void List<T>::Clear()
{
	while (Size)
	{
		PopFront();
	}
}

template<typename T>
void List<T>::RemoveAt(int index)
{
	if (index == 0)
	{
		PopFront();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::PushBack(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::PushFront(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::Insert(T value, int index)
{
	if (index == 0)
	{
		PushFront(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(value, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}

}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main()
{
	List<int> lst;
	int second = 0;
	do {
		second = 0;
		system("cls");
		cout << "Enter what you want to do:\n1-push element back;\n2-push element front\n3-delete element" << endl;

		int menu = 0;
		int again = 0;

		cin >> menu;
		switch (menu)
		{
		case 1:
			do
			{
				again = 0;
				int element = 0;
				cout << "Enter element:" << endl;
				cin >> element;
				lst.PushBack(element);
				cout << "Do again?(1-yes)" << endl;
				cin >> again;
			} while (again == 1);
			break;
		case 2:
			do
			{
				again = 0;
				int element = 0;
				cout << "Enter element:" << endl;
				cin >> element;
				lst.PushFront(element);
				cout << "Do again?(1-yes)" << endl;
				cin >> again;
			} while (again == 1);
			break;
		case 3:
			do
			{
				again = 0;
				int index = 0;
				cout << "Enter index (start from 0):" << endl;
				cin >> index;
				lst.RemoveAt(index);
				cout << "Do again?(1-yes)" << endl;
				cin >> again;
			} while (again == 1);
			break;
		default:
			cout << "Error!" << endl;
			break;
		}

		cout << "Your list:" << endl;
		for (int i = 0; i < lst.GetSize(); i++)
			cout << lst[i] << endl;

		cout << "Press 1 to try again:" << endl;
		cin >> second;
	} while (second == 1);

	return 0;
}


