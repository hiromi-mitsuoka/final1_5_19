#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int i;
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofEnableDepthTest();//深度テストを有効に
    ofSetVerticalSync(true);//素早い動きOK
    dis = 120;
    cam.setDistance(dis);
    light.enable();
    light.setPosition(-4*dis,4*dis,8*dis);
    
    mySound.load("Pick Me Up.mp3");
    mySound.setLoop(true);
    //mySound.setSpeed(1.1);
    mySound.play();
    fftSmoothed = new float[n];
    for(int i_=0; i_<n; i_++){
        fftSmoothed[i_] = 0;
    }
    nBandsToGet = 10;
    
    //ofSetCircleResolution(64);
    for(i=0; i<NUM; i++){
        x[i] = ofRandom(-NUM/2,NUM/2);
        y[i] = ofRandom(-NUM/2,NUM/2);
        z[i] = ofRandom(-NUM/2,NUM/2);
        X[i] = ofRandom(-NUM/2,NUM/2);
        Y[i] = ofRandom(-NUM/2,NUM/2);
        Z[i] = ofRandom(-NUM/2,NUM/2);
    }
    ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
    
    gui.setup();
    ofColor initColor = ofColor(0,127,255,255);
    ofColor minColor = ofColor(0,0,0,0);
    ofColor maxColor = ofColor(255,255,255,255);
    gui.add(color.setup("color",140,0,255));
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    volume = ofSoundGetSpectrum(nBandsToGet);
    for(int i_=0; i_<nBandsToGet; i_++){
        fftSmoothed[i_]*=0.66f;
        if(fftSmoothed[i_]<volume[i_]){
            fftSmoothed[i_]=volume[i_];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    time = ofGetElapsedTimeMillis()/50;
    // 座標系を移動
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    cam.begin();
    cam.setPosition(dis*cos(time/9),dis*sin(time/10),dis*sin(time/9));
    cam.lookAt(ofVec3f(0,0,0),(ofVec3f(0,1,0)));
    int i;
    for(i=0; i<NUM; i++){
        ofSetColor(0,164,116,93);
        ofSetLineWidth(2);
        ofDrawLine(x[i], X[i], y[i], Y[i], z[i], Z[i]);
    }
    for(i_=0; i_<NUM*10; i_++){
        float FFT = fftSmoothed[i_];
        //        ofSetLineWidth(10);
        //        ofDrawLine(0,0,0,x[i_]/8,y[i_]/8,z[i_]/8);
        ofNoFill();
        ofSetLineWidth(8);
        ofRotateX(FFT*40);
        ofRotateY(40);
        ofRotateZ(30);
        ofSetColor(color);
        ofDrawRectangle(0, 0, FFT*NUM, FFT*NUM);
        ofFill();
    }
    cam.end();
    ofPopMatrix();
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
