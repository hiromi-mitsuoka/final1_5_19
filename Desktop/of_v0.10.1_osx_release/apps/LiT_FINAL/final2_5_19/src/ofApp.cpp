#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetLineWidth(2);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofEnableDepthTest();//深度テストを有効に
    ofSetVerticalSync(true);//素早い動きOK
    //time = ofGetElapsedTimeMillis();
    dis = 1000;
    cam.setDistance(dis);
    //    cam.setPosition(2000*sin(ofGetElapsedTimeMillis()%255),2000*cos(ofGetElapsedTimeMillis()%255),2000);
    cam.lookAt(ofVec3f(0,0,0),(ofVec3f(0,1,0)));
    
    mySound.load("Eccentric.mp3");
    mySound.setLoop(true);
    mySound.play();
    fftSmoothed = new float[8192];
    for(int i_=0; i_<8192; i_++){
        fftSmoothed[i_] = 0;
    }
    nBandsToGet = 100;
    
    for(int i=0; i<NUM; i++){
        loc_x[i]=ofRandom(-700,700);
        loc_y[i]=ofRandom(-700,700);
        loc_z[i]=ofRandom(-700,700);
        speed_x[i]=ofRandom(-(fftSmoothed[i]*100),(fftSmoothed[i]*100));
        speed_y[i]=ofRandom(-(fftSmoothed[i]*100),(fftSmoothed[i]*100));
        speed_z[i]=ofRandom(-(fftSmoothed[i]*100),(fftSmoothed[i]*100));
        radius[i]=ofRandom(2,5);
        red[i]=ofRandom(0,255);
        green[i]=ofRandom(0,255);
        blue[i]=ofRandom(0,255);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetWindowTitle(to_string(ofGetFrameRate()));
    for(int i=0; i<NUM; i++){
        loc_x[i] += speed_x[i];
        loc_y[i] += speed_y[i];
        loc_z[i] += speed_z[i];
        
        if(loc_x[i]<-dis){
            speed_x[i] = speed_x[i]*-1;
        }
        if(loc_x[i]>dis){
            speed_x[i] = speed_x[i]*-1;
        }
        if(loc_y[i]<-dis){
            speed_y[i] = speed_y[i]*-1;
        }
        if(loc_y[i]>dis){
            speed_y[i] = speed_y[i]*-1;
        }
        if(loc_z[i]<-dis){
            speed_z[i] = speed_z[i]*-1;
        }
        if(loc_z[i]>dis){
            speed_z[i] = speed_z[i]*-1;
        }
    }
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
    
    time = ofGetElapsedTimeMillis()*8;
    
    // 座標系を移動
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    cam.begin();
    //cam.setPosition(1000*cos(ofGetFrameNum()/8),1000+sin(ofGetFrameNum()/8)*-500,1000*sin(ofGetFrameNum()/8));
    //    cam.setPosition(dis*cos(time),0,dis*sin(time));
    //    cam.lookAt(ofVec3f(0,0,0),(ofVec3f(0,1,0)));
    if(space == true){
        ofRotateX(ofGetFrameNum());
        ofRotateY(ofGetFrameNum());
    }else{
    }
    
    for(int i=0; i<NUM; i++){
        ofSetColor(red[i], green[i], blue[i], (fftSmoothed[i]*250)+150);
        sphere.set(radius[i]+(fftSmoothed[i]*115)+(fftSmoothed[i_]*115), 2);
        sphere.setPosition(loc_x[i],loc_y[i],loc_z[i]);
        sphere.drawWireframe();
        
        //        ofDrawCircle(loc_x[i], loc_y[i], radius[i]);
    }
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(' '){
        space = !space;
    }
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
