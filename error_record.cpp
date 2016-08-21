#define _CRT_SECURE_NO_WARNINGS

/*
 * 开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
 * 处理:
 * 1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
 * 2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
 * 3.输入的文件可能带路径，记录文件名称不能带路径
 * 输入描述:
 * 一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
 * 文件路径为windows格式
 * 如：E:\V1R2\product\fpgadrive.c 1325
 * 输出描述:
 * 将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1 
 * 结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。
 * 如果超过8条记录，则只输出前8条记录.
 * 如果文件名的长度超过16个字符，则只输出后16个字符
 */

#include <iostream>
#include <set>
#include <string>

using namespace std;

#define _SIZE_ 128

void GetFileName(string &path)
{
	size_t pos = path.find_last_of('\\');
	if (pos == string::npos)
		return;
	pos++;
	int sub = path.size() - pos;
	if (sub > 16)
	{
		pos = path.size() - 16;
	}
	string name(path, pos);
	path = name;
}

int main()
{
	set<pair<int, pair<string, int> > > s;

	char buf1[_SIZE_];
	char buf2[_SIZE_];
	set<pair<int, pair<string, int> > >::iterator pos;
	while (scanf("%s%s", buf1, buf2) != EOF)
	{
		int line = atoi(buf2);
		int cnt = 1;
		string name(buf1);
		GetFileName(name);
		pair<string, int> second(name, line);

		pos = s.begin();
		for (int i = 0; pos != s.end(); i++, ++pos)
		{
			if (pos->second.first == second.first && pos->second.second == second.second)
			{
				cnt = pos->first + 1;
				s.erase(pos);
				break;
			}
		}

		s.insert(pair<int, pair<string, int> >(cnt, second));
	}
	pos = s.begin();
	for (int i = 0; i < 8 && pos != s.end(); i++, ++pos)
	{
		cout << pos->second.first << " ";
		cout << pos->second.second << " ";
		cout << pos->first << endl;
	}

	return 0;
}