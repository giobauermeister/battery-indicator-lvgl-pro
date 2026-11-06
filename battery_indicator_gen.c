/**
 * @file battery_indicator_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "battery_indicator.h"

#if defined(LV_USE_XML) && LV_USE_XML
#include "widgets/wd_battery_v2/wd_battery_v2_private_gen.h"
#include "widgets/wd_battery/wd_battery_private_gen.h"
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void check_font(lv_font_t ** font, const char * name);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t battery_indicator_target = BATTERY_INDICATOR_COMPILE_TARGET;

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_hour_32;
extern lv_font_t font_hour_32_data;
lv_font_t * inter_28;
extern lv_font_t inter_28_data;
lv_font_t * font_hour_25;
extern lv_font_t font_hour_25_data;
lv_font_t * font_inter_semibold_30;
extern lv_font_t font_inter_semibold_30_data;
lv_font_t * font_inter_semibold_25;
extern lv_font_t font_inter_semibold_25_data;

/*----------------
 * Images
 *----------------*/

/* Targets: any */
const void * img_charging = NULL;
extern const void * img_charging_data;
const void * img_charging_no_stroke = NULL;
extern const void * img_charging_no_stroke_data;
const void * img_charging_small = NULL;
extern const void * img_charging_small_data;
const void * img_thunder_transparent = NULL;
extern const void * img_thunder_transparent_data;
const void * img_thunder_v2 = NULL;
extern const void * img_thunder_v2_data;
const void * img_thunder_small_v2 = NULL;
extern const void * img_thunder_small_v2_data;
const void * img_battery_mask_v2 = NULL;
extern const void * img_battery_mask_v2_data;
const void * img_battery_mask_v3 = NULL;
extern const void * img_battery_mask_v3_data;
const void * img_background = NULL;
extern const void * img_background_data;
const void * img_background_light = NULL;
extern const void * img_background_light_data;

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

lv_subject_t * battery_value;
lv_subject_t * low_power_mode;
lv_subject_t * battery_show_percentage;
lv_subject_t * battery_charging;
lv_subject_t * battery_theme;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void battery_indicator_init_gen(const char * asset_path)
{

    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if BATTERY_INDICATOR_CHECK_COMPILE_TARGET(BATTERY_INDICATOR_TARGET_ALL)
    if (battery_indicator_check_target(BATTERY_INDICATOR_TARGET_ALL)) {
        if (!font_hour_32) {
            /* font_hour_32 */
            /* get font 'font_hour_32' from a C array */
            font_hour_32 = &font_hour_32_data;

        }
        if (!inter_28) {
            /* inter_28 */
            /* get font 'inter_28' from a C array */
            inter_28 = &inter_28_data;

        }
        if (!font_hour_25) {
            /* font_hour_25 */
            /* get font 'font_hour_25' from a C array */
            font_hour_25 = &font_hour_25_data;

        }
        if (!font_inter_semibold_30) {
            /* font_inter_semibold_30 */
            /* get font 'font_inter_semibold_30' from a C array */
            font_inter_semibold_30 = &font_inter_semibold_30_data;

        }
        if (!font_inter_semibold_25) {
            /* font_inter_semibold_25 */
            /* get font 'font_inter_semibold_25' from a C array */
            font_inter_semibold_25 = &font_inter_semibold_25_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/

    /* Targets: any */
    #if BATTERY_INDICATOR_CHECK_COMPILE_TARGET(BATTERY_INDICATOR_TARGET_ALL)
    if (battery_indicator_check_target(BATTERY_INDICATOR_TARGET_ALL)) {
        /* img_charging */
        if (!img_charging) {
            img_charging = &img_charging_data;
        }
        /* img_charging_no_stroke */
        if (!img_charging_no_stroke) {
            img_charging_no_stroke = &img_charging_no_stroke_data;
        }
        /* img_charging_small */
        if (!img_charging_small) {
            img_charging_small = &img_charging_small_data;
        }
        /* img_thunder_transparent */
        if (!img_thunder_transparent) {
            img_thunder_transparent = &img_thunder_transparent_data;
        }
        /* img_thunder_v2 */
        if (!img_thunder_v2) {
            img_thunder_v2 = &img_thunder_v2_data;
        }
        /* img_thunder_small_v2 */
        if (!img_thunder_small_v2) {
            img_thunder_small_v2 = &img_thunder_small_v2_data;
        }
        /* img_battery_mask_v2 */
        if (!img_battery_mask_v2) {
            img_battery_mask_v2 = &img_battery_mask_v2_data;
        }
        /* img_battery_mask_v3 */
        if (!img_battery_mask_v3) {
            img_battery_mask_v3 = &img_battery_mask_v3_data;
        }
        /* img_background */
        if (!img_background) {
            img_background = &img_background_data;
        }
        /* img_background_light */
        if (!img_background_light) {
            img_background_light = &img_background_light_data;
        }
    }
    #endif

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Subjects
     *----------------*/
    battery_value = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(battery_value, 50);
    low_power_mode = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(low_power_mode, 0);
    battery_show_percentage = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(battery_show_percentage, 0);
    battery_charging = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(battery_charging, 0);
    battery_theme = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(battery_theme, 0);

    /*----------------
     * Translations
     *----------------*/

#if defined(LV_USE_XML) && LV_USE_XML
    /* Register widgets */
    wd_battery_v2_register();
    wd_battery_register();

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&font_hour_32, "font_hour_32");
    check_font(&inter_28, "inter_28");
    check_font(&font_hour_25, "font_hour_25");
    check_font(&font_inter_semibold_30, "font_inter_semibold_30");
    check_font(&font_inter_semibold_25, "font_inter_semibold_25");

    /* Register fonts */
    lv_xml_register_font(NULL, "font_hour_32", font_hour_32);
    lv_xml_register_font(NULL, "inter_28", inter_28);
    lv_xml_register_font(NULL, "font_hour_25", font_hour_25);
    lv_xml_register_font(NULL, "font_inter_semibold_30", font_inter_semibold_30);
    lv_xml_register_font(NULL, "font_inter_semibold_25", font_inter_semibold_25);

    /* Register subjects */
    lv_xml_register_subject(NULL, "battery_value", battery_value);
    lv_xml_register_subject(NULL, "low_power_mode", low_power_mode);
    lv_xml_register_subject(NULL, "battery_show_percentage", battery_show_percentage);
    lv_xml_register_subject(NULL, "battery_charging", battery_charging);
    lv_xml_register_subject(NULL, "battery_theme", battery_theme);

    /* Register callbacks */
    lv_xml_register_event_cb(NULL, "btn_low_power_toggle_cb", btn_low_power_toggle_cb);
    lv_xml_register_event_cb(NULL, "btn_charging_toggle_cb", btn_charging_toggle_cb);

    /* Register easing callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if defined(LV_USE_XML) && LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "img_charging", img_charging);
    lv_xml_register_image(NULL, "img_charging_no_stroke", img_charging_no_stroke);
    lv_xml_register_image(NULL, "img_charging_small", img_charging_small);
    lv_xml_register_image(NULL, "img_thunder_transparent", img_thunder_transparent);
    lv_xml_register_image(NULL, "img_thunder_v2", img_thunder_v2);
    lv_xml_register_image(NULL, "img_thunder_small_v2", img_thunder_small_v2);
    lv_xml_register_image(NULL, "img_battery_mask_v2", img_battery_mask_v2);
    lv_xml_register_image(NULL, "img_battery_mask_v3", img_battery_mask_v3);
    lv_xml_register_image(NULL, "img_background", img_background);
    lv_xml_register_image(NULL, "img_background_light", img_background_light);
#endif

#if !defined(LV_USE_XML) || LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
#endif
}

void battery_indicator_set_target(uint32_t target)
{
    battery_indicator_target = target;
}

uint32_t battery_indicator_get_target(void)
{
    return battery_indicator_target;
}

bool battery_indicator_check_target(uint32_t target)
{
    return (battery_indicator_target & target) ? true : false;
}

/* Callbacks */
#if defined(LV_EDITOR_PREVIEW)
void __attribute__((weak)) btn_low_power_toggle_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("btn_low_power_toggle_cb was called\n");
}
void __attribute__((weak)) btn_charging_toggle_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("btn_charging_toggle_cb was called\n");
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = (lv_font_t *)LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}