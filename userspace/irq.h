/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2014, Alexey Kramarenko
    All rights reserved.
*/

#ifndef IRQ_H
#define IRQ_H

#include "lib/types.h"
#include "sys.h"
#include "cc_macro.h"
#include "error.h"

/** \addtogroup irq irq
    All irq's before they can be used must be registered with handler. If IRQ already registered, it will be locked and
    cannot be registered again, until caller process unregister it.
    \{
 */

/**
    \brief register irq
    \param vector: IRQ vector to register
    \param handler: IRQ handler, that will be called on IRQ
    \param param: param for handler
    \retval none
*/
__STATIC_INLINE void irq_register(int vector, IRQ handler, void* param)
{
    sys_call(SVC_IRQ_REGISTER, (unsigned int)vector, (unsigned int)handler, (unsigned int)param);
}

/**
    \brief unregister irq
    \param vector: IRQ vector to register
    \retval none
*/
__STATIC_INLINE void irq_unregister(int vector)
{
    sys_call(SVC_IRQ_UNREGISTER, (unsigned int)vector, 0, 0);
}

/** \} */ // end of irq group

#endif // IRQ_H
