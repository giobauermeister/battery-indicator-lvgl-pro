/**
 * @file top_bar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "top_bar_gen.h"
#include "../../battery_indicator.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static void top_bar_battery_indicator_v3_0_value_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void top_bar_battery_indicator_v3_0_charging_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void top_bar_battery_indicator_v3_0_low_power_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void top_bar_battery_indicator_v3_0_show_percentage_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void top_bar_battery_indicator_v3_0_theme_binding_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * top_bar_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_main);

        lv_style_set_border_width(&style_main, 0);
        lv_style_set_bg_color(&style_main, lv_color_hex(0x505050));
        lv_style_set_radius(&style_main, 0);
        lv_style_set_pad_all(&style_main, 0);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if BATTERY_INDICATOR_CHECK_COMPILE_TARGET(BATTERY_INDICATOR_TARGET_ALL)
    if (battery_indicator_check_target(BATTERY_INDICATOR_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "top_bar_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_height(lv_obj_0, 60);
        lv_obj_set_scrollable(lv_obj_0, false);
        lv_obj_set_style_pad_left(lv_obj_0, 90, 0);
        lv_obj_set_style_pad_right(lv_obj_0, 90, 0);

        lv_obj_add_style(lv_obj_0, &style_main, 0);
        lv_obj_t * clock_0 = clock_create(lv_obj_0);
        lv_obj_set_align(clock_0, LV_ALIGN_LEFT_MID);

        lv_obj_t * battery_indicator_v3_0 = battery_indicator_v3_create(lv_obj_0, lv_subject_get_int(battery_value), lv_subject_get_int(battery_charging) != 0, lv_subject_get_int(low_power_mode) != 0, lv_subject_get_int(battery_show_percentage) != 0, lv_subject_get_int(battery_theme), 20);
        lv_obj_set_align(battery_indicator_v3_0, LV_ALIGN_RIGHT_MID);
        lv_subject_add_observer_obj(battery_value, top_bar_battery_indicator_v3_0_value_binding_cb, battery_indicator_v3_0, NULL);
        lv_subject_add_observer_obj(battery_charging, top_bar_battery_indicator_v3_0_charging_binding_cb, battery_indicator_v3_0, NULL);
        lv_subject_add_observer_obj(low_power_mode, top_bar_battery_indicator_v3_0_low_power_binding_cb, battery_indicator_v3_0, NULL);
        lv_subject_add_observer_obj(battery_show_percentage, top_bar_battery_indicator_v3_0_show_percentage_binding_cb, battery_indicator_v3_0, NULL);
        lv_subject_add_observer_obj(battery_theme, top_bar_battery_indicator_v3_0_theme_binding_cb, battery_indicator_v3_0, NULL);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void top_bar_battery_indicator_v3_0_value_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    battery_indicator_v3_set_value(obj, lv_subject_get_int(battery_value));
}

static void top_bar_battery_indicator_v3_0_charging_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    battery_indicator_v3_set_charging(obj, lv_subject_get_int(battery_charging) != 0);
}

static void top_bar_battery_indicator_v3_0_low_power_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    battery_indicator_v3_set_low_power(obj, lv_subject_get_int(low_power_mode) != 0);
}

static void top_bar_battery_indicator_v3_0_show_percentage_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    battery_indicator_v3_set_show_percentage(obj, lv_subject_get_int(battery_show_percentage) != 0);
}

static void top_bar_battery_indicator_v3_0_theme_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    battery_indicator_v3_set_theme(obj, lv_subject_get_int(battery_theme));
}

