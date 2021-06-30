#include<iostream>
#include<string>
#include "grid.h"


int main()
{
	setSize(15, 12);
	const int middle = getCols() / 2;
	setChar(6, middle, 'E');
	setChar(8, middle, 'L');
	setChar(9, middle, 'O');
	setChar(7, middle, 'L');
	setChar(5, middle, 'H');
	if (getChar(6, middle) == 'E')
		setChar(10, middle, '!');
	draw();
}

