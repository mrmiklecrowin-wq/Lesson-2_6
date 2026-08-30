#include <iostream>
#include <windows.h>
#include <string.h>


int function(std::string str, int forbidden_length){
	
	int str_length = str.size();
	int result = 0;
	std::string bad_length = "Вы ввели слово запретной длины! До свидания";
	
	if(str_length == forbidden_length){;
		std::cout << "Длина слова " << str << " равна " << forbidden_length <<std::endl;
		return result = 0;
	}
	else {
		std::cout << bad_length;
		return result = -1;
	}
};


int main(){
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int forbidden_length = 0;
	std::string str = " ";
	int result = 0;
	
	while(result == 0){
		
		std::cout <<"Введите запретную длину: ";
		std::cin >> forbidden_length;
		std::cout << "Введите слово: " ;
		std::cin >> str;
		result = function(str,forbidden_length);
		
	}
	return result;
}
