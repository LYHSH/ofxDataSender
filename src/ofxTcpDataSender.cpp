#include "ofxTcpDataSender.h"



ofxTcpDataSender::ofxTcpDataSender()
{
}


ofxTcpDataSender::~ofxTcpDataSender()
{
	close();
}

void ofxTcpDataSender::setup(string _ip, int _port)
{
	ip = _ip;
	port = _port;
}

int ofxTcpDataSender::sendData(const char *_data, int _size, bool _bPrint /* = true */)
{
	if (_bPrint)
	{
		ofLogNotice(OF_FUNCTION_NAME) << "ip:" << ip << " port:" << port << " send:" << endl;
		printTestData(_data, _size);
	}
	
#ifndef LOCAL_DEBUG
	if (!tcpClient.isConnected())
	{
		bConnected = tcpClient.setup(ip, port, false);
	}

	if (bConnected)
	{
		Sleep(300);				//投影机指令发送时间延迟

		bConnected = tcpClient.sendRawBytes(_data, _size);


		Sleep(300);				//投影机指令发送时间延迟
		tcpClient.close();
	}
#endif
	
	return bConnected;
}

int ofxTcpDataSender::recvData(char * _data, int _size)
{
	if (!tcpClient.isConnected())
	{
		bConnected = tcpClient.setup(ip, port, false);
	}

	if (bConnected)
	{
		Sleep(200);

		return tcpClient.receiveRawBytes(_data, _size);
	}
	return 0;
}

void ofxTcpDataSender::close()
{
	tcpClient.close();
}
