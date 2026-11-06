/**
 * @file wd_battery_private_gen.h
 *
 */

#ifndef LVGL_PRO_WD_BATTERY_PRIVATE_GEN_H
#define LVGL_PRO_WD_BATTERY_PRIVATE_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl_private.h"
#else
    #include "lvgl_private/lvgl_private.h"
#endif
#include "wd_battery.h"

/*********************
 *      DEFINES
 *********************/

#ifndef WD_BATTERY_USER_DATA
#define WD_BATTERY_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    int32_t value;
    bool low_power;
    bool charging;
    lv_subject_t * bind_value;
    lv_subject_t * bind_low_power;
    lv_subject_t * bind_charging;
    lv_obj_t * battery_tip_container;
    lv_obj_t * battery_tip;
    lv_obj_t * slider_indicator;
    lv_obj_t * text_indicator_container;
    lv_obj_t * pct_text;
    lv_obj_t * charging_icon;
    WD_BATTERY_USER_DATA
} wd_battery_t;

extern const lv_obj_class_t wd_battery_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if defined(LV_USE_XML) && LV_USE_XML
    void wd_battery_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_WD_BATTERY_PRIVATE_GEN_H*/