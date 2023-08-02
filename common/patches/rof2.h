#ifndef ROF2_H_
#define ROF2_H_

#include "../struct_strategy.h"

class EQStreamIdentifier;

namespace RoF2 {

// these are the only public member of this namespace.
extern void Register(EQStreamIdentifier &into);
extern void Reload();

// you should not directly access anything below..
// I just dont feel like making a seperate header for it.

class Strategy : public StructStrategy {
   public:
	Strategy();

   protected:
	virtual std::string Describe() const;
	virtual const EQ::versions::ClientVersion ClientVersion() const;
// magic macro to declare our opcodes
#include "ss_declare.h"
#include "rof2_ops.h"
};

};  // namespace RoF2

#endif /*TEMPLATE_H_*/
