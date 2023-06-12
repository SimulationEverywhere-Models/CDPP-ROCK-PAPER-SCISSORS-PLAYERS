#ifndef __ACTIONMAKER_H
#define __ACTIONMAKER_H

#include "atomic.h"     // class Atomic

class ActionMaker : public Atomic
{
	public:
		ActionMaker(const string &name = "ActionMaker"); // Default constructor
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
string ActionMaker::className() const
{
	return "ActionMaker" ;
}

#endif   //__ACTIONMAKER_H
