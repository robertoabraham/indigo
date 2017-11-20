// Copyright (c) 2017 CloudMakers, s. r. o.
// All rights reserved.
//
// You can use this software under the terms of 'INDIGO Astronomy
// open-source license' (see LICENSE.md).
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHORS 'AS IS' AND ANY EXPRESS
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// version history
// 2.0 by Peter Polakovic <peter.polakovic@cloudmakers.eu>

/** INDIGO Dome Driver base
 \file indigo_dome_driver.h
 */

#ifndef indigo_dome_h
#define indigo_dome_h

#include "indigo_bus.h"
#include "indigo_driver.h"

#ifdef __cplusplus
extern "C" {
#endif
	
/** Main dome group name string.
*/
#define DOME_MAIN_GROUP									"Dome"
	
/** Device context pointer.
 */
#define DOME_CONTEXT                					((indigo_dome_context *)device->device_context)
	
/** DOME_SPEED property pointer, property is mandatory, property change request should be fully handled by indigo_dome_change_property
 */
#define DOME_SPEED_PROPERTY								(DOME_CONTEXT->dome_speed_property)
	
/** DOME_SPEED.SPEED property item pointer.
 */
#define DOME_SPEED_ITEM									(DOME_SPEED_PROPERTY->items+0)

/** DOME_DIRECTION property pointer, property is mandatory, property change request should be fully handled by indigo_dome_change_property.
 */
#define DOME_DIRECTION_PROPERTY							(DOME_CONTEXT->dome_direction_property)
	
/** DOME_DIRECTION.MOVE_CLOCKWISE property item pointer.
 */
#define DOME_DIRECTION_MOVE_CLOCKWISE_ITEM				(DOME_DIRECTION_PROPERTY->items+0)
	
/** DOME_DIRECTION.MOVE_COUNTERCLOCKWISE property item pointer.
 */
#define DOME_DIRECTION_MOVE_COUNTERCLOCKWISE_ITEM		(DOME_DIRECTION_PROPERTY->items+1)
	
/** DOME_STEPS property pointer, property is mandatory, property change request should be fully handled by dome driver
 */
#define DOME_STEPS_PROPERTY								(DOME_CONTEXT->dome_steps_property)
	
/** DOME_STEPS.STEPS property item pointer.
 */
#define DOME_STEPS_ITEM									(DOME_STEPS_PROPERTY->items+0)
	
/** DOME_HORIZONTAL_COORDINATES property pointer, property is mandatory, property change request should be fully handled by dome driver
 */
#define DOME_HORIZONTAL_COORDINATES_PROPERTY			(DOME_CONTEXT->dome_position_property)
	
/** DOME_HORIZONTAL_COORDINATES.AZ property item pointer.
 */
#define DOME_HORIZONTAL_COORDINATES_AZ_ITEM								(DOME_HORIZONTAL_COORDINATES_PROPERTY->items+0)
	
/** DOME_HORIZONTAL_COORDINATES.ALT property item pointer.
 */
#define DOME_HORIZONTAL_COORDINATES_ALT_ITEM								(DOME_HORIZONTAL_COORDINATES_PROPERTY->items+1)
	
/** DOME_ABORT_MOTION property pointer, property is mandatory, property change request should be fully handled by dome driver
 */
#define DOME_ABORT_MOTION_PROPERTY						(DOME_CONTEXT->dome_abort_motion_property)
	
/** DOME_ABORT_MOTION.ABORT_MOTION property item pointer.
 */
#define DOME_ABORT_MOTION_ITEM							(DOME_ABORT_MOTION_PROPERTY->items+0)
	
/** DOME_SHUTTER property pointer, property is mandatory, property change request should be fully handled by dome driver
 */
#define DOME_SHUTTER_PROPERTY								(DOME_CONTEXT->dome_shutter_property)
	
/** DOME_SHUTTER.OPENED property item pointer.
 */
#define DOME_SHUTTER_OPENED_ITEM							(DOME_SHUTTER_PROPERTY->items+0)
	
/** DOME_SHUTTER.CLOSED property item pointer.
 */
#define DOME_SHUTTER_CLOSED_ITEM							(DOME_SHUTTER_PROPERTY->items+1)
	
//----------------------------------------------
/** DOME_PARK property pointer, property is mandatory, property change request should be fully handled by device driver.
 */
#define DOME_PARK_PROPERTY														(DOME_CONTEXT->dome_park_property)
	
/** DOME_PARK.PARKED property item pointer.
 */
#define DOME_PARK_PARKED_ITEM												(DOME_PARK_PROPERTY->items+0)
	
/** DOME_PARK.UNPARKED property item pointer.
 */
#define DOME_PARK_UNPARKED_ITEM											(DOME_PARK_PROPERTY->items+1)

//----------------------------------------------
/** DOME_MEASUREMENT property pointer, property is mandatory
 */
#define DOME_DIMENSION_PROPERTY										(DOME_CONTEXT->dome_measurement_property)
	
/** DOME_MEASUREMENT.RADIUS property item pointer.
 */
#define DOME_RADIUS_ITEM														(DOME_DIMENSION_PROPERTY->items+0)

/** DOME_MEASUREMENT.SHUTTER_WIDTH property item pointer.
 */
#define DOME_SHUTTER_WIDTH_ITEM											(DOME_DIMENSION_PROPERTY->items+1)
	
/** DOME_MEASUREMENT.NORTH_DISPLACEMENT property item pointer.
 */
#define DOME_NORTH_DISPLACEMENT_ITEM								(DOME_DIMENSION_PROPERTY->items+2)
	
/** DOME_MEASUREMENT.EAST_DISPLACEMENT property item pointer.
 */
#define DOME_EAST_DISPLACEMENT_ITEM									(DOME_DIMENSION_PROPERTY->items+3)
	
/** DOME_MEASUREMENT.UP_DISPLACEMENT property item pointer.
 */
#define DOME_UP_DISPLACEMENT_ITEM										(DOME_DIMENSION_PROPERTY->items+4)
	
/** DOME_MEASUREMENT.OTA_OFFSET property item pointer.
 */
#define DOME_OTA_OFFSET_ITEM												(DOME_DIMENSION_PROPERTY->items+5)
	
/** Dome device context structure.
 */
typedef struct {
	indigo_device_context device_context;					///< device context base
	indigo_property *dome_speed_property;					///< DOME_SPEED property pointer
	indigo_property *dome_direction_property;			///< DOME_DIRECTION property pointer
	indigo_property *dome_steps_property;					///< DOME_STEPS property pointer
	indigo_property *dome_position_property;			///< DOME_POSITION property pointer
	indigo_property *dome_abort_motion_property;	///< DOME_ABORT_MOTION property pointer
	indigo_property *dome_shutter_property;				///< DOME_SHUTTER_PROPERTY pointer
	indigo_property *dome_park_property;					///< DOME_PARK property pointer
	indigo_property *dome_measurement_property;		///< DOME_PARK property pointer
} indigo_dome_context;

/** Attach callback function.
 */
extern indigo_result indigo_dome_attach(indigo_device *device, unsigned version);
/** Enumerate properties callback function.
 */
extern indigo_result indigo_dome_enumerate_properties(indigo_device *device, indigo_client *client, indigo_property *property);
/** Change property callback function.
 */
extern indigo_result indigo_dome_change_property(indigo_device *device, indigo_client *client, indigo_property *property);
/** Detach callback function.
 */
extern indigo_result indigo_dome_detach(indigo_device *device);
	
#ifdef __cplusplus
}
#endif

#endif /* indigo_dome_h */


