#include "Box.h"
#include <algorithm>

Box::Box()
{
	x = y = width = height = 0;
}
Box::Box(float X, float Y, float Width, float Height, bool Blocked, float Vx, float Vy)
{

	x = X;
	y = Y;
	vx = Vx;
	vy = Vy;
	width = Width;
	height = Height;	
}
Box::~Box()
{
}

void Box::tranlate(float dx, float dy)
{
	x += dx;
	y += dy;
}

bool ValueInRange(int value, int min, int max)
{
	return (value >= min) && (value <= max);
}

// returns true if the boxes are colliding (velocities are not used)
bool Box::aabbCheck(Box b1, Box b2)
{
	return !(b1.x + b1.width < b2.x || b1.x > b2.x + b2.width || b1.y + b1.height < b2.y || b1.y > b2.y + b2.height);
}

// returns true if the Boxes are colliding (velocities are not used)
// moveX and moveY will return the movement the b1 must move to avoid the collision
bool Box::aabb(Box b1, Box b2, float& moveX, float& moveY)
{
	moveX = moveY = 0.0f;

	float l = b2.x - (b1.x + b1.width);
	float r = (b2.x + b2.width) - b1.x;
	float t = b2.y - (b1.y + b1.height);
	float b = (b2.y + b2.height) - b1.y;

	// check that there was a collision
	if (l > 0 || r < 0 || t > 0 || b < 0)
		return false;

	// find the offset of both sides
	moveX = abs(l) < r ? l : r;
	moveY = abs(t) < b ? t : b;

	// only use whichever offset is the smallest
	if (abs(moveX) < abs(moveY))
		moveY = 0.0f;
	else
		moveX = 0.0f;

	return true;
}

// returns a Box the spans both a current Box and the destination Box
Box Box::getSweptBroadphaseRec(Box b)
{
	Box broadphaseBox(0.0f, 0.0f, 0.0f, 0.0f);

	broadphaseBox.x = b.vx > 0 ? b.x : b.x + b.vx;
	broadphaseBox.y = b.vy > 0 ? b.y : b.y + b.vy;
	broadphaseBox.width = b.vx > 0 ? b.vx + b.width : b.width - b.vx;
	broadphaseBox.height = b.vy > 0 ? b.vy + b.height : b.height - b.vy;

	return broadphaseBox;
}

// performs collision detection on moving Box b1 and static Box b2
// returns the time that the collision occured (where 0 is the start of the movement and 1 is the destination)
// getting the new position can be retrieved by Box.x = Box.x + Box.vx * collisiontime
// normalx and normaly return the normal of the collided surface (this can be used to do a response)
float Box::sweptAABB(Box b1, Box b2, float& normalx, float& normaly)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// find the distance between the objects on the near and far sides for both x and y
	if (b1.vx > 0.0f)
	{
		xInvEntry = b2.x - (b1.x + b1.width);
		xInvExit = (b2.x + b2.width) - b1.x;
	}
	else
	{
		xInvEntry = (b2.x + b2.width) - b1.x;
		xInvExit = b2.x - (b1.x + b1.width);
	}

	if (b1.vy > 0.0f)
	{
		yInvEntry = b2.y - (b1.y + b1.height);
		yInvExit = (b2.y + b2.height) - b1.y;
	}
	else
	{
		yInvEntry = (b2.y + b2.height) - b1.y;
		yInvExit = b2.y - (b1.y + b1.height);
	}

	// find time of collision and time of leaving for each axis (if statement is to prevent divide by zero)
	float xEntry, yEntry;
	float xExit, yExit;

	if (b1.vx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / b1.vx;
		xExit = xInvExit / b1.vx;
	}

	if (b1.vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / b1.vy;
		yExit = yInvExit / b1.vy;
	}

	// find the earliest/latest times of collision
	float entryTime = std::max(xEntry, yEntry);
	float exitTime = std::min(xExit, yExit);

	// if there was no collision
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}
	else // if there was a collision
	{
		// calculate normal of collided surface
		if (xEntry > yEntry)
		{
			if (xInvEntry < 0.0f)
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else
		{
			if (yInvEntry < 0.0f)
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}

		// return the time of collision
		return entryTime;
	}
}

int Box::collide(Box box, Box block)
{
	// Box is the moving Box
	// block is the static Box
	Box broadphaseBox = getSweptBroadphaseRec(box);
	if (aabbCheck(broadphaseBox, block))
	{
		float normalx, normaly;
		float collisiontime = sweptAABB(box, block, normalx, normaly);
		float remainingtime = 1.0f - collisiontime;
		if (collisiontime <1.0f)
		{
			
			if (normalx == -1)
				return 2; //right
			if (normalx == 1)
				return 1; //left
			if (normaly == -1)
				return 4;//top
			if (normaly == 1)
				return 3; //bottom
		}
		else
			if (aabbCheck(box, block))
			{
				return 5;
			}
	}
	return 0;
}

//Get and Set

float Box::getTimeCol()
{
	return this->collisiontime;
}

float Box::getWidth()
{
	return this->width;
	
}
float Box::getHeight()
{
	return this->height;
}



