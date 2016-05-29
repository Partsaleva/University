// DepedenciesResolving.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include<vector>
#include <string>
#include <sstream>

//had a great time working in a team with Maria Ilieva

using namespace std;
vector<string> data;
vector<vector<string>> all;
ifstream packages("all_packages.json");
ifstream depend("dependencies.json");
string line;

string findDepend(){
	string word;
	string beg;
	while (getline(depend, line))
	{
		stringstream iss(line);
		getline(iss, beg, '[');
		getline(iss, word, ']');

	}
	word = word.substr(1, word.length() - 2);
	return word;
}


void parse(const string& str){
	const string delimiters = " \",:[]{}";
	size_t startIndex, endIndex;

	startIndex = str.find_first_not_of(delimiters);  // start of word

	while (startIndex != string::npos)
	{
		endIndex = str.find_first_of(delimiters, startIndex);  // end of word
		if (endIndex == string::npos)
		{
			endIndex = str.length();
		}

		string word = str.substr(startIndex, endIndex - startIndex);

		data.push_back(word);

		startIndex = str.find_first_not_of(delimiters, endIndex);

	}
	if (!data.empty())
	{
		all.push_back(data);
	}

	data.clear();
}


bool isInstaled(const string& prog){
	ifstream file("installed_modules.txt");
	string line;
	while (getline(file, line))
	{
		if (line == prog)
		{
			cout << prog << " is already installed."<<endl;
			return true;
		}
	}
	return false;
}

vector<string> searchDep(string prog){
	for (size_t i = 0; i < all.size(); i++)
	{
		if (all[i][0] == prog)
		{
			return all[i];
		}
	}
	exit(1);
}

void install(string str,fstream& file){
	vector<string> dependencies, addDep;
	if (!isInstaled(str)){
		cout << "Installing " << str << '.' << endl;
		dependencies = searchDep(str);		
		file << dependencies[0] << endl;			
		if (dependencies.size() > 1){
			cout << "In order to install " << str << " we need " << dependencies[1];
			addDep.push_back(dependencies[1]);
			for (size_t j = 2; j < dependencies.size(); j++)
			{
				cout << " and " << dependencies[j];
				addDep.push_back(dependencies[j]);
			}
			cout << '.';
			cout << endl;
		}
	}
	
	for (size_t i = 0; i < addDep.size(); i++)
	{
		install(addDep[i],file);
	}

}

int main()
{

	fstream file;
	file.open("installed_modules.txt", ios::in | ios::out | ios::app|ios::trunc);

	while (getline(packages, line))
	{
		parse(line);
	}

	install(findDepend(),file);
	cout << "All done." << endl;
	file.close();
	return 0;
}

