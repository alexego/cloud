#include <cstdlib>

class ManStrategy {
public:
	virtual int& operator()() = 0;
};

class ManStrategyDead : public ManStrategy {
public:
	virtual int& operator()() {
		int* nihil = new int;
		*nihil = 0;
		return *nihil;
	}
};

class ManStrategyAlive : public ManStrategy {
public:
	virtual int& operator()() {
		int* some = new int;
		*some = std::rand() % 2;
		return *some;
	}
};
