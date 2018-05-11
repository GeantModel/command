

#ifndef CPROJECT_PRIMARYGEN_HH
#define CPROJECT_PRIMARYGEN_HH


#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

#include "G4Event.hh"

#include "G4SystemOfUnits.hh"

#include "G4Gamma.hh"

class G4ParticleGun;
class G4Event;
class Command;

class PrimaryGen : public G4VUserPrimaryGeneratorAction
{
private:
    G4ParticleGun*  gun;
    G4double Energy;
    Command *detCommand;

public:
    PrimaryGen();
    virtual ~PrimaryGen();
    virtual void GeneratePrimaries(G4Event*);
    void setEnergy(double newEnergy);
};

#endif //CPROJECT_PRIMARYGEN_HH
