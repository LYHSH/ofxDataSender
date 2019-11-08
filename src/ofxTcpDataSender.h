#pragma once
#include "ofxDataSender.h"
#include "ofxTCPClient.h"

//#define LOCAL_DEBUG
/************************************************************************/
/* file describe:TCP·¢ËÍ¶Ë
/* date:2017.7.16
/* author:hui
/* update:2018.11.12
/************************************************************************/
class ofxTcpDataSender : public ofxDataSender
{
public:
	ofxTcpDataSender();
	~ofxTcpDataSender();

	void setup(string _ip,int _port);

	int sendData(const char *_data, int _size, bool _bPrint = true) override final;
	int recvData(char * _data, int _size) override final;

	void close() override final;

private:
	string ip;
	int port;
	bool bConnected;
	ofxTCPClient tcpClient;
};

