#include "patches.h"

#include "../global_define.h"
#include "rof2.h"

void RegisterAllPatches(EQStreamIdentifier &into) { RoF2::Register(into); }

void ReloadAllPatches() { RoF2::Reload(); }
