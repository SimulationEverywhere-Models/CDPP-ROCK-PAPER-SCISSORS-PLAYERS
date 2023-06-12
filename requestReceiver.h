#ifndef __REQUESTRECEIVER_H
#define __REQUESTRECEIVER_H

#include "atomic.h"     // class Atomic

class RequestReceiver : public Atomic
{
	public:
		RequestReceiver(const string &name = "RequestReceiver"); // Default constructor
		virtual string className() const ;
	protected:
		Model &initFunction();
		Model &externalFunction( const ExternalMessage & );
		Model &internalFunction( const InternalMessage & );
		Model &outputFunction( const InternalMessage & );
	private:
		// ports
		const Port &in;
		Port &out;
		// time variables
		Time preparationTime;
		// state variables
		// (none, just using active or passive and passing a message through to the ActionMaker)
};

inline
string RequestReceiver::className() const
{
	return "RequestReceiver" ;
}

#endif   //__REQUESTRECEIVER_H
