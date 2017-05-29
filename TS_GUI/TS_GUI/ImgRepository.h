#pragma once
class ImgRepository
{
private:
	std::vector<std::string> imgList;
	std::string pathToImg;
public:
	ImgRepository();
	ImgRepository(std::string);
	~ImgRepository();
};

