/// \file T1EventAction.hh
/// \brief Definition of the T1EventAction class

#ifndef T1EventAction_h
#define T1EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

/// Event action class
///
/// Cauculate the tracking Length and x component of the output particle

class T1EventAction : public G4UserEventAction
{
	public:
		T1EventAction();
		virtual ~T1EventAction();
		
		virtual void BeginOfEventAction(const G4Event* event);
		virtual void EndOfEventAction(const G4Event* event);

		void AddLength(G4double l);
		void UpdatePx(G4double p);
		G4double GetLength();
	private:
		G4double fPx;
		G4double fTrackL;
};

// inline functions

inline void T1EventAction::AddLength(G4double l){
	fTrackL += l; // Sum all of step length
}

inline void T1EventAction::UpdatePx(G4double p){
	fPx = p;
}

inline G4double T1EventAction::GetLength(){
	return fTrackL;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

#endif
