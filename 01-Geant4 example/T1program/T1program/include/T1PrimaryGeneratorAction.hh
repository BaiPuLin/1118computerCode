/// \file T1PrimaryGeneratorAction.hh
/// \brief Declaration of the T1PrimaryGeneratorAction class

#ifndef T1PrimaryGeneratorAction_h
#define T1PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"

class G4ParticleGun;
class G4Event;


/// The primary generator action class with particle gun.
///
/// The default kinematic is a 7.7 MeV alpha, shooted to the plate in parallel

class T1PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    T1PrimaryGeneratorAction();    
    virtual ~T1PrimaryGeneratorAction();

    // method from the base class
    virtual void GeneratePrimaries(G4Event*);         
    
	// get distance between particle gun and plante
	G4double GetPlateDistanceX();
  private:
    G4ParticleGun*  fParticleGun; // pointer a to G4 gun class
	G4double fPlateDistanceX; // distance between particle gun and plant
};

// inline functions

inline G4double T1PrimaryGeneratorAction::GetPlateDistanceX(){return fPlateDistanceX;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
