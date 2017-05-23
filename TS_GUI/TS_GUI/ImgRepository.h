#pragma once
class ImgRepository
{
private:
	list<string> imgList;
	string pathToImg;
public:
	ImgRepository(string path);
	~ImgRepository();
};

