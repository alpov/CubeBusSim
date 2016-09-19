/*
 * businterface.h
 *
 *  Created on: 19 Sep 2016
 *      Author: Stefan van der Linden
 */

#ifndef INCLUDE_BUSINTERFACE_H_
#define INCLUDE_BUSINTERFACE_H_

#include <stdint.h>
#include "simpackets.h"

class BusInterface {
public:

    /* Interrupt handlers */
    void (*HeaderHandler)(HeaderPacket *);
    void (*DataHandler)(DataPacket *);

    /* The address of this node */
    uint_fast8_t ownAddress;

    /* General fields and methods */
    virtual uint_fast8_t init( bool asMaster, uint_fast8_t ownAddress );
    virtual uint_fast8_t sendData( uint_fast8_t * );

    /* Bus MASTER methods */
    virtual uint_fast8_t sendHeader( HeaderPacket * );

    /* Bus Slave methods */
    virtual void setHeaderHandler(void (*)(HeaderPacket *));
    virtual void setDataHandler(void (*)(DataPacket *));
};


#endif /* INCLUDE_BUSINTERFACE_H_ */
