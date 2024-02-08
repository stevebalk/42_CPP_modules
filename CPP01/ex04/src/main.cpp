#include <fstream>
#include <iostream>
#include <string>

void replace(std::string &line, const std::string target,
		const std::string new_string) {
	size_t pos = 0;

	while ((pos = line.find(target, pos)) != std::string::npos) {
		line.erase(pos, target.length());
		line.insert(pos, new_string);
		pos += new_string.length();
	}
	std::cout << line;
}

int main(int argc, char *argv[]) {
	try {
		if (argc != 4) {
			std::cerr << "Usage: " << argv[0]
					  << " <filename> <stringToReplace> <newString>"
					  << std::endl;
			return 1;
		}
		std::ifstream inputFile(argv[1]);
		if (!inputFile) {
			throw std::runtime_error("Error: Unable to open input file.");
		}
		std::string content;
		char ch;
		while (inputFile.get(ch)) {
			content += ch;
			if (ch == '\n') {
				replace(content, argv[2], argv[3]);
				content = "";
			}
		}
		replace(content, argv[2], argv[3]);
		// replace(content, argv[2], argv[3]);
		inputFile.close();

	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}
