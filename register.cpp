#include "modeladm.h" 
#include "requestReceiver.h"
#include "actionMaker.h"
#include "comparer.h"
#include "message.h"
#include "mainsimu.h"

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<	RequestReceiver		>(), "RequestReceiver"		) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<	ActionMaker			>(), "ActionMaker"			) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<	Comparer			>(), "Comparer"				) ;
}
