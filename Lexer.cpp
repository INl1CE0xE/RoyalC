#include "Lexer.h"

//Класс лексер читает файл и заполняет вектор токенов. (Глуповат)
Lexer::Lexer(std::string f) : filename(f), file(f) {
	current_char = file.getFile().get();
}

//Читает символы по очереди и переводит курсор line&col
void Lexer::readChar() {
	file.getFile().get(current_char);
	column++;
	if (current_char == '\n') { line++; column = 1; }
}

//Пропускает пробелы
void Lexer::skipWhitespace() {
	while (isspace(current_char)) readChar();
}

//Заполняет буфер чисел и возвращает токен
Token Lexer::readNumber() {
	std::string digits;
	int start_Line = line, start_column = column;
	while (isdigit(current_char)) {
		digits += current_char;
		readChar();
	}
	return Token(TokenType::NUMBER, digits, start_Line, start_column);
}

//Заполняет буфер идентефикатора и возвращает токен
Token Lexer::readID() {
	std::string buffer;
	int start_Line = line, start_column = column;
	while (isalpha(current_char)) {
		buffer += current_char;
		readChar();
	}
	if (buffer == "let") {
		return Token(TokenType::LET, buffer, start_Line, start_column);
	}
	if (buffer == "print") {
		return Token(TokenType::PRINT, buffer, start_Line, start_column);
	}
	return Token(TokenType::ID, buffer, start_Line, start_column);
}

//Читает токены пока они есть.
Token Lexer::nextToken() {
	skipWhitespace();
	if (isdigit(current_char)) {
		return readNumber();
	}
	if (isalpha(current_char)) {
		return readID();
	}
	switch (current_char) {
	case '+': readChar(); return Token(TokenType::PLUS, "+", line, column);
	case '-': readChar(); return Token(TokenType::MINUS, "-", line, column);
	case '=': readChar(); return Token(TokenType::ASSIGN, "=", line, column);
	case ';': readChar(); return Token(TokenType::SEMICOLON, ";", line, column);
	case '(': readChar(); return Token(TokenType::LPAREN, "(", line, column);
	case ')': readChar(); return Token(TokenType::RPAREN, ")", line, column);
	default: return Token(TokenType::INVALID, std::string(1, current_char), line, column);
	}
}

//Создает цепочку токенов. Возвращает вектор токенов.
std::vector<Token>& Lexer::tokenChain() {
	while (!file.getFile().eof()) {
		tokens.push_back(nextToken());
	}
	return tokens;
}
