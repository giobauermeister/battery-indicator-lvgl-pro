/**
 * @file battery_indicator_v2_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "battery_indicator_v2_gen.h"
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

static lv_style_t * battery_indicator_v2_indicator_red_ref; /* set in create(), read by a binding callback */
static lv_style_t * battery_indicator_v2_indicator_yellow_ref; /* set in create(), read by a binding callback */
static void battery_indicator_v2_lv_slider_0_style_enabled_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v2_lv_slider_0_style_enabled_cb_2(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v2_lv_image_0_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * battery_indicator_v2_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t container;
    static lv_style_t style_border;
    static lv_style_t indicator;
    static lv_style_t indicator_red;
    static lv_style_t indicator_yellow;
    static lv_style_t tip;
    static lv_style_t hidden;
    static lv_style_t slider_indicator;
    static lv_style_t style_battery_indicator_container_mask;
    static lv_style_t style_no_mask;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&container);
        lv_style_init(&style_border);
        lv_style_init(&indicator);
        lv_style_init(&indicator_red);
        lv_style_init(&indicator_yellow);
        lv_style_init(&tip);
        lv_style_init(&hidden);
        lv_style_init(&slider_indicator);
        lv_style_init(&style_battery_indicator_container_mask);
        lv_style_init(&style_no_mask);

        lv_style_set_border_width(&container, 0);
        lv_style_set_bg_opa(&container, 0);
        lv_style_set_pad_all(&container, 0);
        lv_style_set_border_color(&style_border, lv_color_hex(0xadadad));
        lv_style_set_border_opa(&style_border, 255);
        lv_style_set_border_width(&style_border, 3);
        lv_style_set_radius(&style_border, 14);
        lv_style_set_bg_opa(&style_border, 0);
        lv_style_set_pad_all(&style_border, 0);
        lv_style_set_margin_right(&style_border, 10);
        lv_style_set_pad_left(&style_border, 3);
        lv_style_set_radius(&indicator, 8);
        lv_style_set_bg_opa(&indicator, 0);
        lv_style_set_bg_color(&indicator_red, lv_color_hex(0xFD3B2F));
        lv_style_set_bg_color(&indicator_yellow, lv_color_hex(0xFECC0B));
        lv_style_set_bg_color(&tip, lv_color_hex(0xadadad));
        lv_style_set_radius(&tip, 100);
        lv_style_set_border_width(&tip, 0);
        lv_style_set_opa(&hidden, 0);
        lv_style_set_bg_color(&slider_indicator, lv_color_hex(0x37c557));
        lv_style_set_radius(&slider_indicator, 8);
        lv_style_set_width(&style_battery_indicator_container_mask, 71);
        lv_style_set_height(&style_battery_indicator_container_mask, 38);
        lv_style_set_bitmap_mask_src(&style_battery_indicator_container_mask, img_battery_mask_v2);
        lv_style_set_border_width(&style_battery_indicator_container_mask, 0);
        lv_style_set_bg_opa(&style_battery_indicator_container_mask, 0);
        lv_style_set_pad_all(&style_battery_indicator_container_mask, 0);
        lv_style_set_width(&style_no_mask, 71);
        lv_style_set_height(&style_no_mask, 38);
        lv_style_set_border_width(&style_no_mask, 0);
        lv_style_set_bg_opa(&style_no_mask, 0);
        lv_style_set_pad_all(&style_no_mask, 0);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if BATTERY_INDICATOR_CHECK_COMPILE_TARGET(BATTERY_INDICATOR_TARGET_ALL)
    if (battery_indicator_check_target(BATTERY_INDICATOR_TARGET_ALL)) {
        lv_obj_t * battery = lv_obj_create(parent);
        lv_obj_set_name_static(battery, "battery_indicator_v2_#");
        lv_obj_set_name(battery, "battery");
        lv_obj_set_width(battery, 78);
        lv_obj_set_height(battery, 38);
        lv_obj_set_scrollable(battery, false);

        lv_obj_add_style(battery, &container, 0);
        lv_obj_t * battery_mask = lv_obj_create(battery);
        lv_obj_set_name(battery_mask, "battery_mask");
        lv_obj_set_scrollable(battery_mask, false);
        lv_obj_set_align(battery_mask, LV_ALIGN_LEFT_MID);
        lv_obj_set_style_pad_all(battery_mask, 0, 0);
        lv_obj_bind_style(battery_mask, &style_no_mask, LV_PART_MAIN, battery_charging, 0);
        lv_obj_bind_style(battery_mask, &style_battery_indicator_container_mask, LV_PART_MAIN, battery_charging, 1);
        lv_obj_t * battery_border = lv_obj_create(battery_mask);
        lv_obj_set_name(battery_border, "battery_border");
        lv_obj_set_width(battery_border, 71);
        lv_obj_set_height(battery_border, 38);
        lv_obj_set_align(battery_border, LV_ALIGN_LEFT_MID);
        lv_obj_set_scrollable(battery_border, false);
        lv_obj_add_style(battery_border, &style_border, 0);
        lv_obj_t * lv_slider_0 = lv_slider_create(battery_border);
        lv_slider_bind_value(lv_slider_0, battery_value);
        lv_slider_set_min_value(lv_slider_0, 0);
        lv_slider_set_max_value(lv_slider_0, 100);
        lv_obj_set_align(lv_slider_0, LV_ALIGN_LEFT_MID);
        lv_obj_set_width(lv_slider_0, 59);
        lv_obj_set_height(lv_slider_0, 26);
        lv_obj_add_style(lv_slider_0, &indicator, 0);
        lv_obj_add_style(lv_slider_0, &slider_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(lv_slider_0, &hidden, LV_PART_KNOB);
        lv_obj_add_style(lv_slider_0, &indicator_red, LV_PART_INDICATOR);
        battery_indicator_v2_indicator_red_ref = &indicator_red;
        lv_subject_add_observer_obj(battery_value, battery_indicator_v2_lv_slider_0_style_enabled_cb, lv_slider_0, NULL);
        lv_obj_add_style(lv_slider_0, &indicator_yellow, LV_PART_INDICATOR);
        battery_indicator_v2_indicator_yellow_ref = &indicator_yellow;
        lv_subject_add_observer_obj(low_power_mode, battery_indicator_v2_lv_slider_0_style_enabled_cb_2, lv_slider_0, NULL);

        lv_obj_t * battery_tip = lv_obj_create(battery);
        lv_obj_set_name(battery_tip, "battery_tip");
        lv_obj_set_width(battery_tip, 4);
        lv_obj_set_height(battery_tip, 12);
        lv_obj_set_style_radius(battery_tip, 0, 0);
        lv_obj_set_style_border_width(battery_tip, 0, 0);
        lv_obj_set_scrollable(battery_tip, false);
        lv_obj_set_align(battery_tip, LV_ALIGN_RIGHT_MID);
        lv_obj_set_style_pad_all(battery_tip, 0, 0);
        lv_obj_set_style_bg_opa(battery_tip, 0, 0);
        lv_obj_t * lv_obj_0 = lv_obj_create(battery_tip);
        lv_obj_set_width(lv_obj_0, 12);
        lv_obj_set_height(lv_obj_0, 12);
        lv_obj_set_align(lv_obj_0, LV_ALIGN_RIGHT_MID);
        lv_obj_add_style(lv_obj_0, &tip, 0);

        lv_obj_t * lv_image_0 = lv_image_create(battery);
        lv_image_set_src(lv_image_0, img_thunder_v2);
        lv_obj_set_align(lv_image_0, LV_ALIGN_LEFT_MID);
        lv_obj_set_style_pad_left(lv_image_0, 48, 0);
        lv_subject_add_observer_obj(battery_charging, battery_indicator_v2_lv_image_0_hidden_binding_cb, lv_image_0, NULL);

        the_root = battery;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void battery_indicator_v2_lv_slider_0_style_enabled_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_enabled(obj, battery_indicator_v2_indicator_red_ref, LV_PART_INDICATOR, lv_subject_get_int(battery_value) <= 20);
}

static void battery_indicator_v2_lv_slider_0_style_enabled_cb_2(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_enabled(obj, battery_indicator_v2_indicator_yellow_ref, LV_PART_INDICATOR, lv_subject_get_int(low_power_mode) == 1);
}

static void battery_indicator_v2_lv_image_0_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_hidden(obj, lv_subject_get_int(battery_charging) == 0);
}

