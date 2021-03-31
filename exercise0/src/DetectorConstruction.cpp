// -----------------------------------------------------------------------------
//  G4Basic | DetectorConstruction.cpp
//
//
// -----------------------------------------------------------------------------

#include "DetectorConstruction.h"

#include <G4Box.hh>
#include <G4Tubs.hh>
#include <G4Sphere.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4SystemOfUnits.hh>
#include <G4PhysicalConstants.hh>
#include <G4NistManager.hh>
#include <G4VisAttributes.hh>
#include <G4RotationMatrix.hh>


DetectorConstruction::DetectorConstruction(): G4VUserDetectorConstruction()
{
}


DetectorConstruction::~DetectorConstruction()
{
}


G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // WORLD /////////////////////////////////////////////////

  G4String world_name  = "WORLD";
  G4double world_size  = 1. *  m;
  G4double world_depth = 1. * mm;

  G4Box* world_solid_vol =
    new G4Box(world_name, world_size/2, world_size/2, world_depth/2);

  G4LogicalVolume* world_logic_vol =
    new G4LogicalVolume(world_solid_vol,
                        G4NistManager::Instance()->FindOrBuildMaterial("G4_Galactic"),
                        world_name);

  G4VPhysicalVolume* world_phys_vol =
    new G4PVPlacement(nullptr, G4ThreeVector(0.,0.,0.),
                      world_logic_vol, world_name, nullptr,
                      false, 0, true);

  world_logic_vol->SetVisAttributes(G4VisAttributes::Invisible);

  // EMOJI FACE

  G4String face_name   = "FACE";
  G4double face_diam   = world_size;

  G4Tubs* face_solid_vol =
    new G4Tubs(face_name, 0., face_diam/2., world_depth/2, 0., 360.*deg);

  G4LogicalVolume* face_logic_vol =
    new G4LogicalVolume(face_solid_vol,
                        G4NistManager::Instance()->FindOrBuildMaterial("G4_WATER"),
                        face_name);

  face_logic_vol->SetVisAttributes(new G4VisAttributes(G4Colour(255, 255, 0)));

  new G4PVPlacement(nullptr, G4ThreeVector(0.,0.,0.),
                    face_logic_vol, face_name, world_logic_vol,
                    false, 0, true);

  // EMOJI MOUTH

  G4String mouth_name   = "MOUTH";
  G4double mouth_diam   = 2 / 3. * face_diam;

  G4Tubs* mouth_solid_vol =
    new G4Tubs(mouth_name, 0., mouth_diam/2., world_depth/2., 180. * deg, 180. * deg);

  G4LogicalVolume* mouth_logic_vol =
    new G4LogicalVolume(mouth_solid_vol,
                        G4NistManager::Instance()->FindOrBuildMaterial("G4_LEAD"),
                        mouth_name);

  mouth_logic_vol->SetVisAttributes(new G4VisAttributes(G4Colour(0, 0, 0)));

  new G4PVPlacement(nullptr, G4ThreeVector(0.,0.,0.),
                    mouth_logic_vol, mouth_name, face_logic_vol,
                    false, 0, true);

  // EMOJI EYES

  G4String eye_name   = "EYE";
  G4double eye_diam   = 1 / 7. * face_diam;

  G4Tubs* eye_solid_vol =
    new G4Tubs(eye_name, 0., eye_diam/2., world_depth/2., 0. * deg, 360. * deg);

  G4LogicalVolume* eye_logic_vol =
    new G4LogicalVolume(eye_solid_vol,
                        G4NistManager::Instance()->FindOrBuildMaterial("G4_COPPER"),
                        eye_name);

  eye_logic_vol->SetVisAttributes(new G4VisAttributes(G4Colour(0, 0, 0)));

  new G4PVPlacement(nullptr, G4ThreeVector(face_diam/2./2. * sin(55.*deg), face_diam/2./2. * cos(55.*deg), 0.),
                    eye_logic_vol, eye_name + "1", face_logic_vol,
                    false, 0, true);

  new G4PVPlacement(nullptr, G4ThreeVector(-face_diam/2./2. * sin(55*deg), face_diam/2./2. * cos(55.*deg), 0.),
                    eye_logic_vol, eye_name + "2", face_logic_vol,
                    false, 1, true);


  // EMOJI TONGUE

  G4String tongue_name   = "TONGUE";
  G4double tongue_diam   = 3 / 8. * face_diam;

  G4Tubs* tongue_solid_vol =
    new G4Tubs(tongue_name, 0., tongue_diam/2., world_depth/2, 180. * deg, 180. * deg);

  G4LogicalVolume* tongue_logic_vol =
    new G4LogicalVolume(tongue_solid_vol,
                        EnrichedXenon(),
                        tongue_name);

  tongue_logic_vol->SetVisAttributes(new G4VisAttributes(G4Colour(255, 0, 0)));

  new G4PVPlacement(nullptr, G4ThreeVector(0, - mouth_diam/2./2. + eye_diam/2., 0.),
                    tongue_logic_vol, tongue_name, mouth_logic_vol,
                    false, 0, true);

  return world_phys_vol;
}


G4Material* DetectorConstruction::EnrichedXenon() const
{
  G4String name = "ENRICHED_XENON";
  G4double pressure    = 15.0 * bar;
  G4double temperature = STP_Temperature; // 273.15 K
  G4double density     = 97.49 * kg/m3;

  G4Material* material =
    new G4Material(name, density, 1, kStateGas, temperature, pressure);

  G4Element* Xe = new G4Element("ENRICHED_XENON", "Xe", 2);

  G4Isotope* Xe134 = new G4Isotope("Xe134", 54, 134, 133.905395*g/mole);
  G4Isotope* Xe136 = new G4Isotope("Xe136", 54, 136, 135.907219*g/mole);
  Xe->AddIsotope(Xe134,  9.*perCent);
  Xe->AddIsotope(Xe136, 91.*perCent);

  material->AddElement(Xe,1);

  return material;
}
