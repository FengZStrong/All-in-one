#include <string>
#include "Window_mgr.h"

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

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

Screen &Screen::set(const char c)
{
	contents[cursor] = c;

	return *this;
}

Screen &Screen::set(const pos ht, const pos wd, const char c)
{
	contents[ht * wd] = c;

	return *this;
}

Screen &Screen::display(std::ostream &os)
{
	do_display(os);

	return *this;
}

const Screen &Screen::display(std::ostream &os) const
{
	do_display(os);

	return *this;
}

Screen::pos Screen::size() const
{
	return height * width;
}