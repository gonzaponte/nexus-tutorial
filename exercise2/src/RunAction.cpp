// -----------------------------------------------------------------------------
//  G4Basic | RunAction.cpp
//
//  User run action class.
// -----------------------------------------------------------------------------

#include "RunAction.h"

#include <G4Run.hh>


void RunAction::BeginOfRunAction(const G4Run* run)
{
  G4cout << "------------------------------------------------------------" << G4endl
         << "Run ID " << run->GetRunID()                      << " "
         << "#event " << run->GetNumberOfEventToBeProcessed() << " "
         << G4endl;
}

void RunAction::EndOfRunAction(const G4Run*)
{
  G4cout << "End of run."
         << "------------------------------------------------------------"
         << G4endl;
}
