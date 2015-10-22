/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2015, Alexey Kramarenko
    All rights reserved.
*/

#ifndef LPC_ETH_H
#define LPC_ETH_H

/*
    STM32 Ethernet driver.
*/

#include "../../userspace/process.h"
#include "../../userspace/eth.h"
#include "../../userspace/io.h"
#include <stdint.h>
#include "sys_config.h"

#pragma pack(push, 1)

typedef struct {
    uint32_t ctl;
    uint32_t size;
    void* buf1;
    void* buf2_ndes;
} ETH_DESCRIPTORS;

#pragma pack(pop)

typedef struct {
#if (ETH_DOUBLE_BUFFERING)
    IO* tx[2];
    IO* rx[2];
    ETH_DESCRIPTORS tx_des[2], rx_des[2];
#else
    ETH_DESCRIPTORS tx_des, rx_des;
    IO* tx;
    IO* rx;
#endif
    ETH_CONN_TYPE conn;
    HANDLE tcpip, timer;
    bool connected;
    MAC mac;
    uint8_t phy_addr;
#if (ETH_DOUBLE_BUFFERING)
    uint8_t cur_rx, cur_tx;
#endif
} ETH_DRV;

#endif // LPC_ETH_H