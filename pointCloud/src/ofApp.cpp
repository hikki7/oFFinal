#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetFullscreen(true);
    
    //-------------------setup kinect
    kinect.init();
    kinect.open();
    cout<<kinect.isConnected()<<endl;
    kinect.setDepthClipping();
    //これでcolorが通常カメラと深度カメラのずれを修正できた
    kinect.setRegistration(true);
    kinect.setCameraTiltAngle(22);
    
    //-------------------setup gui
    
    gui.setup();
    gui.add(nearVal.setup("near val",0,0,1000));
    gui.add(farVal.setup("far val",2000,150,2000));
    gui.add(kinectAngle.setup("kinect angle",22,0,45));
    gui.add(space.setup("space",5,0,10));
    gui.add(radius.setup("radius",1,0,10));
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
    kinect.setCameraTiltAngle(kinectAngle);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //kinect.draw(0, 0,kinect.getWidth(),kinect.getHeight());
    //kinect.drawDepth(kinect.getWidth(), 0,kinect.getWidth(),kinect.getHeight());

    cam.begin();
    drawPointCloud();
    cam.end();
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::drawPointCloud(){
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    for (int y=0; y<kinect.height; y+=space) {
        for (int x=0; x<kinect.width; x+=space) {
            if (kinect.getDistanceAt(x, y)>nearVal&&kinect.getDistanceAt(x, y)<farVal) {
                mesh.addColor(kinect.getColorAt(x, y));
                mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
            }
        }
    }
    glPointSize(radius);
    ofPushMatrix();
    ofScale(1,-1,-1);
    ofTranslate(0, 0,-1000);
    ofEnableDepthTest();
    mesh.drawVertices();
    ofDisableDepthTest();
    ofPopMatrix();
}

//--------------------------------------------------------------

void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
