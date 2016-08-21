#define _CRT_SECURE_NO_WARNINGS

/*
 * ����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
 * ����:
 * 1.��¼���8�������¼������ͬ�Ĵ����¼(���ļ����ƺ��к���ȫƥ��)ֻ��¼һ��������������ӣ�(�ļ����ڵ�Ŀ¼��ͬ���ļ������к���ͬҲҪ�ϲ�)
 * 2.����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���(����ļ�����ͬ����ֻ���ļ����ĺ�16���ַ����к���ͬ��Ҳ��Ҫ�ϲ�)
 * 3.������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·��
 * ��������:
 * һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������
 * �ļ�·��Ϊwindows��ʽ
 * �磺E:\V1R2\product\fpgadrive.c 1325
 * �������:
 * �����еļ�¼ͳ�Ʋ�������������ʽ���ļ�������������Ŀ��һ���ո��������: fpgadrive.c 1325 1 
 * ���������Ŀ�Ӷൽ��������Ŀ��ͬ������£����������һ�γ���˳������
 * �������8����¼����ֻ���ǰ8����¼.
 * ����ļ����ĳ��ȳ���16���ַ�����ֻ�����16���ַ�
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