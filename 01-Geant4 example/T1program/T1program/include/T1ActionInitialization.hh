/// \file T1ActionInitialization.hh
/// \brief Definition of the T1ActionInitialization class

#ifndef T1ActionInitialization_h
#define T1ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class T1DetectorConstruction;

class T1ActionInitialization : public G4VUserActionInitialization
{
	public:
	  T1ActionInitialization(T1DetectorConstruction*);
	  ~T1ActionInitialization();
	  virtual void Build() const;

	private:
	  T1DetectorConstruction* fDetConstruction;
};

#endif
