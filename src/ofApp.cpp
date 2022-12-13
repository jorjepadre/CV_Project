#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    gui.setup();
//    gui.add(lowThresholdEdge.setup("Edge Threshold", 50, 0, 100));
//    webcamGrabber.setup(640, 640);
    
//    ----------
    learnBackground = false;
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(xVal, yVal);
    colorImg.allocate(xVal, yVal);
    grayImage.allocate(xVal, yVal);
    grayBg.allocate(xVal, yVal);
    grayDiff.allocate(xVal, yVal);
    
}

//--------------------------------------------------------------
void ofApp::update(){
//    webcamGrabber.update();
    
    // Edge Detection
//    if(webcamGrabber.isFrameNew()){
//        ofPixels pixs = webcamGrabber.getPixels();
//        webcamGrabberFrame.setFromPixels(pixs);
//        webcamGrabberFrameMat = toCv(webcamGrabberFrame);
//        cvtColor(webcamGrabberFrameMat, webcamGrabberFrameMatGray, CV_BGR2GRAY);
//        GaussianBlur(webcamGrabberFrameMatGray, webcamGrabberFrameMatGray, 3);
//        Canny(webcamGrabberFrameMatGray, webcamGrabberFrameMatEdge, lowThresholdEdge, lowThresholdEdge*3);
//    }
    
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
    
//    ------------------------------------------------------------
    vidGrabber.update();
    if (vidGrabber.isFrameNew()) {
        colorImg.setFromPixels(vidGrabber.getPixels());
        grayImage = colorImg;
        if (learnBackground) {
            grayBg = grayImage;
            learnBackground = false;
        }
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(30);
        contourFinder.findContours(grayDiff, 10, (xVal * yVal) / 4, 2, false, true);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofBackground(255);
//    ofSetColor(255, 255, 255);
//
//    // Draw the input from the WebCam
//    webcamGrabber.draw(0, 0, ofGetWidth(), ofGetHeight());
//
//    // Draw the Edges from the WebCam Input
////    drawMat(webcamGrabberFrameMatEdge, 0, 0, ofGetWidth(), ofGetHeight());
//    gui.draw();
    
//    ------------------------------------
    ofSetHexColor(0xffffff);
    colorImg.draw(0, 0, xVal, yVal);
    grayDiff.draw(0, yVal, xVal, yVal);
    ofDrawRectangle(xVal, 0, xVal, yVal);
    contourFinder.draw(xVal, 0, xVal, yVal);
    ofColor c(255, 255, 255);
    
    for (int i = 0; i <contourFinder.nBlobs; ++i) {
        ofRectangle r = contourFinder.blobs.at(i).boundingRect;
        r.x += xVal ;
        r.y += yVal;
        c.setHsb(i * 64, 255, 255);
        ofSetColor(c);
        ofDrawRectangle(r);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    learnBackground = true;
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
