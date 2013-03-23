/* File : example.h */

#include <iostream>

class Callback {
public:
	virtual ~Callback() { std::cout << "Callback::~Callback()" << std:: endl; }
	virtual std::string run() { return "bar"}
};


class Caller {
private:
	Callback *_callback;
public:
	Caller(): _callback(0) {}
	~Caller() { delCallback(); }
	void delCallback() { delete _callback; _callback = 0; }
	void setCallback(Callback *cb) { delCallback(); _callback = cb; }
	std::string call() { if (_callback) return _callback->run(); }
};

