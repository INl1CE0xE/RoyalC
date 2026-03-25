#pragma once
#include <iostream>
#include <string>
#include <fstream>

//Класс File. Хранит дескриптор файла и геттер.
class File {
protected:
	std::string filename;
	std::ifstream sFile;
public:
	//Открывает файл
	void openFile();
	//Геттер для файла
	std::ifstream& getFile();
	//Закрывает файл
	void closeFile();
	//Конструктор файла
	File(std::string f);
	File(File&& f)noexcept;
	~File() = default;
};

bool ValideFileName(const std::string& filename);