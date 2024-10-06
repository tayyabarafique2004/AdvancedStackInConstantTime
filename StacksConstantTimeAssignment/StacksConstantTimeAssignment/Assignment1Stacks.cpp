#include<iostream>
#include<vector>
typedef int itemType;
#define max 100
using namespace std;
vector<itemType>ans;
class Stack
{
private:
	itemType top;
	itemType *items = new itemType[max];
	itemType *miniStack = new itemType[max];

public:
	Stack();
	void push(itemType);
	void push2(itemType);
	void pop();
	itemType getMin();
	itemType getSize();
	bool isEmpty();
	bool isFull();
	itemType peek();
};

Stack::Stack()
{
	top = -1;

}

void Stack::push(itemType item)
{
	if (isFull())
	{
		cout << "Stack Overflow!" << endl;
		return;
	}
	top++;
	items[top] = item;
	if (top == 0)
	{
		miniStack[top] = item;
	}
	else
	{
		if (item < miniStack[top - 1])
		{
			miniStack[top] = item;
		}
		else
			miniStack[top] = miniStack[top - 1];
	}
	

}

void Stack::push2(itemType item)
{
	if (isFull())
	{
		cout << "Stack Overflow!" << endl;
		return;
	}
	top++;
	items[top] = item;
}

void Stack::pop()
{
	if (isEmpty())
	{
		cout << "Stack Underflow!" <<endl;
		return;
	}
	top--;
}

itemType Stack::getMin()
{
	return miniStack[top];
}

itemType Stack::getSize()
{
	return (top+1);
}

bool Stack::isEmpty()
{
	return (top == -1);
}

bool Stack::isFull()
{
	return(top == max);
}


itemType Stack::peek()
{
	if (!isEmpty())
	{
		return items[top];
	}
	return -1; 
}
void findNextGreater(itemType arrElement,Stack &stGreater)
{
	if (stGreater.isEmpty())
	{
		ans.push_back(-1);
	}
	else
	{
		while (stGreater.isEmpty()==false && arrElement >= stGreater.peek())
		{
			stGreater.pop();
		}
		ans.push_back(stGreater.peek());
	}
	stGreater.push2(arrElement);

}


int main()
{
	Stack stack;
	Stack stGreater;
	cout << "Pushing Elements in the Stack: " << endl;
	stack.push(7);
	stack.push(2);
	stack.push(5);
	stack.push(3);
	stack.push(2);
	stack.push(9);
	stack.push(1);
	cout << "Current Size of the Stack:  "<<stack.getSize()<<endl;
	cout << "Current Minimum Element in the Stack: " << stack.getMin();
	cout << "Popping 2 Elements: "<<endl;
	stack.pop();
	stack.pop();
		cout << "Current Size of the Stack:  "<<stack.getSize()<<endl;
	cout << "Current Minimum Element in the Stack: " << stack.getMin();
	cout << endl;
	itemType array[] = { 4,5,2,25 };
	itemType size = sizeof(array) / sizeof(array[0]);

	for (int i = size - 1; i >= 0; i--)
	{
		findNextGreater(array[i],stGreater);
	}
	reverse(ans.begin(), ans.end());
	cout << endl;
	cout << "Next Greater Elements: ";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;

}