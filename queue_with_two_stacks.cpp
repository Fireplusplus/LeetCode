#include <iostream>
#include <stack>

template <typename T>
class queue_by_stacks
{
private:
	void move()
	{
		if (s2.empty())
		{
			int sz = s1.size();
			while (sz--)
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
	}

public:
	void Push(const T &data)
	{
		s1.push(data);
	}

	void Pop()
	{
		move();
		s2.pop();
	}
	
	T & Front()
	{
		move();
		return s2.top();
	}

	T & Back()
	{
		return s1.top();
	}

	size_t Size()
	{
		return s1.size() + s2.size();
	}

	size_t Capacity()
	{
		return s1.capacity() + s2.capacity();
	}
	
	bool Empty()
	{
		return (s1.empty() && s2.empty());
	}

private:
	std::stack<T> s1;
	std::stack<T> s2;
};

int main()
{
	queue_by_stacks<int> q;
	
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	
	std::cout << q.Front() << std::endl;
	q.Pop();
	std::cout << q.Front() << std::endl;
	q.Pop();
	std::cout << q.Front() << std::endl;
	q.Pop();
	std::cout << q.Front() << std::endl;
	q.Pop();

	return 0;
}
