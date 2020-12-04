/// \file T1SteppingAction.cc
/// \brief Implementation of the T1SteppingAction class

#include "T1SteppingAction.hh"
#include "T1EventAction.hh"
//#include "T1DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
//#include "G4ThreeVector.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

T1SteppingAction::T1SteppingAction(T1EventAction* eventAction)
	: G4UserSteppingAction(),
	  fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

T1SteppingAction::~T1SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void T1SteppingAction::UserSteppingAction(const G4Step* step)
{
	// Get Length
	G4double steplength = 0.;
	steplength = step->GetStepLength();

	// Get Pz
	G4ThreeVector P = step->GetPostStepPoint()->GetMomentum();
	G4double Px = P.x();
/*
	G4cout << "     Px = " << Px ;
	G4cout << "      X = " << step->GetPostStepPoint()->GetPosition().x();
	G4cout << " Length = " << fEventAction->GetLength() << G4endl;
*/
	// Add to EventAction
	fEventAction->AddLength(steplength);

	// Update Pz
	if (fEventAction->GetLength() >= 2.5*cm){
	fEventAction->UpdatePx(Px);
	}

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
