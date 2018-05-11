#include <G4UIcommand.hh>
#include <Command.hh>
#include <G4UIcmdWithAString.hh>

void Command::SetNewValue(G4UIcommand *command, G4String newValue) {
    if(command == cmd)
        exit(80);
    if(command == setSizeX)
        my_command_size->setBoxXsize(setSizeX->GetNewDoubleValue(newValue));
    if(command == setSizeY)
        my_command_size->setBoxYsize(setSizeY->GetNewIntValue(newValue));
    if(command == setMaterial)
        my_command_size->setBoxMaterial(newValue);
    if(command == setEnergy)
        my_command_energy->setEnergy(setEnergy->GetNewDoubleValue(newValue));
}

Command::Command(DetGeometry* geom): my_command_size(geom){
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
Command::Command(PrimaryGen* pGen): my_command_energy(pGen){
    auto dir = new G4UIdirectory("/my_command/");

    setEnergy = new G4UIcmdWithADouble("/my_command/setEnergy",this);
    setEnergy->SetGuidance("Select material");
    setEnergy->SetParameterName("name", false);
}
Command::~Command() {}
