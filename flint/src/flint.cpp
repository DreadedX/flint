#include <iostream>

const char *mainMenu[] = {
    "Setup",
    "Build",
    "Run",
    "Debug",
};

/** @todo This depends on the system */
const int ptr_size = 8;

int menu(const char **options, int size);

int main() {

    int option = menu(mainMenu, sizeof(mainMenu)/ptr_size);

    switch(option) {
	case 1:
	    std::cout << "Show setup menu" << std::endl;
	    break;
	case 2:
	    std::cout << "Show build menu" << std::endl;
	    break;
	case 3:
	    std::cout << "Show run menu" << std::endl;
	    break;
	case 4:
	    std::cout << "Show debug menu" << std::endl;
	    break;
	case 0:
	    std::cout << "Closing flint" << std::endl;
	    break;
	default:
	    std::cout << "Unknown option selected, this should not happen" << std::endl;
	    break;
    }
}

int menu(const char **options, int size) {

    int option = -1; 

    while (option == -1) {
	for (int i = 0; i < size; i++) {

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

	if (option > size || option < 0) {
	    std::cout << "Please enter a valid number" << std::endl;
	    option = -1;
	}

    }

    return option;
}
