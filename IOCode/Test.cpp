#include "StreamDef.h"
#include "FileReadStream.h"
#include "FileWriteStream.h"

#include <iostream>
using namespace std;

#define READ_TEST

void main()
{
#ifdef WRITE_TEST
	FileWriteStream fws;
	fws.open("test.txt");
	char buf[100] = "≤›ƒ„√√";
	fws.write(buf, strlen(buf));
	fws.close();
#endif
#ifdef READ_TEST
	FileReadStream frs;
	frs.open("test.txt");
	char buf[100] = "";
	frs.read(buf, 100);
	cout << buf << frs.size() << endl;
	frs.close();
#endif
}