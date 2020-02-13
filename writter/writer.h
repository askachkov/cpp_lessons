#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Writer {
	class File {
	private:
		fstream file;
	public:
		File(string name);
		~File();
		fstream& operator*();
	};

private:
	File file;
public:
	Writer(const string&);
	~Writer();
	Writer& operator<<(const string& str);
	string& operator>>(string& str);
	string content();

};

ostream& operator<<(ostream &os, Writer& wr);
