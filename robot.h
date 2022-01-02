#ifndef ROBOT_H_
#define ROBOT_H_
#include <iostream>
using namespace std;
struct Point { 
	int x;
	int y;
};

class Robot
{
public:
	Robot();
	Robot(Point location);
	Point location();
	void set_location(const int &x, const int &y);

	void MoveNorth();  
	void MoveEast();
	void MoveSouth();
	void MoveWest();


	int FindPaths(const Point &treasure, const Point &start_location, const int &max_moves); 
	
private:
	int FindPaths(const Point &treasure, const int &moves_completed, const string &path, const int &max_moves, int moves_in_a_row); 
	Point location_;
};
#endif

