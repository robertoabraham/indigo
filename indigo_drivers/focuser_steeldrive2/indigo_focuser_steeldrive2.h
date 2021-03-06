// Copyright (c) 2019 CloudMakers, s. r. o.
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

/** INDIGO Baader Planetarium SteelDriverII focuser driver
 \file indigo_focuser_steeldrive2.h
 */

#ifndef focuser_steeldrive2_h
#define focuser_steeldrive2_h

#include <indigo/indigo_driver.h>
#include <indigo/indigo_focuser_driver.h>
#include <indigo/indigo_aux_driver.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Register SteelDriveII focuser driver
 */

extern indigo_result indigo_focuser_steeldrive2(indigo_driver_action action, indigo_driver_info *info);

#ifdef __cplusplus
}
#endif

#endif /* focuser_steeldrive2_h */

