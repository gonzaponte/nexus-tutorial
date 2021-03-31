// -----------------------------------------------------------------------------
//  G4Basic | EventAction.cpp
//
//  User run action class.
// -----------------------------------------------------------------------------

#include "EventAction.h"

#include <G4Event.hh>
#include <G4Run.hh>


void EventAction::BeginOfEventAction(const G4Event* event)
{
  G4cout << "============================================"
         << "Starting Event " << event->GetEventID() << " "
         << "with " << event->GetNumberOfPrimaryVertex() << " vertices"
         << G4endl
         << "============================================"
         << G4endl
         << G4endl;
}

void EventAction::EndOfEventAction(const G4Event* event)
{
  G4cout << G4endl
         << "============================================"
         << "End of Event " << event->GetEventID()
         << G4endl
         << "============================================"
         << G4endl
         << G4endl;
}
