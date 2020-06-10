#pragma once

class Stack
{
private:
	class Element
	{
	public:
		Element(int val, Element* ptr)
			:
			val(val),
			ptr_to_next(ptr)
		{}
		int GetValue() const
		{
			return val;
		}
		Element* Disconnect()
		{
			auto ptrTemp = ptr_to_next;
			ptr_to_next = nullptr;
			return ptrTemp;
		}
		int CountNumber()
		{
			if (ptr_to_next != nullptr)
			{
				return ptr_to_next->CountNumber() + 1;
			}
			else
			{
				return 1;
			}
		}
		Element(const Element& src)
			:
			val(src.val)
		{
			if (src.ptr_to_next != nullptr)
			{
				ptr_to_next = new Element(*src.ptr_to_next);
			}
			else
			{
				ptr_to_next = nullptr;
			}
		}
		~Element()
		{
			delete ptr_to_next;
			ptr_to_next = nullptr;
		}
	private:
		int val;
		Element* ptr_to_next;
	};
public:
	Stack() = default;
	~Stack()
	{
		delete ptr_head;
		ptr_head = nullptr;
	}
	Stack(const Stack& src)
	{
		*this = src;
	}
	Stack& operator=(const Stack& rhs)
	{
		if (!Empty())
		{
			delete ptr_head;
			ptr_head = nullptr;
		}
		if (!rhs.Empty())
		{
			this->ptr_head = new Element(*rhs.ptr_head);
		}
		return *this;
	}
	void Push(int val)
	{
		ptr_head = new Element(val, ptr_head);
	}
	int Pop()
	{
		int value;
		if (!Empty())
		{
			value = ptr_head->GetValue();
			auto ptr_old_head = ptr_head;
			ptr_head = ptr_old_head->Disconnect();
			delete ptr_old_head;
			return value;
		}
		else
		{
			return -1;
		}
	}
	int Size() const
	{
		if (ptr_head != nullptr)
		{
			return ptr_head->CountNumber();
		}
		else
		{
			return 0;
		}
	}
	bool Empty() const
	{
		return ptr_head == nullptr;
	}
private:
	Element* ptr_head = nullptr;
};