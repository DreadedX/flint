#include "find.h"

rapidjson::Document find() {

    FILE* file = fopen("flintfile", "rb");

    if (file == nullptr) {

	std::cout << "Could not find flintfile" << std::endl;
	exit(-1);
    }

    char buffer[65536];

    rapidjson::FileReadStream is(file, buffer, sizeof(buffer));
    rapidjson::Document document;
    document.ParseStream<0>(is);

    if (document.IsObject()) {

	std::cout << "Error parsing flintfile" << std::endl;
	exit(-1);
    }

    return document;
}
