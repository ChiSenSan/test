// TestFile.cpp
#include <iostream.h>
#include "MainDefs.h"
#include "File.h"
#include "TextFile.h"

bool Open(CFile& rfile, const char* pszFlags)
{
    char buffer[512];

    cout << "ファイル名を指定して下さい > " << flush;
    cin >> buffer;
    return rfile.Open(buffer, pszFlags);
}

void Write(CTextFile& rtxt)
{
    char buffer[512];

    cout << "何を書き込みますか > " << flush;
    cin >> buffer;
    rtxt.WriteString(buffer);
}

void Load(CFile& rbin)
{
    char buffer[512];
    int  nRead;

    nRead = rbin.Read(buffer, numof(buffer));
    buffer[nRead] = 0;
    cout << buffer << endl;
}

int main()
{
	CTextFile txt("Test.txt","r");
	#if 0
    CFile     bin;
    CTextFile txt;

    if(Open(txt, "w") == false)
        return 0;
    Write(txt);
    txt.Close();

    if(Open(bin, "r") == false)
        return 0;
    Load(bin);
    bin.Close();
	#endif
    return 0;
}