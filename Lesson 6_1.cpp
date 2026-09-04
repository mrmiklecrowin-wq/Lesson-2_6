#include <iostream>
#include <string>
#include <windows.h>

int function(const std::string& str, int forbidden_length) {
	if ( forbidden_length == static_cast<int>(str.size())){
		throw std::string ("bad_length");
	}
	return static_cast<int>(str.size());
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int forbidden_length = 0;
	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;
	
	while (true) {
		std::string str;
		std::cout << "Введите слово: ";
		std::cin >> str;
		
		try {
			int str_length = function(str, forbidden_length);
			std::cout << "Длина слова " << str << " равна " << str_length << std::endl;
		} catch (std::string bad_length) {
			if (bad_length== "bad_length") {
				std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
				break;
			}
		}
	}
	
	return 0;
}
