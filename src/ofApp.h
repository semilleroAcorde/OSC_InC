#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Osc_handler.h"

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


		
      Osc_handler recv;

      ofxOscSender local_client;
      string client_dest;
      int client_port;

      ofTrueTypeFont the_font;
      
      vector<int> control_a, control_b;
      
      // sounds
     vector<ofSoundPlayer> samples;
     bool s1;
      

};
