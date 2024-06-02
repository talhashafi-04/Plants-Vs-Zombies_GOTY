#include "PlayerArray.h"

PlayerArray::PlayerArray()
{
	size = 0;
	playerList = new Player * [size];
}

PlayerArray::~PlayerArray()
{
	for (int i = 0; i < size; i++)
	{
		delete playerList[i];
	}
	delete[] playerList;
}

Player** PlayerArray::getPlayerList()
{
	return playerList;
}


void PlayerArray::addPlayer(string name, int score, int level)
{
	Player** temp = new Player * [size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = playerList[i];
	}
	temp[size] = new Player(name, score, level);
	size++;
	delete[] playerList;
	playerList = temp;
}

void PlayerArray::deletePlayer(int index)
{
	Player** temp = new Player * [size - 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = playerList[i];
	}
	for (int i = index + 1; i < size; i++)
	{
		temp[i - 1] = playerList[i];
	}
	size--;
	delete playerList[index];
	delete[] playerList;
	playerList = temp;
}

void PlayerArray::sortPlayer()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (playerList[j]->getKills() < playerList[j + 1]->getKills())
			{
				Player* temp = playerList[j];
				playerList[j] = playerList[j + 1];
				playerList[j + 1] = temp;
			}
		}
	}
}

void PlayerArray::displayPlayer()
{
	for (int i = 0; i < size; i++)
	{
		cout << playerList[i]->getName() << " " << playerList[i]->getKills() << " " << playerList[i]->getLevel() << endl;
	}
}

void PlayerArray::writeToFile()
{
	ofstream file("player.txt");
	for (int i = 0; i < size; i++)
	{
		file << playerList[i]->getName() << "," << playerList[i]->getKills() << "," << playerList[i]->getLevel() << endl;
	}
	file.close();
}

void PlayerArray::readFromFile()
{
	ifstream file("player.txt");
	if (!file.is_open())
	{
		cout << "Error opening file for reading." << endl;
	}
	else
	{
		string line;
		while (getline(file, line))
		{
			string name = "";
			int score = 0, level = 0;
			stringstream ss(line);
			getline(ss, name, ',');
			ss >> score;
			ss.ignore();
			ss >> level;
			addPlayer(name, score, level);
		}
		file.close();
	}
}

void PlayerArray::updatePlayer(string name, int score, int level)
{
	for (int i = 0; i < size; i++)
	{
		if (playerList[i]->getName() == name)
		{
			playerList[i]->setKills(score);
			playerList[i]->setLevel(level);
		}
	}
}

int PlayerArray::getSize()
{
	return size;
}

Player* PlayerArray::getPlayer(int index)
{
	return playerList[index];
}



void PlayerArray::displayOnTerminal() {
	for (int i = 0; i < size; i++)
	{
		cout << "Name: " << getPlayer(i)->getName() << endl;
		cout << "Kills: " << getPlayer(i)->getKills() << endl;
		cout << "Level: " << getPlayer(i)->getLevel() << endl;
		cout << "--------------------------------" << endl;
		cout << endl;
	}
}