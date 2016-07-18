#include <iostream>
#include <queue>

template <typename T>
class stack_by_queues
{
public:
	stack_by_queues()
		: flag(true)
	{}
	
	void Push(const T &data)
	{
		if (flag)
			q1.push(data);
		else
			q2.push(data);
	}
	
	void Pop()
	{
		if (flag)
		{
			if (!q1.empty())
			{
				int sz = q1.size();

				while (--sz)
				{
					q2.push(q1.front());
					q1.pop();
				}
				flag = false;
			}
			q1.pop();
		}
		else
		{
			if (!q2.empty())
			{
				int sz = q2.size();
				
				while (--sz)
				{
					q1.push(q2.front());
					q2.pop();
				}
				flag = true;
			}
			q2.pop();
		}
	}
	
	T & Top()
	{
		if (flag)
		{
			return q1.back();
		}
		else
			return q2.back();
	}

	bool Empty()
	{
		if (flag)
			return q1.empty();
		else
			return q2.empty();
	}

	size_t Size()
	{
		if (flag)
			return q1.size();
		else
			return q2.size();
	}

	size_t capacity()
	{
		return q1.capacity();
	}

private:
	std::queue<T> q1;
	std::queue<T> q2;
	bool flag;	//标记当前存放元素主队列:true代表q1,false代表q2
};

int main()
{
//	stack_by_queues<int> s;
//
//	s.Push(1);
//	std::cout << s.Top() << std::endl;
//	s.Push(2);
//	std::cout << s.Top() << std::endl;
//	s.Push(3);
//	std::cout << s.Top() << std::endl;
//	s.Push(4);
//	std::cout << s.Top() << std::endl;
//
//	std::cout << std::endl;
//	
//	s.Pop();
//	std::cout << s.Top() << std::endl;
//	s.Pop();
//	std::cout << s.Top() << std::endl;
//	s.Pop();
//	std::cout << s.Top() << std::endl;
//	s.Pop();
//	
//	if (!s.Empty())
//	{
//		std::cout << s.Top() << std::endl;
//	}
//	else
//	{
//		std::cout << "no elem !" << std::endl;
//	}
	
//	std::queue<int> q;
//	q.back();				//没反应
//	std::cout << q.back() << std::endl;	//段错误

	return 0;
}
