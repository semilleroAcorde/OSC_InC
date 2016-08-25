#pragma once
#include "ofMain.h"
#include "ofxOsc.h"
#include "constants.h"

class Osc_handler : public ofBaseApp{
   public:

      void init();
      void update();


      ofxOscReceiver server;
      ofTrueTypeFont font;

      string the_address;


      int current_msg_string;
      string msg_strings[NUM_MSG_STRINGS];
      float timers[NUM_MSG_STRINGS];
      vector<string> server_messages;
      string from_client;

      string getOscMsgAsString(ofxOscMessage m);
      string setAddress(string s);
      vector<int> getOscValuesByAddress(string address, ofxOscMessage message);
      vector<int> vals;
      vector<int> getValues();

};
