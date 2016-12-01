#include <iostream>
#include <string>

class Screen
{
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd):height(ht),width(wd),contents(ht * wd, ' '){};
	Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht * wd, c){};
	char get() const
	{
		return contents[cursor];
	}

	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	Screen &set(const char c);
	Screen &set(const pos ht, const pos wd, const char c);

	Screen &display(std::ostream &os);
	const Screen &display(std::ostream &os) const;
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const
	{
		os << contents;
	}
};