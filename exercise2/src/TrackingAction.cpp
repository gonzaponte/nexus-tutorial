// -----------------------------------------------------------------------------
//  G4Basic | TrackingAction.cpp
//
//  User tracking action class.
// -----------------------------------------------------------------------------

#include "TrackingAction.h"

#include <G4Track.hh>


void TrackingAction::PreUserTrackingAction(const G4Track* track)
{
  G4cout << "**************************************************************"
         << G4endl
         << "G4track info: "
         << "Particle = "  << track->GetParticleDefinition()->GetParticleName() << " "
         << "Track ID = "  << track->GetTrackID()                               << " "
         << "Parent ID = " << track->GetParentID()                              << " "
         << G4endl
         << "**************************************************************"
         << G4endl
         << "              "
         << "Step#          Position           KinEnergy deltaE depEnergy StepLength TrackLength NextVolume CreatorProcess"
         << G4endl;
}

void TrackingAction::PostUserTrackingAction(const G4Track*)
{
  G4cout << G4endl;
}
