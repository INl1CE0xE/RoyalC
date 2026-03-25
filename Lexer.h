#pragma once
#include <string>
#include <vector>
#include "File.h"
#include "Token.h"

//Класс лексер читает файл и заполняет вектор токенов. (Глуповат)
class Lexer {
protected:
	File file;
	std::string filename;
	char current_char{};
	int line = 1, column = 1;
	std::vector<Token> tokens;
public:
	Lexer(std::string f);

	//Читает символы по очереди и переводит курсор line&col
	void readChar();

	//Пропускает пробелы
	void skipWhitespace();

	//Заполняет буфер чисел и возвращает токен
	Token readNumber();

	//Заполняет буфер идентефикатора и возвращает токен
	Token readID();

	//Читает токены пока они есть.
	Token nextToken();

	//Создает цепочку токенов. Возвращает вектор токенов.
	std::vector<Token>& tokenChain();
};