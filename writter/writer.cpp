#include "writer.h"
#include <iostream>

using namespace std;

Writer::File::File(string path)
{
	file.open(path);
}

Writer::File::~File()
{
	file.flush();
	file.close();
}

Writer::~Writer()
{
}

Writer::Writer(const string& path):file(path)
{
}

Writer& Writer::operator<<(const string& str)
{
	*file << str;
	return *this;
}

string& Writer::operator>>(string& str)
{
	*file >> str;
	return str;
}

fstream& Writer::File::operator*()
{
	return file;
}

string Writer::content()
{
	string content;
	*file >> content;
	std::cout<<content<<std::endl;
	return content;
}

ostream& operator<<(ostream &os, Writer& wr)
{
	return (os << wr.content());
}
