/// \file T1PrimaryGeneratorAction.cc
/// \brief Implementation of the T1PrimaryGeneratorAction class

#include "T1PrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

T1PrimaryGeneratorAction::T1PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0),
  fPlateDistanceX(2.5*cm) 
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);

  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="alpha");

  // The default kinematic is a 7.7 MeV alpha, shooted to the plate in parallel

  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleMomentum(G4ThreeVector(7.7*MeV,0.,0.));
  //fParticleGun->SetParticleEnergy(7.7*MeV);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

T1PrimaryGeneratorAction::~T1PrimaryGeneratorAction()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void T1PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  //this function is called at the begining of ecah event
  //
  
  G4double SourceCenterX = -fPlateDistanceX;
  G4double SourceCenterYZ = 0*cm;
  G4double RayWidth = 0.01*cm;
  G4double x0 = SourceCenterX + 0;
  G4double y0 = RayWidth * (G4UniformRand()-0.5) + SourceCenterYZ;
  G4double z0 = RayWidth * (G4UniformRand()-0.5) + SourceCenterYZ;
  
  fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));

  fParticleGun->GeneratePrimaryVertex(anEvent);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

