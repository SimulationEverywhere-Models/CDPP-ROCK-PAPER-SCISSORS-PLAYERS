#include "requestReceiver.h"
#include "message.h"
#include "mainsimu.h"

RequestReceiver::RequestReceiver( const string &name ): Atomic(name)
	, preparationTime( 0, 0, 1, 0 )
	, in( this->addInputPort( "in" ) )
	, out( this->addOutputPort( "out" ) )
{
	string time( MainSimulator::Instance().getParameter( this->description(), "preparation" ) ) ;
	if( time != "" )
		preparationTime = time ;
}

Model &RequestReceiver::initFunction()
{
	this-> passivate();
	return *this;
}

Model &RequestReceiver::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in)
	{
		this->holdIn( active, preparationTime ); // we are now reacting to the input
	}
	return *this;
}

Model &RequestReceiver::outputFunction( const InternalMessage &msg )
{
	this->sendOutput( msg.time(), out, 1 ) ; // simply send a message to the out port
	return *this ;
}

Model &RequestReceiver::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}
