#include <fstream>
#include <cstdio>
#include "Player.h"

class Client
{
private:
	int FIFO;
	static int id;
	Player block;
public:
	Client();
	int SendQuery();
	int* RequestCards();
	int SendGameDump();
};