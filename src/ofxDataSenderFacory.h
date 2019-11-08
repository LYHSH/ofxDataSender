#pragma once
#include "ofxDataSender.h"
class ofxDataSenderFacory
{
public:
	ofxDataSenderFacory();
	~ofxDataSenderFacory();

	static ofxDataSender * createTcpSender(string _ip,int _port);			
	static ofxDataSender * createSerialSender(int _comNum,int _nBaud);
	static ofxDataSender * createSerialSender(string _comName, int _nBaud);
	static ofxDataSender * createUdpSender(string _ip, int _port);
};

