//
// Created by student on 11.05.18.
//

#include <G4UIcommand.hh>
#include <DetGeometryMessenger.hh>
#include <G4UIcmdWithAString.hh>

void DetGeometryMessenger::SetNewValue(G4UIcommand *command, G4String newValue) {
    if(command == cmd)
        exit(80);
    if(command == setSizeX)
        my_command->setBoxXsize(setSizeX->GetNewDoubleValue(newValue));
    if(command == setSizeY)
        my_command->setBoxYsize(setSizeY->GetNewIntValue(newValue));
    if(command == setMaterial)
        my_command->setBoxMaterial(newValue);
}

DetGeometryMessenger::DetGeometryMessenger(DetGeometry* geom): my_command(geom){
    auto dir = new G4UIdirectory("/my_command/");

    setSizeX = new G4UIcmdWithADouble("/my_command/setSizeX",this);
    setSizeX->SetGuidance("Select size X ");
    setSizeX->SetParameterName("size", false);

    setSizeY = new G4UIcmdWithAnInteger("/my_command/setSizeY",this);
    setSizeY->SetGuidance("Select size Y");
    setSizeY->SetParameterName("size", false);

    setMaterial = new G4UIcmdWithAString("/my_command/setMaterial",this);
    setMaterial->SetGuidance("Select material");
    setMaterial->SetParameterName("name", false);

    cmd = new G4UIcommand("/my_command/exit",this);

}

DetGeometryMessenger::~DetGeometryMessenger() {

}