/// \file T1RunAction.cc
/// \brief Implementation of the T1RunAction class

#include "T1RunAction.hh"
#include "T1Analysis.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

T1RunAction::T1RunAction() : G4UserRunAction()
{
	// set printing event number per each event 
	// **Reset this parameter to see what it means.**
	G4RunManager::GetRunManager()->SetPrintProgress(1); 

	// Create analysis manager
	// Interface with root, setted in T1Analysis.hh
	auto analysisManager = G4AnalysisManager::Instance();
	G4cout << "Using" << analysisManager->GetType() << G4endl;

	//Create directories
	//analysisManager->SetHistoDirectoryName("histograms"); // Why didn't use?

	analysisManager->SetVerboseLevel(1);

	// Creating histogram
	analysisManager->CreateH1("p_x",
							  "X component of momentum",
							  70,         // Number of bins
							  /*-5*cm*/-7.7*MeV,    
							  /*5*cm*/  7.0*MeV);    // Range of the histogram
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

T1RunAction::~T1RunAction()
{
	delete G4AnalysisManager::Instance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void T1RunAction::BeginOfRunAction(const G4Run* /*run*/)
{
	// Get analysis manager 
	auto analysisManager = G4AnalysisManager::Instance();

	// Open an output file 
	analysisManager->OpenFile("T1_Px");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

void T1RunAction::EndOfRunAction(const G4Run* /*run*/)
{
	// print histogram statistics
	auto analysisManager = G4AnalysisManager::Instance();
	
	// save histograms
	analysisManager->Write();
	analysisManager->CloseFile();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....
