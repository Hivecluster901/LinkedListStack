#pragma once

class Stack
{
private:
	class Element
	{
	public:
		Element(int val)
			:
			x(val)
		{
		}
		int x;
		Element* ptr_to_next = nullptr;
	};
public:
	void Push(int val)
	{
		if (Empty())
		{
			Element* e = new Element(val);
			firstPtr = e;
		}
		else
		{
			Element* e = new Element(val);
			Element* ptr = firstPtr;
			while (ptr->ptr_to_next != nullptr)
			{
				ptr = ptr->ptr_to_next;
			}
			ptr = e;
		}
	}
	int Pop()
	{
		Element** ptr1 = nullptr;
		Element* ptr2 = firstPtr;
		while (ptr2->ptr_to_next != nullptr)
		{
			ptr2 = ptr2->ptr_to_next;
		}
		ptr1 = &ptr2;
		int value = ptr2->x;
		delete ptr2;
		*ptr1 = nullptr;
		return value;
	}
	int Size() const
	{
		Element* ptr = firstPtr;
		int size = 0;
		while (ptr->ptr_to_next != nullptr)
		{
			ptr = ptr->ptr_to_next;
			size++;
		}
		return size;
	}
	bool Empty() const
	{
		return firstPtr == nullptr;
	}
private:
	Element* firstPtr = nullptr;
};