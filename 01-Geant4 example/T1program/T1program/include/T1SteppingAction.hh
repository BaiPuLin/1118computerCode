/// \file T1SteppingAction.hh
/// \brief Definition of the T1SteppingAction class

#ifndef T1SteppingAction_h
#define T1SteppingAction_h 1

#include "G4UserSteppingAction.hh"

class T1DetectorConstruction;
class T1EventAction;

/// Stepping class.
///
/// Add every Stepping Length to T1Event::fTrackLength, Reset T1EventAction
/// ::fPz with Stepping Pz

class T1SteppingAction : public G4UserSteppingAction
{
	public:
		T1SteppingAction(T1EventAction* eventAction);
		virtual ~T1SteppingAction();

		virtual void UserSteppingAction(const G4Step* step);

	private:
		T1EventAction* fEventAction;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
