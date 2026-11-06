/**
 * @file battery_indicator_v3_gen.h
 */

#ifndef LVGL_PRO_BATTERY_INDICATOR_V3_GEN_H
#define LVGL_PRO_BATTERY_INDICATOR_V3_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * battery_indicator_v3_create(lv_obj_t * parent, int32_t value, bool charging, bool low_power, bool show_percentage, int32_t theme, int32_t low_threshold);
/**
 * Set the `value` property of a battery_indicator_v3, and notify everything bound to it.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @param value  the new value
 */
void battery_indicator_v3_set_value(lv_obj_t * obj, int32_t value);

/**
 * Get the current `value` property of a battery_indicator_v3.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @return          the current value, or 0 if `obj` is not in a battery_indicator_v3
 */
int32_t battery_indicator_v3_get_value(lv_obj_t * obj);

/**
 * Set the `charging` property of a battery_indicator_v3, and notify everything bound to it.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @param charging  the new value
 */
void battery_indicator_v3_set_charging(lv_obj_t * obj, int32_t charging);

/**
 * Get the current `charging` property of a battery_indicator_v3.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @return          the current value, or 0 if `obj` is not in a battery_indicator_v3
 */
int32_t battery_indicator_v3_get_charging(lv_obj_t * obj);

/**
 * Set the `low_power` property of a battery_indicator_v3, and notify everything bound to it.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @param low_power  the new value
 */
void battery_indicator_v3_set_low_power(lv_obj_t * obj, int32_t low_power);

/**
 * Get the current `low_power` property of a battery_indicator_v3.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @return          the current value, or 0 if `obj` is not in a battery_indicator_v3
 */
int32_t battery_indicator_v3_get_low_power(lv_obj_t * obj);

/**
 * Set the `show_percentage` property of a battery_indicator_v3, and notify everything bound to it.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @param show_percentage  the new value
 */
void battery_indicator_v3_set_show_percentage(lv_obj_t * obj, int32_t show_percentage);

/**
 * Get the current `show_percentage` property of a battery_indicator_v3.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @return          the current value, or 0 if `obj` is not in a battery_indicator_v3
 */
int32_t battery_indicator_v3_get_show_percentage(lv_obj_t * obj);

/**
 * Set the `theme` property of a battery_indicator_v3, and notify everything bound to it.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @param theme  the new value
 */
void battery_indicator_v3_set_theme(lv_obj_t * obj, int32_t theme);

/**
 * Get the current `theme` property of a battery_indicator_v3.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @return          the current value, or 0 if `obj` is not in a battery_indicator_v3
 */
int32_t battery_indicator_v3_get_theme(lv_obj_t * obj);

/**
 * Set the `low_threshold` property of a battery_indicator_v3, and notify everything bound to it.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @param low_threshold  the new value
 */
void battery_indicator_v3_set_low_threshold(lv_obj_t * obj, int32_t low_threshold);

/**
 * Get the current `low_threshold` property of a battery_indicator_v3.
 * @param obj       pointer to a battery_indicator_v3, or to any widget inside one
 * @return          the current value, or 0 if `obj` is not in a battery_indicator_v3
 */
int32_t battery_indicator_v3_get_low_threshold(lv_obj_t * obj);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_BATTERY_INDICATOR_V3_GEN_H*/