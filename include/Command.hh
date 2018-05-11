//
// Created by student on 11.05.18.
//

#ifndef PW_1_GEOMETRY_COMMAND_HH
#define PW_1_GEOMETRY_COMMAND_HH
#include <G4UImessenger.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithAString.hh>
#include "DetGeometry.hh"
#include "PrimaryGen.hh"

class DetGeometry;
class PrimaryGen;
class Command: public G4UImessenger{

    G4UIcmdWithADouble *setSizeX;
    G4UIcmdWithAnInteger *setSizeY;
    G4UIcmdWithAString *setMaterial;
    G4UIcmdWithADouble *setEnergy;
    G4UIcommand * cmd;
    DetGeometry* my_command_size;
    PrimaryGen* my_command_energy;
public:
    Command(DetGeometry* geom);
    Command(PrimaryGen *pGen);
    ~Command();
    void SetNewValue(G4UIcommand *command, G4String newValue) override;


};

#endif //PW_1_GEOMETRY_COMMAND_HH
