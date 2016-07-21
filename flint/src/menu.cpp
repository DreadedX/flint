#include "menu.h"

int menu(std::vector<std::string> options) {

    int option = -1; 

    while (option == -1) {
	for (int i = 0; i < options.size(); i++) {

	    std::cout << i+1 << ": " << options[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "0: Exit menu" << std::endl;

	std::string in;

	std::cout << "Select: ";
	std::cin >> in;

	try {
	    option = std::stoi(in);
	} catch(std::invalid_argument &e) {
	    option = -1;
	}

	if (option > options.size() || option < 0) {
	    std::cout << "Please enter a valid number" << std::endl;
	    option = -1;
	}

    }

    return option;
}
