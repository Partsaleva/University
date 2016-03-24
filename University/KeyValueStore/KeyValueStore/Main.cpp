// KeyValueStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KeyValue.h"
using std::size_t;

int main()
{
	
		KeyValue keyValue;
		size_t key1 = keyValue.store("Mariana");size_t key2 = keyValue.store("Ani");
		size_t key3 = keyValue.store("Dida");size_t key4 = keyValue.store("Vili");
		size_t key5 = keyValue.store("Ivan");size_t key6 = keyValue.store("Georgi");	
		size_t key7 = keyValue.store("Petyr");size_t key8 = keyValue.store("Nikola");
		size_t key9 = keyValue.store("Kalin");size_t key10 = keyValue.store("Maria"); 
		size_t key11 = keyValue.store("Anita"); size_t key12 = keyValue.store("Dido");
		size_t key13 = keyValue.store("Viliana"); size_t key14 = keyValue.store("Ivana");
		size_t key15 = keyValue.store("Gergana");	size_t key16 = keyValue.store("Petq"); 
		size_t key17 = keyValue.store("Nikolina"); size_t key18 = keyValue.store("Kalina");
		keyValue.loadFile();
		keyValue.print();
		cout << endl;
		keyValue.load(key1); 
		keyValue.load(key2); 
		keyValue.load(key6);
		keyValue.load(key7); 
		keyValue.load(key8); 
		keyValue.load(key9);
		keyValue.load(key10);
		cout << endl;
		keyValue.erase(key14);//1 name-  
		keyValue.erase(key18);//first name 
		//keyValue.erase(key17);//second name 
		keyValue.print();
	
		return 0;
	
}

