#ifndef COMMON_EMU_LIMITS_H
#define COMMON_EMU_LIMITS_H

#include "types.h"

#include <stdlib.h>

namespace EntityLimits {
namespace NPC {
const int16 IINVALID = -1;
const int16 INULL = 0;

namespace invtype {
const int16 TRADE_SIZE = 4;
}  // namespace invtype

}  // namespace NPC

namespace NPCMerchant {
const int16 IINVALID = -1;
const int16 INULL = 0;

namespace invtype {
const int16 TRADE_SIZE = 4;

}  // namespace invtype

}  // namespace NPCMerchant

namespace ClientPet {
const int16 IINVALID = -1;
const int16 INULL = 0;

namespace invtype {
const int16 TRADE_SIZE = 4;

}  // namespace invtype

}  // namespace ClientPet

namespace NPCPet {
const int16 IINVALID = -1;
const int16 INULL = 0;

namespace invtype {
const int16 TRADE_SIZE = 4;

}  // namespace invtype

}  // namespace NPCPet

};  // namespace EntityLimits

#endif /*COMMON_EMU_LIMITS_H*/