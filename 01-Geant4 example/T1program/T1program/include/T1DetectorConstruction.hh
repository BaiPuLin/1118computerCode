//
// *******************************************
// a Au Plate in the world
// *******************************************
//
/// \file T1DetectorConstruction.hh
/// \brief Declaration of the T1DetectorConstruction class

#ifndef T1DetectorConstruction_h
#define T1DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume; 
class G4LogicalVolume;

/// Detector construction class to define materials and geometry

class T1DetectorConstruction : public G4VUserDetectorConstruction
{
    public:
        T1DetectorConstruction();  // To initialize of this class
        virtual ~T1DetectorConstruction();  // To clear the memory after using this class

        virtual G4VPhysicalVolume* Construct();
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#endif 
