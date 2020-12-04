/// \file T1ActionInitialization.cc
/// \breif Implementation of the T1ActionInitialization class

#include "T1ActionInitialization.hh"
#include "T1PrimaryGeneratorAction.hh"
#include "T1RunAction.hh"
#include "T1EventAction.hh"
#include "T1SteppingAction.hh"
#include "T1DetectorConstruction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

T1ActionInitialization::T1ActionInitialization
							(T1DetectorConstruction* detConstruction)
 : G4VUserActionInitialization(),
	fDetConstruction(detConstruction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

T1ActionInitialization::~T1ActionInitialization()
{}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void T1ActionInitialization::Build() const
{
	SetUserAction(new T1PrimaryGeneratorAction);
	SetUserAction(new T1RunAction);
	auto eventAction = new T1EventAction(); // No brackets to use the default constructor
	SetUserAction(eventAction);
	SetUserAction(new T1SteppingAction(eventAction));
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
