#include "Osc_handler.h"
#include "constants.h"


// config //

void Osc_handler::init(){

   ofSetLogLevel(OF_LOG_VERBOSE);
   server.setup(PORT);

   current_msg_string = 0;

   font.load("futura_book.otf",12);
}
void Osc_handler::update(){


   while(server.hasWaitingMessages()){


      ofxOscMessage m;
      server.getNextMessage(&m);

      //log information
     // ofLogVerbose(getOscMsgAsString(m));


      if(m.getNumArgs() > 0){
      vals =   getOscValuesByAddress(the_address, m);
      }
   }
}
vector<int> Osc_handler::getValues(){

   return vals;
}
string Osc_handler::getOscMsgAsString(ofxOscMessage m){
   string msg_string;
   msg_string = m.getAddress();
   msg_string += ":";
   for(int i = 0; i < m.getNumArgs(); i++){
      // get the argument type
      msg_string += " " + m.getArgTypeName(i);
      msg_string += ":";
      // display the argument - make sure we get the right type
      if(m.getArgType(i) == OFXOSC_TYPE_INT32){
         msg_string += ofToString(m.getArgAsInt32(i));
      }
      else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
         msg_string += ofToString(m.getArgAsFloat(i));
      }
      else if(m.getArgType(i) == OFXOSC_TYPE_STRING){
         msg_string += m.getArgAsString(i);
      }
      else{
         msg_string += "unknown";
      }
   }
   return msg_string;
}

string Osc_handler::setAddress(string s){
   the_address = s;
}

vector<int> Osc_handler::getOscValuesByAddress(string address, ofxOscMessage message){
   vector<int> values;
//cout<<"dir"<<message.getAddress()<<endl;
   if(message.getAddress() == address){

 //     cout<<"numero_argumentos"<<"\t"<<s.getNumArgs()<<endl;
      for(int i =0; i < message.getNumArgs(); i++){

         values.push_back(message.getArgAsInt(i));
      }
//      cout<<values.at(1)<<endl;
      return values;
   }


}
