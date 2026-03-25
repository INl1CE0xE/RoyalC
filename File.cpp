#include "File.h"

//Проверка на правильность расширения
bool ValideFileName(const std::string& filename) {
	std::string valideExp = "rocc";
	size_t lastDot = filename.find_last_of('.');
	if (lastDot != std::string::npos) {
		std::string expansion = filename.substr(lastDot + 1);
		//std::cout << expansion;
		return expansion == valideExp;
	}
	return false;
}


void File::openFile() {
	sFile.open(filename);
	if (!sFile.is_open()) {
		std::cout << "\nError openning file";
	}
}
std::ifstream& File::getFile() {
	return sFile;
}
void File::closeFile() {
	sFile.close();
}
//Конструктор файла
File::File(std::string f) : filename(f) {
	if (!ValideFileName(filename)) { //Проверяет валидность расширения
		std::cout << "\nName of filename incorrect! Need .rocc expansion";
	}
	openFile();
}
File::File(File&& f) noexcept : filename(std::move(f.filename)), sFile(std::move(f.sFile)) {}
//File& operator=(File&& f) noexcept{

//	filename = std::move(f.filename);
//	sFile = std::move(f.sFile);
//}

