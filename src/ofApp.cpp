#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

   //font sett

   the_font.load("futura_book.otf",20);

   //server
   recv.init();


   //local client
   client_dest = "localhost";
   client_port = 12000;
   local_client.setup(client_dest,client_port);

   // sample settings
   for(int i=0; i < 2; i++){

      ofSoundPlayer p;
      samples.push_back(p);

      samples.at(i).setMultiPlay(false);

   }
   samples.at(0).load("samples/1.wav");
   samples.at(1).load("samples/2.wav");


}

//--------------------------------------------------------------
void ofApp::update(){

   //update sound play sys
   ofSoundUpdate();

   recv.update();

  if(ofGetMousePressed(0)){

/*   ofxOscMessage m;
   m.setAddress("diego/perc");
   m.addIntArg(50);
   m.addIntArg(ofMap(mouseX, 0,ofGetWidth()-1,0,255));
   local_client.sendMessage(m,false);*/
     cout<<"presionado"<<endl;
   }
  ofxOscMessage m;
   m.setAddress("diego/perc");
   m.addIntArg(50);
   m.addIntArg(ofMap(mouseX, 0,ofGetWidth()-1,0,255));
   local_client.sendMessage(m,false);
   //2 message
 ofxOscMessage s;
   s.setAddress("miguel/perc");
   s.addIntArg(100);
   s.addIntArg(ofMap(mouseX, 0,ofGetWidth()-1,0,12));
   local_client.sendMessage(s,false);
   //pack client message

   // listen messages
/*  recv.setAddress("diego/perc");
  control_a = recv.getValues();*/

 recv.setAddress("miguel/perc");
  control_b = recv.getValues();
  


  if(control_b.size() >= 2){
     //play sounds from osc vals
     if(control_b.at(1) == 2){
//        samples.at(0).play();
     }else if(control_b.at(1) == 8){
        samples.at(1).play();
     }
  }

  // control_a= recv.getValues();

//   cout<<"valores"<<"\t"<<control_a.size()<<"\t"<<control_b.size()<<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){

   if(control_a.size() >= 2){
   the_font.drawString(ofToString(control_a.at(1)),200,200);
   }

   

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


   cout<<"el boton "<<button<<endl;
   if(button==0){

//   cout<<"ofGetWindowSize()"<<"   "<<ofGetWidth()<<"  "<<ofGetHeight()<<endl;
   }

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
