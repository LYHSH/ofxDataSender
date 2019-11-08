#pragma once
#include "ofMain.h"
#include "ofxUDPManager.h"
#include "ofxDataSender.h"
/************************************************************************/
/* file describe:UDP·¢ËÍ¶Ë
/* date:2017.7.31
/* author:hui
/* update:2018.11.12
/************************************************************************/
class ofxUdpDataSender : public ofxDataSender
{
public:
	ofxUdpDataSender();
	~ofxUdpDataSender();

	void setup(string _ip, int _port);

	int sendData(const char *_data, int _size, bool _bPrint = true) override final;
	int recvData(char * _data, int _size) override final;

	void close() override final;

private:
	string ip;
	int port;
	ofxUDPManager udpClient;

	bool isSetuped;
};

