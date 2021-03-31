// -----------------------------------------------------------------------------
//  G4Basic | PrimaryGeneration.cpp
//
//
// -----------------------------------------------------------------------------

#include "PrimaryGeneration.h"

#include <G4Electron.hh>
#include <G4ParticleDefinition.hh>
#include <G4SystemOfUnits.hh>
#include <G4PrimaryParticle.hh>
#include <G4PrimaryVertex.hh>
#include <G4IonTable.hh>
#include <G4Event.hh>
#include <G4RandomDirection.hh>


PrimaryGeneration::PrimaryGeneration():
  G4VUserPrimaryGeneratorAction(),
  Z(36), A(83), E(41.5 * keV),
  px(0), py(0), pz(0),
  K(0)
{
}


PrimaryGeneration::~PrimaryGeneration()
{
}


void PrimaryGeneration::GeneratePrimaries(G4Event* event)
{
  G4double x = (G4UniformRand() * 2 - 1) * m;
  G4double y = (G4UniformRand() * 2 - 1) * m;
  G4double z = (G4UniformRand() * 2 - 1) * m;

  G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z, A, E);

  G4PrimaryParticle* particle = new G4PrimaryParticle(ion);
  particle->SetMomentumDirection(G4ThreeVector(px, py, pz));
  particle->SetKineticEnergy(K);

  G4PrimaryVertex* vertex = new G4PrimaryVertex(G4ThreeVector(x, y, z), 0.);
  vertex->SetPrimary(particle);

  event->AddPrimaryVertex(vertex);
}
