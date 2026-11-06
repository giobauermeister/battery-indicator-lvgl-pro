/**
 * @file settings_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "settings_item_gen.h"
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

lv_obj_t * settings_item_create(lv_obj_t * parent, const char * item_label, lv_subject_t * subject)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_label_container;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_main);
        lv_style_init(&style_label_container);

        lv_style_set_border_width(&style_main, 0);
        lv_style_set_bg_opa(&style_main, 0);
        lv_style_set_layout(&style_main, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_main, LV_FLEX_FLOW_ROW);
        lv_style_set_pad_column(&style_main, 43);
        lv_style_set_flex_cross_place(&style_main, LV_FLEX_ALIGN_CENTER);
        lv_style_set_text_font(&style_main, font_inter_semibold_25);
        lv_style_set_pad_all(&style_main, 0);
        lv_style_set_border_width(&style_label_container, 0);
        lv_style_set_bg_opa(&style_label_container, 0);
        lv_style_set_pad_all(&style_label_container, 0);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if BATTERY_INDICATOR_CHECK_COMPILE_TARGET(BATTERY_INDICATOR_TARGET_ALL)
    if (battery_indicator_check_target(BATTERY_INDICATOR_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "settings_item_#");
        lv_obj_set_width(lv_obj_0, 300);
        lv_obj_set_height(lv_obj_0, 60);

        lv_obj_add_style(lv_obj_0, &style_main, 0);
        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, 140);
        lv_obj_set_height(lv_obj_1, 60);
        lv_obj_set_scrollable(lv_obj_1, false);
        lv_obj_add_style(lv_obj_1, &style_label_container, 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_1);
        lv_label_set_text(lv_label_0, item_label);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_set_width(lv_label_0, 140);

        lv_obj_t * toggle_switch_0 = toggle_switch_create(lv_obj_0);
        lv_obj_bind_checked(toggle_switch_0, subject);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

