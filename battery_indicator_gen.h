/**
 * @file battery_indicator_gen.h
 */

#ifndef LVGL_PRO_BATTERY_INDICATOR_GEN_H
#define LVGL_PRO_BATTERY_INDICATOR_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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



/* Prototypes for target functions, needed by responsive const definitions */

void battery_indicator_set_target(uint32_t target);
uint32_t battery_indicator_get_target(void);
bool battery_indicator_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define BATTERY_INDICATOR_TARGET_UNDEFINED        (0 << 1)
#define BATTERY_INDICATOR_TARGET_WAVESHARE_WATCH  (1 << 1)
#define BATTERY_INDICATOR_TARGET_ALL              0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef BATTERY_INDICATOR_COMPILE_TARGET
#define BATTERY_INDICATOR_COMPILE_TARGET BATTERY_INDICATOR_TARGET_ALL
#endif

#define BATTERY_INDICATOR_CHECK_COMPILE_TARGET(target) (BATTERY_INDICATOR_COMPILE_TARGET & (target) ? 1 : 0)

#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**
 * Animation path of a style transition with a `bezier(…)` easing. The control
 * points come from the transition descriptor's `user_data`, as a transition
 * descriptor cannot store animation parameters itself.
 */
static inline int32_t battery_indicator_style_transition_bezier_path_helper(const lv_anim_t * a)
{
    const lv_anim_bezier3_para_t * para = (const lv_anim_bezier3_para_t *)lv_anim_get_user_data(a);
    if(para == NULL) return lv_anim_path_linear(a);

    lv_anim_t a_tmp = *a;
    lv_anim_set_bezier3_param(&a_tmp, para->x1, para->y1, para->x2, para->y2);
    return lv_anim_path_custom_bezier3(&a_tmp);
}

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * font_hour_32;
extern lv_font_t * inter_28;
extern lv_font_t * font_hour_25;
extern lv_font_t * font_inter_semibold_30;
extern lv_font_t * font_inter_semibold_25;


/*----------------
 * Images
 *----------------*/

/* Targets: any */
extern const void * img_charging;
extern const void * img_charging_no_stroke;
extern const void * img_charging_small;
extern const void * img_thunder_transparent;
extern const void * img_thunder_v2;
extern const void * img_thunder_small_v2;
extern const void * img_battery_mask_v2;
extern const void * img_background;
extern const void * img_background_light;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t * battery_value;
extern lv_subject_t * low_power_mode;
extern lv_subject_t * battery_show_percentage;
extern lv_subject_t * battery_charging;
extern lv_subject_t * battery_theme;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

void btn_low_power_toggle_cb(lv_event_t * e);
void btn_charging_toggle_cb(lv_event_t * e);

/*----------------
 * Easing Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void battery_indicator_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/battery_indicator_2/battery_indicator_2_gen.h"
#include "components/battery_indicator_v2/battery_indicator_v2_gen.h"
#include "components/battery_indicator/battery_gen.h"
#include "components/button/button_gen.h"
#include "components/charge_slider/charge_slider_gen.h"
#include "components/clock/clock_gen.h"
#include "components/settings_item/settings_item_gen.h"
#include "components/settings_menu_line/settings_menu_line_gen.h"
#include "components/settings_panel/settings_panel_gen.h"
#include "components/toggle_switch/toggle_switch_gen.h"
#include "components/top_bar/top_bar_gen.h"
#include "screens/smartwatch_v2/smartwatch_v2_gen.h"
#include "screens/smartwatch/smartwatch_gen.h"
#include "widgets/wd_battery_v2/wd_battery_v2_gen.h"
#include "widgets/wd_battery/wd_battery_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_BATTERY_INDICATOR_GEN_H*/