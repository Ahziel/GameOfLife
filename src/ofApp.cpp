#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// Set Background color to black
	ofSetBackgroundColor(0);

	game = GameOfLife(ofGetWindowHeight(),200);
	game.createRandomGrid();

	gameOn = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	buffer.draw(0, 0);

	if (gameOn)
	{
		game.applyRules();
		//gameOn = !gameOn;
	}
	
	buffer.allocate(ofGetWidth(), ofGetHeight());
	buffer.begin();
	// Draw the grid
	game.draw();
	buffer.end();

	ofSleepMillis(25);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'p')
	{
		gameOn = !gameOn;
	}
	if (key == 'n')
	{
		game.createRandomGrid();
	}
	if (key == 'b')
	{
		game.createBlankGrid();
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	int i = (int)(x / game.m_squareSize);
	int j = (int)(y / game.m_squareSize);

	bool val = !game.getValue(i,j);
	game.setValue(i,j,val);
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
