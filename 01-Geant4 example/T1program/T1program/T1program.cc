/// \file exampleB1.cc
/// \brief Main program of the B1 example

// Debug
#include <iostream>
using namespace std;
//------------------

#include "T1DetectorConstruction.hh"
#include "T1ActionInitialization.hh"

#include "G4RunManager.hh"

#include "G4UImanager.hh"
#include "QBBC.hh"
#include "FTFP_BERT.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Randomize.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc,char** argv)
{
	G4UIExecutive* ui = 0;
	if ( argc == 1 ){
		ui = new G4UIExecutive(argc, argv);
	}
    // Create a runManager
    G4RunManager* runManager = new G4RunManager;
    
    // Set mandatory initialization classes
    // Detector construction
	T1DetectorConstruction* detConstruction = new T1DetectorConstruction();
    runManager->SetUserInitialization(detConstruction);

    //Physics list
	/*
    G4VPhysicsConstructor* physicsList = new G4EmStandardPhysics();
    physicsList ->SetVerboseLevel(1);  // 
	physicsList ->ConstructParticle();
	physicsList ->ConstructProcess();
    runManager ->SetUserInitialization(physicsList);
	*/

	G4VModularPhysicsList* physicsList = new QBBC;
    physicsList ->SetVerboseLevel(1);  // 
    runManager ->SetUserInitialization(physicsList);

    // Primary generator action
    runManager->SetUserInitialization(new T1ActionInitialization(detConstruction));

    // Initialize visualization
    //
    G4VisManager* visManager = new G4VisExecutive;
    
    // Initialize
    visManager->Initialize();

    // Get the pointer to the User Interface manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    // interactive mode
	if ( ! ui ) {
		// batch mode
		G4String command = "/control/execute ";
		G4String fileName = argv[1];
		G4cout << "!!!!!! " << command+fileName << endl;
		UImanager->ApplyCommand(command+fileName);
	}
	else {
		// interactive mode
		UImanager->ApplyCommand("/control/execute init_vis.mac");
		ui->SessionStart();
		delete ui;
	}

////////////////////
// start a run in a purely hark-coded batch mode
//
// int numberOfEvent = 3;
//
// runManager->BeamOn(numberOfEvent);
//
///////////////////

    //Free up the memory
    delete visManager;
    delete runManager;
    return 0;
}
