#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
public:
	Harl();
	~Harl();

	void complain(std::string level);

private:
	enum State {
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};
	static const std::string _complains[4];
	int _filter_level;


	void setFilterLevel(std::string level);

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

};

#endif
