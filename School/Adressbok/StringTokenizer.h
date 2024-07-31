
#ifndef __STRINGTOKENIZER_H__
#define __STRINGTOKENIZER_H__

class StringTokenizer
{
private:
	char *token;
	char spliter;
	unsigned int pos;
	int tokens;
	int curpos;
public:
	void Reset();
	StringTokenizer(char*,char);
	~StringTokenizer();
	char* NextToken();
	bool HasMoreTokens();
};
#endif