#include <fstream>
#include <iostream>
#include <string>

void replace(std::string &line, const std::string target,
		const std::string new_string, std::ofstream &outputfile) {
	size_t pos = 0;

	if (target.length() > 0)
	{
		while ((pos = line.find(target, pos)) != std::string::npos
				&& target.length() > 0) {
			line.erase(pos, target.length());
			line.insert(pos, new_string);
			pos += new_string.length();
		}
	}
	outputfile << line;
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
			throw "Error: Unable to open input file.";
		}

		std::string new_file_name = argv[1];
		new_file_name.append(".replace");
		std::ofstream outputFile(new_file_name.c_str());
		if (!outputFile.is_open())
		{
			throw "Error: Unable to open output file.";
			inputFile.close();
  			return 1;
		}

		std::string line;
		while (std::getline(inputFile, line)) {
			replace(line, argv[2], argv[3], outputFile);
			if (!inputFile.eof()) {
				outputFile << '\n';
			}
		}
		inputFile.close();
		outputFile.close();
	} catch (const char* e) {
        std::cerr << "Error: " << e << std::endl;
        return 1;
	}
}
