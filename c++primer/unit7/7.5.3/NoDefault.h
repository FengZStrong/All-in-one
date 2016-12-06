class NoDefault
{
public:
	NoDefault(int argv):value(argv){};
private:
	int value;
};

class C 
{
public:
	C():nd(NoDefault(0)){};
private:
	NoDefault nd;
};