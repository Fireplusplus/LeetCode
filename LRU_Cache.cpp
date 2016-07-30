/* 
 * Design and implement a data structure for Least Recently Used (LRU) 
 * cache. It should support the following operations: get and set.
 * get(key) - Get the value (will always be positive) of the key if 
 * the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already 
 * present. When the cache reached its capacity, it should invalidate 
 * the least recently used item before inserting a new item.
 */

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
 class LRUCache
 {
 private:
 	struct CacheNode
	{
		int key;
		int value;
		CacheNode(int k, int v)
			: key(k)
			, value(v)
		{}
	};
 public:
	LRUCache(int capacity)
	{
		this->capacity = capacity;
	}

	int get(int key)
	{
		if (cacheMap.find(key) == cacheMap.end())
			return -1;
		
		// 把当前访问的结点移到链表头部，并更新map中该结点的地址
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}

	void set(int key, int value)
	{
		if (cacheMap.find(key) == cacheMap.end())
		{
			if (cacheList.size() == capacity)
			{
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			cacheList.push_front(CacheNode(key, value));
			cacheMap[key] = cacheList.begin();
		}
		else
		{
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
private:
	list<CacheNode> cacheList;
	unordered_map<int, list<CacheNode>::iterator> cacheMap;
	int capacity;
 };

 int main()
 {
 	return 0;
 }
