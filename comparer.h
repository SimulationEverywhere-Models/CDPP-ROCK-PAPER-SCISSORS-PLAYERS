#ifndef __COMPARER_H
#define __COMPARER_H

#include "atomic.h"     // class Atomic

class Comparer : public Atomic
{
	public:
		Comparer(const string &name = "Comparer"); // Default constructor
		virtual string className() const ;
	protected:
		Model &initFunction();
		Model &externalFunction( const ExternalMessage & );
		Model &internalFunction( const InternalMessage & );
		Model &outputFunction( const InternalMessage & );
	private:
		// ports
		const Port &playGame;
		const Port &gameAction1;
		const Port &gameAction2;
		Port &playGame1;
		Port &playGame2;
		Port &winReport;
		// time variables
		Time preparationTime;
		// state variables
		int action1;
		int action2;
		bool newGame; // have we received a request for a new game?
};

inline
string Comparer::className() const
{
	return "Comparer" ;
}

#endif   //__COMPARER_H
