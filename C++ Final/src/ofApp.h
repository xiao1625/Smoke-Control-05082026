//  ofApp.h
#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "mover.hpp"

struct SmokeGroup {          // 一团烟雾 = 一堆粒子 + 自己的颜色
	std::vector<Mover> movers;
	ofColor baseColor;
};

class ofApp : public ofBaseApp {
public:
	void setup() override;
	void update() override;
	void draw() override;
	void mousePressed(int x, int y, int button) override;
	void mouseDragged(int x, int y, int button) override;
	void keyPressed(int key) override;

	void emitSmoke(int x, int y, ofColor c);   // 发射一团烟雾

	std::vector<SmokeGroup> smokes;

	// GUI（保留你原来的拖尾控制 + 新增烟雾参数）
	ofxPanel gui;
	ofxFloatSlider bgAlpha;
	ofxIntSlider   numParticlesPerClick;
	ofxFloatSlider turbulenceStrength;  // 可调烟雾强度
	ofxButton      resetButton;

	void resetScene();
};
