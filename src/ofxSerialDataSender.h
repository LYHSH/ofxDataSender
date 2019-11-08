#pragma once
#include "ofxDataSender.h"
#include "ofxSerial.h"
/************************************************************************/
/* file describe:´®¿Ú·¢ËÍ¶Ë
/* date:2017.7.16
/* author:hui
/************************************************************************/
class ofxSerialDataSender: public ofxDataSender
{
public:
	ofxSerialDataSender();
	~ofxSerialDataSender();

	bool setup(int _comNum, int _nBaud);
	bool setup(string _comName, int _nBaud);

	int sendData(const char *_data, int _size,bool _bPrint = true) override final;
	int recvData(char * _data, int _size) override final;

	void close() override final;
private:
	ofxSerial serial;
	string portName;
	int nBaud;
};

