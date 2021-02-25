#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct Log
{
	enum class Flag { DEBUG, INFO, WARN, FATAL, ERROR,};
	Log(const string message = "NO message", Flag flag = Flag::DEBUG) {
		vector<string> Flag_char{ " ---------- "," ============== "," @@@@@@@@@@@@ ", " ########## ", " ********** " };
		if (!message.empty() && message.size() < 236) {
			string temp = Flag_char[(size_t)flag];
			temp += message;
			temp += Flag_char[(size_t)flag];
			strcpy_s(this->message, temp.c_str());
		}
	}
	friend ostream& operator<<(ostream& ost, const Log& log) {
		ost << log.message << endl;
		return ost;
	};
private:
	char message[256];
};

class Logging
{
private:
	static Logging* instance;
protected:
	Logging() = default;
public:
	void addLog(const Log& log);
	void showLog() const;
	Logging(const Logging&) = delete; // заборона копіювати 
	Logging& operator = (const Logging&) = delete; // заборона присвоювати
	static Logging* getInstance() {

		if (instance == nullptr) {
			instance = new Logging();
		}
		return instance;

	};
};