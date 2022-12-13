#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(lowThresholdEdge.setup("Edge Threshold", 50, 0, 100));
    webcamGrabber.setup(640, 640);
}

//--------------------------------------------------------------
void ofApp::update(){
    webcamGrabber.update();
    
    // Edge Detection
    if(webcamGrabber.isFrameNew()){
        ofPixels pixs = webcamGrabber.getPixels();
        webcamGrabberFrame.setFromPixels(pixs);
        webcamGrabberFrameMat = toCv(webcamGrabberFrame);
        cvtColor(webcamGrabberFrameMat, webcamGrabberFrameMatGray, CV_BGR2GRAY);
        GaussianBlur(webcamGrabberFrameMatGray, webcamGrabberFrameMatGray, 3);
        Canny(webcamGrabberFrameMatGray, webcamGrabberFrameMatEdge, lowThresholdEdge, lowThresholdEdge*3);
    }
    
    // Circle Detection
    
//    if (webcamGrabber.isFrameNew()) {
//        ofPixels pixs = webcamGrabber.getPixels();
//        webcamGrabberFrame.setFromPixels(pixs);
//        webcamGrabberFrameMat = toCv(webcamGrabberFrame);
////        cvtColor(webcamGrabberFrameMat, webcamGrabberFrameMatGray, CV_BGR2GRAY);
//        cvtColor(webcamGrabberFrameMat, webcamGrabberFrameMat, CV_BGR2GRAY);
////        GaussianBlur(webcamGrabberFrameMatGray, webcamGrabberFrameMatGray, 3);
//        GaussianBlur(webcamGrabberFrameMat, webcamGrabberFrameMat, 3);
////        Canny(webcamGrabberFrameMatGray, webcamGrabberFrameMatEdge, lowThresholdEdge, lowThresholdEdge*2);
//        Canny(webcamGrabberFrameMat, webcamGrabberFrameMat, lowThresholdEdge, lowThresholdEdge*2);
//        HoughCircles(webcamGrabberFrameMat, circles, CV_HOUGH_GRADIENT, 2, 50, lowThresholdEdge*2, 100, 30, 50);
//        ofSetColor(255, 0, 0);
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255, 255, 255);
    
    // Draw the input from the WebCam
//    webcamGrabber.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    // Draw the Edges from the WebCam Input
    drawMat(webcamGrabberFrameMatEdge, 0, 0, ofGetWidth(), ofGetHeight());
    gui.draw();
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
