#include <iostream>
#include <fstream>
#include <string>

#ifndef _INPUT_CHANGE_
	#define _INPUT_CHANGE_
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
#endif
