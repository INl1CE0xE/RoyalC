#pragma once
#include <string>

//Типы токенов
enum class TokenType {
	LET,
	PRINT,
	ID,
	NUMBER,
	PLUS,
	MINUS,
	STAR,
	SLASH,
	ASSIGN,
	SEMICOLON,
	LPAREN,
	RPAREN,
	INVALID,
	END_OF_FILE
};

//Объект токен
struct Token {
	TokenType type;
	std::string value;
	int line, col;
};