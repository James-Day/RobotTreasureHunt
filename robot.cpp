#include "robot.h"
#include <math.h>

Robot::Robot() 
{
	location_.x = 0;
	location_.y = 0;
}
Robot::Robot(Point location) 
{
	location_ = location;
}


int Robot::FindPaths(const Point& treasure, const int& moves_completed, const string& path, const int& max_moves,  int moves_in_a_row) 
{

	static Point start_location = location_;
	int shortest_distance = (abs(treasure.x - start_location.x) + abs(treasure.y - start_location.y)) - moves_completed; 
	if ((abs(treasure.x - location_.x) + abs(treasure.y - location_.y)) > (shortest_distance)) 
	{
		return 0;
	}
	else if (location_.x == treasure.x || location_.y == treasure.y) 
	{		//Found path
		if (location_.x == treasure.x && treasure.y > location_.y) 
		{
			if (path[path.size()- 1] != 'N') 
			{
				moves_in_a_row = 0;
			}
			if ((moves_in_a_row + abs(location_.y - treasure.y)) <= max_moves) 
			{ 
				cout << path.substr(1,path.size()-1);
				for (int i = 0; i < abs(location_.y - treasure.y); i++) 
				{
					cout << "N";
				}
				cout << endl;
				return 1;
			}
		}
		else if (location_.x == treasure.x && treasure.y < location_.y) 
		{
			if (path[path.size() - 1] != 'S') 
			{
				moves_in_a_row = 0;
			}
			if ((moves_in_a_row + abs(location_.y - treasure.y)) <= max_moves) 
			{
				cout << path.substr(1, path.size() - 1);
				for (int i = 0; i < abs(location_.y - treasure.y); i++) 
				{
					cout << "S";
				}
				cout << endl;
				return 1;
			}
		}
		else if (location_.y == treasure.y && treasure.x > location_.x)
		{
			if (path[path.size() - 1] != 'E') 
			{
				moves_in_a_row = 0;
			}
			if ((moves_in_a_row + abs(location_.x - treasure.x)) <= max_moves) 
			{
				cout << path.substr(1, path.size() - 1);
				for (int i = 0; i < abs(location_.x - treasure.x); i++) 
				{
					cout << "E";
				}
				cout << endl;
				return 1;
			}
		}
		else if (location_.y == treasure.y && treasure.x < location_.x) 
		{
			if (path[path.size() - 1] != 'W') 
			{
				moves_in_a_row = 0;
			}
			if ((moves_in_a_row + abs(location_.x - treasure.x)) <= max_moves)
			{
				cout << path.substr(1, path.size() - 1);
				for (int i = 0; i < abs(location_.x - treasure.x); i++) 
				{
					cout << "W";
				}
				cout << endl;
				return 1;
			}
		}
		if (moves_completed == 0) 
		{
			cout << "No paths found!" << endl;
		}
		return 0;
	}

	int new_moves_in_a_row = moves_in_a_row;
	int total_paths = 0;
	bool add_moves_in_a_row = false;
	if(moves_in_a_row < max_moves || path[path.size()-1] != 'N')
	{
		if (path[path.size() - 1] == 'N') 
		{
			add_moves_in_a_row = true;
		}
		else {
			new_moves_in_a_row = 1;
		}
		MoveNorth();
		total_paths += FindPaths(treasure, moves_completed + 1, path + "N", max_moves, new_moves_in_a_row + add_moves_in_a_row);//North
		MoveSouth();
	}
	add_moves_in_a_row = false;
	new_moves_in_a_row = moves_in_a_row;
	if (moves_in_a_row  < max_moves || path[path.size()-1] != 'E')
	{
		if (path[path.size() - 1] == 'E')
		{
			add_moves_in_a_row = true;
		}
		else 
		{
			new_moves_in_a_row = 1;
		}
		MoveEast();
		total_paths += FindPaths(treasure, moves_completed + 1, path + "E", max_moves, new_moves_in_a_row + add_moves_in_a_row);//East
		MoveWest();
	}
	add_moves_in_a_row = false;
	new_moves_in_a_row = moves_in_a_row;
	if (moves_in_a_row < max_moves || path[path.size()-1] != 'S')
	{
		if (path[path.size() - 1] == 'S') 
		{
			add_moves_in_a_row = true;
		}
		else 
		{
			new_moves_in_a_row = 1;
		}
		MoveSouth();
		total_paths += FindPaths(treasure, moves_completed + 1, path + "S", max_moves, new_moves_in_a_row + add_moves_in_a_row);//South
		MoveNorth();
	}
	add_moves_in_a_row = false;
	new_moves_in_a_row = moves_in_a_row;
	if (moves_in_a_row < max_moves || path[path.size()-1] != 'W')
	{
		if (path[path.size() - 1] == 'W') 
		{
			add_moves_in_a_row = true;
		}
		else 
		{
			new_moves_in_a_row = 1;
		}
		MoveWest();
		total_paths += FindPaths(treasure, moves_completed + 1, path + "W", max_moves, new_moves_in_a_row + add_moves_in_a_row);//West
		MoveEast();
	}
	if (moves_completed == 0 && total_paths == 0) 
	{
		cout << "No paths found!" << endl;
	}
	else if (moves_completed == 0)
	{
		cout << "Number of paths: " << total_paths << endl;
	}
	return total_paths;
}

Point Robot::location()
{
	return this->location_;
}

void Robot::set_location(const int& x, const int& y)
{
	location_.x = x;
	location_.y = y;
}

void Robot::MoveNorth()
{
	this->location_.y += 1;
}
void Robot::MoveEast()
{
	this->location_.x += 1;
}

void Robot::MoveSouth()
{
	this->location_.y -= 1;
}
void Robot::MoveWest()
{
	this->location_.x -= 1;
}

int Robot::FindPaths(const Point& treasure, const Point& start_location, const int& max_moves) 
{
	location_ = start_location;
	return FindPaths(treasure,0," ",max_moves,0);
}
