#include "actionMaker.h"
#include "message.h"
#include "mainsimu.h"
#include <stdlib.h>
#include <stdio.h>

ActionMaker::ActionMaker( const string &name ): Atomic(name)
	, preparationTime( 0, 0, 0, 50 )
	, in( this->addInputPort( "in" ) )
	, out( this->addOutputPort( "out" ) )
{
	string time( MainSimulator::Instance().getParameter( this->description(), "preparation" ) ) ;
	if( time != "" )
		preparationTime = time ;
}

Model &ActionMaker::initFunction()
{
	this-> passivate();
	return *this;
}

Model &ActionMaker::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in)
	{
		this->holdIn( active, preparationTime ); // we are now reacting to the input
	}
	return *this;
}

Model &ActionMaker::outputFunction( const InternalMessage &msg )
{
	int action = rand() % 3 + 1; // integer between 1 and 3 inclusive
	printf( "selected action = %d \n", action );
	this->sendOutput( msg.time(), out, action ) ;
	return *this ;
}

Model &ActionMaker::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}
