//  mover.cpp
//  梦幻光效烟雾粒子 v3

#include "mover.hpp"

Mover::Mover() {
	life = 0;
	maxLife = 255;
}

void Mover::setup(float x, float y) {
	position.set(x, y);
	velocity.set(ofRandom(-3.5f, 3.5f), ofRandom(-4.0f, 1.0f));
	acceleration.set(0);
	life = maxLife = ofRandom(160.0f, 255.0f);
}

void Mover::applyForce(ofVec2f force) {
	acceleration += force;
}

void Mover::update() {
	float t = ofGetElapsedTimef() * 0.8f;

	ofVec2f turbulence;
	turbulence.x = ofSignedNoise(position.x * 0.008f, position.y * 0.008f, t) * 1.8f;
	turbulence.y = ofSignedNoise(position.x * 0.008f + 100, position.y * 0.008f, t) * 1.6f - 0.6f;
	applyForce(turbulence);

	ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
	ofVec2f toMouse = mousePos - position;
	float dist = toMouse.length();
	if (dist > 5) {
		toMouse.normalize();
		float strength = ofMap(dist, 0, 400, 2.4f, 0.3f, true);
		applyForce(toMouse * strength);
	}

	velocity += acceleration;
	velocity *= 0.90f;
	position += velocity;
	acceleration *= 0;

	life -= 1.8f;
}

void Mover::display() {
	if (life <= 0) return;

	float lifeRatio = life / maxLife;   // 1.0(新生) → 0.0(消亡)
	float alpha = ofMap(life, 0, maxLife, 0, 220);

	// 粒子主半径：越老越大（烟雾扩散）
	float mainRadius = ofMap(life, 0, maxLife, 38, 5);

	// ── 第1层：最外层大光晕（极透明，范围很大）
	ofSetColor(color.r, color.g, color.b, alpha * 0.12f);
	ofFill();
	ofDrawCircle(position.x, position.y, mainRadius * 2.6f);

	// ── 第2层：外层烟雾体（半透明彩色）
	ofSetColor(color.r, color.g, color.b, alpha * 0.38f);
	ofDrawCircle(position.x, position.y, mainRadius * 1.4f);

	// ── 第3层：主粒子圆圈本体（纯彩色，新生时更不透明）
	float glowAlpha = alpha * (0.55f + lifeRatio * 0.45f);
	ofSetColor(color.r, color.g, color.b, glowAlpha);
	ofDrawCircle(position.x, position.y, mainRadius);




}
