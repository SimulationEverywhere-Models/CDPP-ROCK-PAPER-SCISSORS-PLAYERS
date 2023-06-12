#include "comparer.h"
#include "message.h"
#include "mainsimu.h"
#include <stdlib.h>
#include <stdio.h>

Comparer::Comparer( const string &name ): Atomic(name)
	, preparationTime( 0, 0, 0, 0 )
	, playGame( this->addInputPort( "playGame" ) )
	, gameAction1( this->addInputPort( "gameAction1" ) )
	, gameAction2( this->addInputPort( "gameAction2" ) )
	, playGame1( this->addOutputPort( "playGame1" ) )
	, playGame2( this->addOutputPort( "playGame2" ) )
	, winReport( this->addOutputPort( "winReport" ) )
{
	string time( MainSimulator::Instance().getParameter( this->description(), "preparation" ) ) ;
	if( time != "" )
		preparationTime = time ;
}

Model &Comparer::initFunction()
{
	this-> passivate();
	action1 = action2 = 0;
	newGame = false;
	return *this;
}

Model &Comparer::externalFunction( const ExternalMessage &msg )
{
	// new game request
	if( msg.port() == playGame)
	{
		newGame = true;
		this->holdIn( active, preparationTime );
	}
	// collect player responses
	if( msg.port() == gameAction1)
	{
		action1 = static_cast<int>( msg.value() );
		this->holdIn( active, preparationTime );
	}
	if( msg.port() == gameAction2)
	{
		action2 = static_cast<int>( msg.value() );
		this->holdIn( active, preparationTime );
	}
	printf( "action1 = %d action2 = %d \n", action1, action2 );
	return *this;
}

Model &Comparer::outputFunction( const InternalMessage &msg )
{
	if(newGame) // if we are dealing with a request for a new game
	{
		newGame = false;
		action1 = action2 = 0;
		this->sendOutput( msg.time(), playGame1, 1 ) ; // simply send a message to the request port
		this->sendOutput( msg.time(), playGame2, 1 ) ;
	}
	else if(action1 != 0 && action2 != 0) // if we have responses from both players
	{
		// which player, 1 or 2, is the winner?
		int winner = 0; // zero represents a tie
		if(action1 == 1 && action2 == 2)
			winner = 2;
		if(action1 == 1 && action2 == 3)
			winner = 1;
		if(action1 == 2 && action2 == 1)
			winner = 1;
		if(action1 == 2 && action2 == 3)
			winner = 2;
		if(action1 == 3 && action2 == 1)
			winner = 2;
		if(action1 == 3 && action2 == 2)
			winner = 1;
		// report the winner
		this->sendOutput( msg.time(), winReport, winner ) ;
		action1 = action2 = 0; // after reporting a game, dispose of its values
	}
	return *this ;
}

Model &Comparer::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}
