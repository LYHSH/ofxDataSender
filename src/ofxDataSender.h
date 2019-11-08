#pragma once
#include "ofMain.h"
#include "ofxMyConstants.h"
/************************************************************************/
/* file describe:数据发送器基类
/* date:2017.7.16
/* author:hui
/* update:2018.11.12
/************************************************************************/
class ofxDataSender
{
public:
	ofxDataSender();
	virtual ~ofxDataSender();

	virtual int sendData(const char *_data, int _size,bool _bPrint = true) = 0;
	virtual int recvData(char * _data, int _size) = 0;
	virtual void close() = 0;

protected:
	void printTestData(const char *_data, int _size);
};

