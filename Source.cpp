#include <iostream>
#include "Singleton.h"

int main()
{
	Logging* log = Logging::getInstance();
	log->addLog({ "Nonameee",Log::Flag::FATAL });
	log->addLog({ "NoName",Log::Flag::WARN });
	log->showLog();
}