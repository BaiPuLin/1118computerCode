/// \file T1RunAction.h
/// \brief Definition of the T1RunAction class.

#ifndef T1RunAction_h
#define T1RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"  // Global Constants and typedefs

class G4Run;  // What does it means?

/// Run action class
/// 
/// It count the z-component of momentum of the particle in the last time 
/// of this Run.

class T1RunAction : public G4UserRunAction
{
	public:
		T1RunAction();
		virtual ~T1RunAction();

		virtual void BeginOfRunAction(const G4Run*);
		virtual void EndOfRunAction(const G4Run*);
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
