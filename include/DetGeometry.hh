
#ifndef CPROJECT_DETGEOMETRY_HH
#define CPROJECT_DETGEOMETRY_HH

#include "G4SystemOfUnits.hh"

#include <G4PhysicalConstants.hh>
#include "G4SolidStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"

#include "G4NistManager.hh"

#include "G4PVPlacement.hh"

#include "G4Box.hh"

#include "G4VUserDetectorConstruction.hh"
#include "DetGeometryMessenger.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class DetGeometryMessenger;


class DetGeometry  : public G4VUserDetectorConstruction
{
private:
    G4NistManager*              nist;
    G4Material*                 world_mat;
    G4double                    world_sizeXYZ;
    G4Box*                      solidWorld;
    G4LogicalVolume*            logicWorld;
    virtual G4VPhysicalVolume*  Construct();
    G4VPhysicalVolume*          physWorld;
public:
    DetGeometry();
    virtual ~DetGeometry();

private:
    G4double boxXsize;
    G4int boxYsize;
    G4Material * box_material;
    DetGeometryMessenger* detGeometryMessenger;
public:
    void setBoxXsize(G4double newValueX);
    void setBoxYsize(G4int newValueY);
    void setBoxMaterial(G4String newBoxMaterial);
};

#endif //CPROJECT_DETGEOMETRY_HH
