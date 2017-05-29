#include "stdafx.h"
#include <string>
#include <vector>
#include <Windows.h>

#include "ImgRepository.h"

using namespace std;
ImgRepository::ImgRepository(string path)
{
	/*pathtoimg = path;
	win32_find_data fd;
	handle hfind = ::findfirstfile(wstring(pathtoimg.begin(), pathtoimg.end()).c_str(), &fd);
	if (hfind != invalid_handle_value)
	{
		do
		{
			if (!(fd.dwfileattributes & file_attribute_directory)) 
			{
				wstring ws(fd.cfilename);
				string str(ws.begin(), ws.end());
				imglist.push_back(str);
			}
		}
		while (::findnextfile(hfind, &fd));
		findclose(hfind);
	}*/
}


ImgRepository::~ImgRepository()
{
}
