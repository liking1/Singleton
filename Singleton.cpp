#include "Singleton.h"

Logging* Logging::instance = nullptr;

void Logging::addLog(const Log& log)
{

	ofstream out("db.dat", ios_base::binary | ios_base::app);
	if (!out)
	{
		cerr << "Error opening for writing\n";
		return;
	}

	out.write((char*)&log, sizeof(log));
	out.close();
}

void Logging::showLog() const
{

	ifstream in("db.dat", ios_base::binary);
	if (!in)
	{
		throw exception("Error opening file for read");
	}
	Log log;
	size_t index = 0;
	while (in.read((char*)&log, sizeof(log)))
	{
		++index;
		cout << index;
		cout << "." << log << endl;
	}
}