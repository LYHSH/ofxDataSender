#include "ofxDataSenderFacory.h"
#include "ofxTcpDataSender.h"
#include "ofxSerialDataSender.h"
#include "ofxUdpDataSender.h"


ofxDataSenderFacory::ofxDataSenderFacory()
{
}


ofxDataSenderFacory::~ofxDataSenderFacory()
{
}

ofxDataSender * ofxDataSenderFacory::createTcpSender(string _ip, int _port)
{
	ofxTcpDataSender * sender = new ofxTcpDataSender();
	sender->setup(_ip, _port);

	return sender;
}

ofxDataSender * ofxDataSenderFacory::createSerialSender(int _comNum, int _nBaud)
{
	ofxSerialDataSender * sender = new ofxSerialDataSender();
	sender->setup(_comNum, _nBaud);

	return sender;
}

ofxDataSender * ofxDataSenderFacory::createSerialSender(string _comName, int _nBaud)
{
	ofxSerialDataSender * sender = new ofxSerialDataSender();
	sender->setup(_comName, _nBaud);

	return sender;
}

ofxDataSender * ofxDataSenderFacory::createUdpSender(string _ip, int _port)
{
	ofxUdpDataSender * sender = new ofxUdpDataSender();
	sender->setup(_ip, _port);

	return sender;
}