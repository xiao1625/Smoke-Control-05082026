//  ofApp.cpp

#include "ofApp.h"

// ─── 宝石色调色盘 ─────────────────────────────────────────────────────────
// 饱和度提升到 170-210（比上版更有色彩感），但色相锁定在好看的区间
// 避开高饱和纯红/纯绿/纯黄这种"霓虹"感
static ofColor getDreamyColor() {
	struct ColorRange { float hMin, hMax, sat, bri; };
	static const ColorRange palette[] = {
		{   0,  18, 190, 250 },   // 珊瑚红 / 玫红
		{  18,  42, 170, 248 },   // 琥珀橙
		{ 270, 300, 195, 245 },   // 紫罗兰
		{ 300, 330, 185, 248 },   // 洋红 / 玫粉
		{ 330, 355, 175, 250 },   // 樱桃粉
		{ 175, 210, 180, 245 },   // 天青蓝 / 冰蓝
		{ 140, 175, 160, 240 },   // 翡翠薄荷
		{ 210, 250, 190, 242 },   // 蔷薇蓝紫
	};
	int idx = (int)ofRandom(0, 8);
	const ColorRange& r = palette[idx];
	float hue = ofRandom(r.hMin, r.hMax);
	float hue255 = fmod(hue / 360.0f * 255.0f + 255.0f, 255.0f);
	return ofColor::fromHsb(hue255, r.sat, r.bri, 255);
}

void ofApp::setup() {
	ofSetBackgroundAuto(false);
	ofBackground(0);
	ofSetFrameRate(60);

	gui.setup("Smoke Controls", "settings.xml", 10, 10);
	gui.add(bgAlpha.setup("Background Alpha", 20, 0, 60));
	gui.add(numParticlesPerClick.setup("Particles per Click", 45, 15, 80));
	gui.add(turbulenceStrength.setup("Turbulence", 1.8f, 0.5f, 4.0f));
	gui.add(resetButton.setup("Reset All"));
	resetButton.addListener(this, &ofApp::resetScene);

	resetScene();
}

void ofApp::resetScene() {
	smokes.clear();
}

void ofApp::emitSmoke(int x, int y, ofColor c) {
	SmokeGroup g;
	g.baseColor = c;

	int count = (int)numParticlesPerClick;
	for (int i = 0; i < count; i++) {
		Mover m;
		m.setup(x + ofRandom(-12, 12), y + ofRandom(-12, 12));
		m.color = c;
		// 色相轻微抖动（±10），保持同一团烟雾颜色统一
		float hue = m.color.getHue() + ofRandom(-10, 10);
		m.color.setHue(fmod(hue + 255.0f, 255.0f));
		// 饱和度略微随机，让粒子有微妙层次
		m.color.setSaturation(ofClamp(m.color.getSaturation() + ofRandom(-20, 20), 140, 220));
		g.movers.push_back(m);
	}
	smokes.push_back(g);
}

void ofApp::update() {
	for (auto& group : smokes) {
		for (auto& m : group.movers) {
			m.update();
		}
	}
	for (auto& group : smokes) {
		ofRemove(group.movers, [](Mover& m){ return m.life <= 0; });
	}
}

void ofApp::draw() {
	ofSetColor(0, bgAlpha);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	for (auto& group : smokes) {
		for (auto& m : group.movers) {
			m.display();
		}
	}

	gui.draw();

	ofSetColor(255, 255, 255, 80);
	ofDrawBitmapString("Click / Drag = 梦幻烟雾   Space = 清空", 12, ofGetHeight() - 12);
}

void ofApp::mousePressed(int x, int y, int button) {
	if (button != 0) return;
	emitSmoke(x, y, getDreamyColor());
}

void ofApp::mouseDragged(int x, int y, int button) {
	if (ofRandom(1) < 0.6f) {
		emitSmoke(x, y, getDreamyColor());
	}
}

void ofApp::keyPressed(int key) {
	if (key == ' ') resetScene();
}
