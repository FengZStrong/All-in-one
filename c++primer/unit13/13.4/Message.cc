#include <iostream>
#include "Message.h"

using namespace std;

/* implement class Message */

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
	add_to_folders(m);
}

Message& Message::operator=(const Message &m) {
	remove_from_folders();
	contents = m.contents;
	folders = m.folders;
	add_to_folders(m);

	return *this;
}

Message::~Message() {
	remove_from_folders();
}

void Message::add_to_folders(const Message &m) {
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}

void Message::remove_from_folders() {
	for (auto f : folders) {
		f->remMsg(this);
	}
}

void Message::save(Folder &f) {
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f) {
	folders.erase(&f);
	f.remMsg(this);
}

/* implement class Folder */

void Folder::addMsg(Message *pm) {
	messages.insert(pm);
}

void Folder::remMsg(Message *pm) {
	messages.erase(pm);
}