#include "stdafx.h"
#include "ImgRepository.h"
#include <list>
#include <string>
#include <Windows.h>

using namespace std;
ImgRepository::ImgRepository(string path)
{
	pathToImg = path;
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(wstring(pathToImg.begin(), pathToImg.end()).c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) 
			{
				wstring ws(fd.cFileName);
				string str(ws.begin(), ws.end());
				imgList.push_back(str);
			}
		}
		while (::FindNextFile(hFind, &fd));
		FindClose(hFind);
	}
}


ImgRepository::~ImgRepository()
{
}
