/*  
 * Given a string s consists of upper/lower-case alphabets and 
 * empty space characters' ', return the length of last word in the 
 * string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of 
 * non-space characters only.
 * For example,
 * Given s ="Hello World",
 * return5. 
 */

#include <string.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
		
        int len = strlen(s);
        const char *tail = s + len - 1;
        
        while (tail >= s && isalpha(*tail))
        	tail--;
        if (tail < s || isspace(*tail))
        	return strlen(tail + 1); 
        return 0;
    }
};

int main()
{
	Solution s;
	int ret = s.lengthOfLastWord("a");
	cout << ret << endl;

	return 0;
}
