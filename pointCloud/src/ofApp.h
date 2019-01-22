#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "ofxGui.h"

using namespace glm;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void drawPointCloud();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    vector<string> split(string str,char del);
    
    ofxKinect kinect;
    
    ofxPanel gui;
    ofxFloatSlider nearVal;
    ofxFloatSlider farVal;
    ofxFloatSlider kinectAngle;
    ofxIntSlider space;
    ofxFloatSlider radius;
    
    ofEasyCam cam;
    
    ofColor color;
    
    vec2 imgLoc;
    int imgWidth,imgHeight;
    
    
};
