#include <iostream>
#include "CandyBox.h"

int main(void)
{
	CBox myBox {4.0, 3.0, 2.0};
	CCandyBox myCandyBox;
	CCandyBox myMintBox {"Wafer Thin Mints"};
	
	std::cout << "myBox occupies" << sizeof myBox
	<< " bytes" << std::endl
	<< "myCandybox occupies " << sizeof myCandyBox
	<< "bytes" << std::endl
	<< "myMinitBox occupies" << sizeof myMintBox
	<< "bytes:"  << std::endl;
}