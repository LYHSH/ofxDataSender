#include "ofxDataSenderMgr.h"



ofxDataSenderMgr::ofxDataSenderMgr()
{
}


ofxDataSenderMgr::~ofxDataSenderMgr()
{
}

void ofxDataSenderMgr::setup(const string & _filename)
{
	ofxXmlSettings xml;
	xml.load(_filename);

	int nums = xml.getNumTags("DATA_SENDER");
	senders.resize(nums);

	for (int i = 0; i < nums; ++i)
	{
		xml.pushTag("DATA_SENDER", i);
		
		if (xml.tagExists("SERIAL"))
		{
			xml.pushTag("SERIAL");
			string comstr = xml.getValue("COM", "COM4");
			int nBaud = xml.getValue("N_BAUD", 9600);
			senders[i] = ofxDataSenderFacory::createSerialSender(comstr, nBaud);
			xml.popTag();
		}
		else if (xml.tagExists("UDP"))
		{
			xml.pushTag("UDP");
			string ip = xml.getValue("IP", "127.0.0.1");
			int port = xml.getValue("PORT", 55555);
			senders[i] = ofxDataSenderFacory::createUdpSender(ip, port);
			xml.popTag();
		}
		else if (xml.tagExists("TCP"))
		{
			xml.pushTag("TCP");
			string ip = xml.getValue("IP", "127.0.0.1");
			int port = xml.getValue("PORT", 55555);
			senders[i] = ofxDataSenderFacory::createTcpSender(ip, port);
			xml.popTag();
		}
		xml.popTag();
	}
}

ofxDataSender * ofxDataSenderMgr::getSender(int _index)
{
	if (!checkOut(_index))return NULL;
	
	return senders[_index];
}

int ofxDataSenderMgr::size()const
{
	return senders.size();
}

bool ofxDataSenderMgr::checkOut(int _index)const
{
	bool res = true;
	res &= _index >= 0;
	res &= _index < size();
	return res;
}