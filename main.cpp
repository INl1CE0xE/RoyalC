#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Lexer.h"

class FileManager {};

int main() {
	std::string filename = "test.rocc";
	Lexer lexer(filename);
	std::vector<Token>& tokens{lexer.tokenChain()};
	for (auto& x : tokens) {
		std::cout << x.value;
	}
}


//Lexer работает, создает токены.
//следующее сделать парсер, для грамматической проверки.