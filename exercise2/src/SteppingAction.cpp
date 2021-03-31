// -----------------------------------------------------------------------------
//  G4Basic | SteppingAction.cpp
//
//  User stepping action class.
// -----------------------------------------------------------------------------

#include "SteppingAction.h"

#include <G4VProcess.hh>
#include <G4Step.hh>



void SteppingAction::UserSteppingAction(const G4Step* step)
{

  G4Track* track = step->GetTrack();

  G4String processname = "None";
  if (track->GetTrackID() != 1)
    processname = track->GetCreatorProcess()->GetProcessName();

  G4cout << " G4step info: "                  << "    "
         << track->GetCurrentStepNumber()     << " "
         << track->GetPosition()              << " "
         << track->GetKineticEnergy()         << " "
         << step ->GetDeltaEnergy()           << " "
         << step ->GetTotalEnergyDeposit()    << " "
         << step ->GetStepLength()            << " "
         << track->GetTrackLength()           << " "
         << track->GetNextVolume()->GetName() << " "
         << processname                       << " "
         << G4endl;
}
