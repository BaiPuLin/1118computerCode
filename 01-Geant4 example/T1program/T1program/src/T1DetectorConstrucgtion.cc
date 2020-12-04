/// \file T1DetectorConstrucgtion.cc
/// \brief Defination of the T1DetectorConstruction class

#include "T1DetectorConstruction.hh"

#include "G4RunManager.hh"  
#include "G4NistManager.hh" //include the standard materials
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
//#include "G4UnitsTable.hh" 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
T1DetectorConstruction::T1DetectorConstruction()
: G4VUserDetectorConstruction()
{ }

T1DetectorConstruction::~T1DetectorConstruction()
{ }
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

G4VPhysicalVolume* T1DetectorConstruction::Construct()
{
    // Get nist material manager
    G4NistManager* nist = G4NistManager::Instance();

    // Plate parameters
    G4double pla_sizeX = 288e-12*m, pla_sizeYZ = 10*cm;
    G4Material* pla_mat = nist->FindOrBuildMaterial("G4_Au");

    // World
    G4double world_sizeXYZ = 1.2*pla_sizeYZ;

	// World Material
	//G4UnitDefinition::BuildUnitsTable();
	G4Material* world_mat = new G4Material("Galactic", 1., 1.01*g/mole, 
											1.e-25*g/cm3, kStateGas,
											0.1*kelvin, 1.e-19*pascal);

	//G4Material* world_mat = new G4Material("world_mat",18,39.95*g/mole,1.390*g/cm3);  //Vacuum, there is nothing

    G4Box* solidWorld =    
        new G4Box("World",                       //its name
           0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);     //its size

    G4LogicalVolume* logicWorld = 
        new G4LogicalVolume(solidWorld,          //its solid
                            world_mat,           //its material
                            "World");            //its name

    G4VPhysicalVolume* physWorld = 
        new G4PVPlacement(0,                     //no rotation
                          G4ThreeVector(),       //at (0,0,0)
                          logicWorld,            //its logical volume
                          "World",               //its name
                          0,                     //its mother  volume
                          false,                 //no boolean operation
                          0);                    //copy number

    // Plate
    G4Box* solidPla =    
        new G4Box("Plate",                    //its name
            0.5*pla_sizeX, 0.5*pla_sizeYZ, 0.5*pla_sizeYZ); //its size
    
    G4LogicalVolume* logicPla = 
        new G4LogicalVolume(solidPla,            //its solid
                            pla_mat,             //its material
                            "Plate");            //its name

    G4VPhysicalVolume* physPla = 
        new G4PVPlacement(0,                     //no rotation
                          G4ThreeVector(),       //at (0,0,0)
                          logicPla,              //its logical volume
                          "Plate",               //its name
                          logicWorld,            //its mother volume
                          false,                 //no boolean operation
                          0);                    //copy number

    return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....


