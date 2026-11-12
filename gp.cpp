#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <fstream>

std::string author_FIO = "Абдулаев Юсуф";
std::string version = "1.7 BETA";

int line_num = 1;
void next_line() {
	std::cout << line_num << ". ~~~\t";
	line_num++;
}

static void text_editor(std::string file_name) {
	
	std::string input;

	std::vector<std::string> memory;

	bool is_work = true;
	while (is_work) {
		
		next_line();
		
		
		std::getline(std::cin, input);
		

		// commands

		if (input == "\\cmd s") { 
			std::ofstream file(file_name, std::ios::app);// save
			for (size_t i = 0; i < (memory.size()); i++) {
				file << memory[i] << '\n';
			}
			file.flush();
			file.close();
			continue;
		}

		else if (input == "\\cmd q") { // exit
			std::ofstream file(file_name, std::ios::app);
			file.close();
			is_work = false;
			file.close();
			continue;
		}

		else if (input == "\\cmd qs" || input == "\\cmd sq") {
			std::ofstream file(file_name, std::ios::app); // exit && save
			for (size_t i = 0; i < (memory.size()); i++) {
				file << memory[i] << '\n';
			}
			file.close();
			is_work = false;
			continue;
		}

		// save (in memory)
		memory.push_back(input);
		
	}
}

int main(int argc, char* argv[]) {
	std::ofstream file;
	if (argc < 2) {
		std::cout << "\t\"Gp\" - консольный текстовый редактор\n"
				  << "Автор: " << author_FIO << "\n"
				  << "_______________\n" // рамочка
				  << "Описание: \n"
				  << "Лёгкий консольный текстовый редактор созданный в учебных целях.\n"
				  << "версия: " << version << '\n'
				  << "Чтобы открыть файл напишите в терминале <gp {имя вашего файла}>, или перетащите файл на бинарный файл gp.\n";

		std::cout << "Enter для выхода...\n";
		std::cin.get();
		
		return 0;
	}
	file.open(argv[1]);

	if (file.is_open()) {
		file.close();
		text_editor(argv[1]);
	}

}
