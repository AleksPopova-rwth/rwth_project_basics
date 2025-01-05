///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef MAPIO_H
#define MAPIO_H

#include "abstractmap.h"

/// This class adds Cities and Streeds to a Map.
///
/**
 *  @class MapIo provides an interface for filling a given map with
 *  cities and streets. It is an abstract base class that defines a virtual
 *  destructor and a pure virtual method, fillMap, which must be implemented
 *  by derived classes. This allows for different implementations of the
 *  map population logic to be used interchangeably.
*
*/
class MapIo
{
public:
    
    /// virtual Destructor
    /**
     *  @brief The virtual destructor ensures that derived class destructors
     *  are called correctly when a MapIo object is deleted through a
     *  pointer to the base class.
     */
    virtual ~MapIo();
    
    /// this method adds Cities and Streets to the provided Map.
    ///
    /**
    *  @brief This method adds cities and streets to the provided map.
    *
    * @param map The map to be filled with cities and streets.
    */
    virtual void fillMap(AbstractMap &map) = 0;
};

#endif // MAPIO_H
