/**
 * @file button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "button_gen.h"
#include "../../battery_indicator.h"

/*********************
 *      DEFINES
 *********************/

#define LOW_POWER (false)


/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    /* <prop type="subject">: owned by the caller, stored, never deleted */
    lv_subject_t * subject;

    /* A plain <prop> a binding froze. The runtime inlines it, because it
     * re-parses the view per instance; the generator compiles once, so the value
     * is kept here and read back in the callback. A plain field, not a subject:
     * nothing ever notifies on it. */
    lv_color_t enabled_color_snapshot;
} button_t;

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static void button_destroy_instance(button_t * inst);
static void button_delete_cb(lv_event_t * e);
static void button_lv_button_0_style_bg_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * button_create(lv_obj_t * parent, const char * text, lv_subject_t * subject, lv_color_t enabled_color)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_main);

        lv_style_set_shadow_width(&style_main, 0);
        lv_style_set_radius(&style_main, 51);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    button_t * inst = lv_malloc(sizeof(button_t));
    lv_memzero(inst, sizeof(button_t));
    inst->subject = subject;
    inst->enabled_color_snapshot = enabled_color;

    #if BATTERY_INDICATOR_CHECK_COMPILE_TARGET(BATTERY_INDICATOR_TARGET_ALL)
    if (battery_indicator_check_target(BATTERY_INDICATOR_TARGET_ALL)) {
        lv_obj_t * lv_button_0 = lv_button_create(parent);
        lv_obj_set_name_static(lv_button_0, "button_#");
        lv_obj_set_width(lv_button_0, 300);
        lv_obj_set_height(lv_button_0, 90);
        lv_subject_add_observer_obj(inst->subject, button_lv_button_0_style_bg_color_binding_cb, lv_button_0, inst);

        lv_obj_add_style(lv_button_0, &style_main, 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, text);
        lv_obj_set_style_text_font(lv_label_0, inter_28, 0);
        lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0x474747), 0);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);

        the_root = lv_button_0;
    }
    #endif

    if(the_root) lv_obj_add_event_cb(the_root, button_delete_cb, LV_EVENT_DELETE, inst);
    else button_destroy_instance(inst); /* no target matched, so nothing owns it */

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void button_destroy_instance(button_t * inst)
{
    lv_free(inst);
}

static void button_delete_cb(lv_event_t * e)
{
    button_destroy_instance(lv_event_get_user_data(e));
}

static void button_lv_button_0_style_bg_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    button_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_bg_color(obj, lv_subject_get_int(inst->subject) == 0 ? lv_color_hex(0xd3d1d1) : inst->enabled_color_snapshot, 0);
}

