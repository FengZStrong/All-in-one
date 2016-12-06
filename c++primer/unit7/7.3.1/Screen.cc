#include "Screen.h"

char Screen::get(pos ht, pos wd) const
{
	pos row = ht * width;
	return contents[row + wd];
}

Screen &Screen::move(pos ht, pos wd)
{
	pos row = ht * width;
	cursor = row + wd;

	return *this;
}