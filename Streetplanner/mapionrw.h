///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef MAPIONRW_H
#define MAPIONRW_H

#include "mapio.h"

/// This class provides a simple hardcoded Map.
/**
 * @brief The MapIoNrw class provides a simple hardcoded map of North Rhine-Westphalia.
 *  The MapIoNrw class is a concrete implementation of the MapIo abstract class.
 *  It is responsible for providing a predefined, hardcoded map of cities and streets
 *  in the North Rhine-Westphalia (NRW) region. This class overrides the fillMap method
 *  to populate the provided map with specific cities and streets representative of NRW.
 */
class MapIoNrw : public MapIo
{
public:
    /**
     * @brief Default constructor.
     *  Constructs a MapIoNrw object. This constructor initializes any necessary
     *  resources or data required for the hardcoded map.
     */
    MapIoNrw();
    /**
     * @brief Virtual destructor.
     *  The virtual destructor ensures that any resources allocated by the MapIoNrw
     *  object are correctly released when the object is deleted.
     */
    virtual ~MapIoNrw();
    /**
     * @brief Fills the provided map with a hardcoded map of NRW.
         *  This method overrides the pure virtual fillMap method from the MapIo class.
         *  It adds a predefined set of cities and streets to the provided map, representing
         *  a specific region of North Rhine-Westphalia (NRW).
         *
         *  \param map The map to be filled with the hardcoded cities and streets of NRW.
         */
    virtual void fillMap(AbstractMap &map);
};

#endif // MAPIONRW_H
