#include "STD_TYPES.hpp"

#include "GPIO_interface.hpp"

#include "IR_infrared_interface.hpp"
#include "IR_infrared_config.hpp"

IR_INFRARED::IR_INFRARED(PORT Copy_enumPortID, PIN Copy_enumPin)
: GPIO_CONFIG_t(Copy_enumPortID, Copy_enumPin, PIN_MODE::INPUT_FLOATING)
{
	SET_voidPin_Mode();
}
EXISTENCE IR_INFRARED::Check_voidExistance(void)
{
	return (static_cast<EXISTENCE>(GPIO_enumGETPinValue()));
}
