#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxGui.h"

using namespace ofxCv;
using namespace cv;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
    
    ofVideoGrabber webcamGrabber;
    ofImage webcamGrabberFrame;
    Mat webcamGrabberFrameMat;
    Mat webcamGrabberFrameMatGray;
    Mat webcamGrabberFrameMatEdge;
    
//    vector<Vec3f> circles;
    
    ofxPanel gui;
    ofxIntSlider lowThresholdEdge;
    
    // ofxOpenCV by Book
    ofxCvContourFinder contourFinder;
    ofxCvColorImage colorImg;
    ofVideoGrabber vidGrabber;
    
    ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage grayBg;
    ofxCvGrayscaleImage grayDiff;
    
    int threshold;
    bool learnBackground;
    
    int xVal = 640;
    int yVal = 480;
    
};
