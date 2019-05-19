#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
    
    static const int NUM = 800;
    
    float x[NUM];
    float y[NUM];
    float z[NUM];
    float X[NUM];
    float Y[NUM];
    float Z[NUM];
    
    ofEasyCam cam;
    ofLight light;
    
    ofSoundPlayer mySound;
    float *volume;
    float* fftSmoothed;
    int nBandsToGet;
    
    float time;
    float dis;
    int i;
    int i_;
    int n = 8192;
    float FFT ;
    
    ofxPanel gui;
    ofxColorSlider color;
    
};
