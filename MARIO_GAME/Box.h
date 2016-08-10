#pragma once
#include <vector>
using namespace std;
class Box
{
	
public:
	float x, y;
	float vx, vy;
	float width, height;
	float collisiontime;
public:
	Box();
	Box(float x, float y, float width, float height, bool blocked = false, float vx = 0, float vy = 0);
	~Box();
	void tranlate(float dx, float dy);	
	static bool aabbCheck(Box b1, Box b2);
	static bool aabb(Box b1, Box b2, float& moveX, float& moveY);
	static Box getSweptBroadphaseRec(Box b);
	static float sweptAABB(Box b1, Box b2, float& normalx, float& normaly);
	static int collide(Box box, Box block);
	float getTimeCol();
public:
	float getWidth();
	
	float getHeight();
	

};
typedef std::vector<Box> Boxlist;

