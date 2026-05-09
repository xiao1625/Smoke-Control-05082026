//  mover.hpp
//  现在是彩色烟雾粒子

#ifndef mover_hpp
#define mover_hpp

#include "ofMain.h"

class Mover {
public:
	Mover();

	void setup(float x, float y);
	void applyForce(ofVec2f force);
	void update();
	void display();

	ofVec2f position;
	ofVec2f velocity;
	ofVec2f acceleration;

	float life;
	float maxLife;

	ofColor color;   // 每团烟雾有自己的颜色
};

#endif
