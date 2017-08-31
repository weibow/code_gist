#pragma once
#include <cstring>


class CBox
{
public:
	double m_Length;
	double m_Width;
	double m_Height;
	
	explicit CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0):
				m_Length {lv}, m_Width {mv}, m_Height {hv} {}
};

class CCandyBox : CBox
{
public:
	char* m_Contents;
	
	explicit CCandyBox(const char* str = "Candy")
	{
		size_t length {strlen{str) + 1};
		m_Contents = new char[length];
		strcpy_s(m_Contents, length, str);
	}
	
	CCandyBox(const CCandyBox& box) = delete;
	CCandyBox & operator= (const CCandyBox& box) = delete;
	
	~CCandyBox();
	{	delete[] m_Contents;}
};
		
