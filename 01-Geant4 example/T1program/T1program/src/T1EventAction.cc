/// \file T1EventAction.cc
/// \brief Implementation of the T1EventAction class

#include "T1EventAction.hh"
#include "T1RunAction.hh"
#include "T1Analysis.hh"
#include "T1PrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"

//#include "Randomize.hh"
//#include <iomanip>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

T1EventAction::T1EventAction() : G4UserEventAction(),
								 fPx(0.),
								 fTrackL(0.)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

T1EventAction::~T1EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void T1EventAction::BeginOfEventAction(const G4Event* /*event*/)
{
	// initialisation per event
	fPx = 0.;
	fTrackL = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void T1EventAction::EndOfEventAction(const G4Event* event)
{
	// get analysis manager
	auto analysisManger = G4AnalysisManager::Instance();

	// fill histograms
	auto PGA = new T1PrimaryGeneratorAction();
	if (fTrackL >= PGA->GetPlateDistanceX() )
	{
		analysisManger->FillH1(0,fPx);

		G4cout << "Event(" << event->GetEventID() << ") has been FILLED" << G4endl;
		G4cout << "px = " << G4BestUnit(fPx,"Energy") << ";" << G4endl << G4endl;
	}
	else {
		G4cout << "Event(" << event->GetEventID() << ") has been REJECTED" << G4endl;
		G4cout << "px = " << G4BestUnit(fPx,"Energy") << ";" << G4endl;
	}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
