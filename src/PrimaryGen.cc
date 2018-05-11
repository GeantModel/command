
#include <G4RunManager.hh>
#include <Command.hh>
#include "PrimaryGen.hh"

PrimaryGen::PrimaryGen() {
    detCommand = new Command(this);
    gun = new G4ParticleGun(1);
    G4cout<<"Primary particles generator is created successfully\t\tOK!!!"<<G4endl;
    Energy = 0.662;
}

PrimaryGen::~PrimaryGen()
{
    delete detCommand;
}

void PrimaryGen::GeneratePrimaries(G4Event* anEvent)
{
    gun->SetParticleDefinition(G4Gamma::GammaDefinition());
    gun->SetParticleEnergy(Energy*MeV);
    gun->SetParticlePosition(G4ThreeVector(-20*cm,0,0));
    gun->SetParticleMomentumDirection(G4ThreeVector(1, 0, 0));
    gun->GeneratePrimaryVertex(anEvent);
}


void PrimaryGen::setEnergy(G4double newEnergy) {
    PrimaryGen::Energy = newEnergy;
}