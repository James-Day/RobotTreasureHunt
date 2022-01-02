#include <iostream>
#include <string>
#include "robot.h"
using namespace std;
int main(int argc, char* argv[]) 
{
	Point robot_location, treasure;

	if (argc == 6) 
	{
		robot_location.x = std::stoi(argv[1]);
		robot_location.y = std::stoi(argv[2]);

		treasure.x = std::stoi(argv[3]);
		treasure.y = std::stoi(argv[4]);

		Robot robot1(robot_location);

		robot1.FindPaths(treasure, robot1.location(), std::stoi(argv[5]));
	}
	else
	{
		cout << "Wrong amount of arguments" << endl;
	}
}