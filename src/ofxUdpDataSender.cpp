#include "ofxUdpDataSender.h"



ofxUdpDataSender::ofxUdpDataSender()
{
	isSetuped = false;
}


ofxUdpDataSender::~ofxUdpDataSender()
{
}

void ofxUdpDataSender::setup(string _ip, int _port)
{
	if (!isSetuped)
	{
		udpClient.Create();
		udpClient.SetNonBlocking(true);

		isSetuped = true;
	}
	ip = _ip;
	port = _port;

	udpClient.Connect(ip.c_str(), port);
}

int ofxUdpDataSender::sendData(const char *_data, int _size, bool _bPrint /* = true */)
{
	if (_bPrint)
	{
		ofLogNotice(OF_FUNCTION_NAME) << "ip:" << ip << " port:" << port << " send:" << endl;
		printTestData(_data, _size);
	}
	
	return udpClient.Send(_data, _size);
}

int ofxUdpDataSender::recvData(char * _data, int _size)
{
	return udpClient.Receive(_data, _size);
}

void ofxUdpDataSender::close()
{
	if (isSetuped)
	{
		udpClient.Close();
		isSetuped = false;
	}
}
