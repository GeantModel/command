

#include <G4Colour.hh>
#include <G4GeometryManager.hh>
#include <G4RunManager.hh>
#include "DetGeometry.hh"
#include "G4VisAttributes.hh"

DetGeometry::DetGeometry() {
    detGeometryMessenger = new DetGeometryMessenger(this);
    world_sizeXYZ   = 50 * m;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_AIR");

    boxXsize = 10*cm;
    boxYsize = 15*cm;
    box_material = nist->FindOrBuildMaterial("G4_BGO");
    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

DetGeometry::~DetGeometry() {
    delete detGeometryMessenger;
}

G4VPhysicalVolume* DetGeometry::Construct(){
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();

    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    logicWorld->SetVisAttributes(G4VisAttributes::Invisible);
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);

    G4Box *box = new G4Box("box", boxXsize, boxYsize, 10*cm);
    auto box_log = new G4LogicalVolume(box, box_material, "box_log");
    box_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(0, G4ThreeVector(), box_log, "box_PV", logicWorld, false, 0);

    return physWorld;
}

void DetGeometry::setBoxXsize(G4double newValueX) {
    DetGeometry::boxXsize = newValueX;
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}
void DetGeometry::setBoxYsize(G4int newValueY) {
     DetGeometry::boxYsize = newValueY;
     G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
     G4RunManager::GetRunManager()->ReinitializeGeometry();
}
void DetGeometry::setBoxMaterial(G4String newBoxMaterial) {
    box_material = nist->FindOrBuildMaterial(newBoxMaterial);
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}



