#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	float radius = 100;
	for (int y = -230; y <= 230; y += 230) {

		for (int i = 0; i < 8; i++) {

			float left_deg_start = ofGetFrameNum() * 5 - i * 20 + y + 270;
			float right_deg_start = ofGetFrameNum()* 5 - i * 20 + 180 + y + 270;

			vector<glm::vec2> vertices;
			for (float deg = left_deg_start; deg < left_deg_start + 10; deg += 1) {

				vertices.push_back(glm::vec2(-180 + radius * cos(deg * DEG_TO_RAD), y + radius * sin(deg * DEG_TO_RAD)));
			}

			for (float deg = right_deg_start; deg < right_deg_start + 10; deg += 1) {

				vertices.push_back(glm::vec2(180 + radius * cos(deg * DEG_TO_RAD), y + radius * sin(deg * DEG_TO_RAD)));
			}

			ofFill();
			ofSetColor(239);

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);

			ofNoFill();
			ofSetColor(39);

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}
	}

	/*
	int start = 250;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}