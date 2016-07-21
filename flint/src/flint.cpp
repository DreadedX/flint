#include "find.h"
#include "parse.h"
#include "menu.h"

std::vector<std::string> mainMenu = {
    "Setup",
    "Build",
    "Run",
    "Debug",
};

rapidjson::Document document;

void printOptions(const char *filter) {

    for (uint32_t i = 0; i < document.Size(); i++) {

	if (document[i].HasMember(filter)) {

	    std::cout << filter << ": \t" << document[i]["name"].GetString() << std::endl;
	}
    }
}

int main() {

    FILE* file = fopen("flintfile", "rb");

    if (file == nullptr) {

	std::cout << "Could not find flintfile" << std::endl;
	exit(-1);
    }

    char buffer[65536];

    rapidjson::FileReadStream is(file, buffer, sizeof(buffer));
    document.ParseStream<0>(is);

    if (!document.IsArray()) {

	std::cout << "Invalid flintfile" << std::endl;
	exit(-1);
    }

    int option = menu(mainMenu);

    switch(option) {
	case 1:
	    printOptions("setup");
	    break;
	case 2:
	    printOptions("build");
	    break;
	case 3:
	    printOptions("run");
	    break;
	case 4:
	    printOptions("debug");
	    break;
	case 0:
	    std::cout << "Closing flint" << std::endl;
	    break;
	default:
	    std::cout << "Unknown option selected, this should not happen" << std::endl;
	    break;
    }
}
