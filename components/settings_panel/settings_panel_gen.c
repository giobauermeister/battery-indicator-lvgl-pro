/**
 * @file settings_panel_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "settings_panel_gen.h"
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

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * settings_panel_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_settings_container;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_main);
        lv_style_init(&style_settings_container);

        lv_style_set_radius(&style_main, 25);
        lv_style_set_border_width(&style_main, 0);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xFDFDFD));
        lv_style_set_pad_all(&style_main, 15);
        lv_style_set_border_width(&style_settings_container, 0);
        lv_style_set_bg_opa(&style_settings_container, 0);
        lv_style_set_layout(&style_settings_container, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_settings_container, LV_FLEX_FLOW_COLUMN);
        lv_style_set_pad_row(&style_settings_container, 11);
        lv_style_set_flex_cross_place(&style_settings_container, LV_FLEX_ALIGN_CENTER);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if BATTERY_INDICATOR_CHECK_COMPILE_TARGET(BATTERY_INDICATOR_TARGET_ALL)
    if (battery_indicator_check_target(BATTERY_INDICATOR_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "settings_panel_#");
        lv_obj_set_width(lv_obj_0, 340);
        lv_obj_set_height(lv_obj_0, 335);
        lv_obj_set_scrollable(lv_obj_0, false);

        lv_obj_add_style(lv_obj_0, &style_main, 0);
        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, LV_SIZE_CONTENT);
        lv_obj_set_height(lv_obj_1, LV_SIZE_CONTENT);
        lv_obj_set_align(lv_obj_1, LV_ALIGN_CENTER);
        lv_obj_set_scrollable(lv_obj_1, false);
        lv_obj_add_style(lv_obj_1, &style_settings_container, 0);
        settings_item_create(lv_obj_1, "Charging", battery_charging);

        settings_menu_line_create(lv_obj_1);

        settings_item_create(lv_obj_1, "Battery Percentage", battery_show_percentage);

        settings_menu_line_create(lv_obj_1);

        settings_item_create(lv_obj_1, "Low Power Mode", low_power_mode);

        settings_menu_line_create(lv_obj_1);

        settings_item_create(lv_obj_1, "Battery Theme", battery_theme);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

