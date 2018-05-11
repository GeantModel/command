//
// Created by student on 11.05.18.
//

#ifndef PW_1_GEOMETRY_DETGEOMETRYMESSENGER_HH
#define PW_1_GEOMETRY_DETGEOMETRYMESSENGER_HH

#include <G4UImessenger.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithAString.hh>
#include "DetGeometry.hh"

class DetGeometry;
class DetGeometryMessenger: public G4UImessenger{

    G4UIcmdWithADouble *setSizeX;
    G4UIcmdWithAnInteger *setSizeY;
    G4UIcmdWithAString *setMaterial;
    G4UIcommand * cmd;
    DetGeometry* my_command;
public:
    DetGeometryMessenger(DetGeometry* geom);
    ~DetGeometryMessenger();
    void SetNewValue(G4UIcommand *command, G4String newValue) override;
};

#endif //PW_1_GEOMETRY_DETGEOMETRYMESSENGER_HH
