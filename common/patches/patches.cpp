#include "patches.h"

#include "../global_define.h"
#include "rof2.h"

void RegisterAllPatches(EQStreamIdentifier &into) { Mac::Register(into); }

void ReloadAllPatches() { Mac::Reload(); }
