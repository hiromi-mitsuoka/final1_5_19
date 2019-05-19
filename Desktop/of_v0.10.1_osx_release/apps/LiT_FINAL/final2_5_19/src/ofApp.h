#pragma once

#include "ofMain.h"

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
    
    static const int NUM = 100;
    
    float loc_x[NUM];
    float loc_y[NUM];
    float loc_z[NUM];
    float speed_x[NUM];
    float speed_y[NUM];
    float speed_z[NUM];
    float radius[NUM];
    
    float red[NUM];
    float green[NUM];
    float blue[NUM];
    
    int i;
    int i_;
    
    ofEasyCam cam;
    ofSpherePrimitive sphere;
    
    ofSoundPlayer mySound;
    float *volume;
    float* fftSmoothed;
    int nBandsToGet;
    
    float time;
    float dis;
    
    bool space = false;
    
};
