#include <string>
#include <set>

class Folder;

class Message
{
friend class Folder;
public:
	explicit Message(const std::string &str = "") : contents(str) {}
	Message(const Message &);
	Message& operator=(const Message&);
	~Message();

	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_folders(const Message&);
	void remove_from_folders();
};

class Folder
{
public:
	void addMsg(Message*);
	void remMsg(Message*);
private:
	std::set<Message*> messages;
};