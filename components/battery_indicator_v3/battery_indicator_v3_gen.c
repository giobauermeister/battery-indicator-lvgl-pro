/**
 * @file battery_indicator_v3_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "battery_indicator_v3_gen.h"
#include "../../battery_indicator.h"

/*********************
 *      DEFINES
 *********************/

#define LIGHT_GREY (lv_color_hex(0x808080))
#define DARK_GREY (lv_color_hex(0xB2B2B2))
#define WHITE (lv_color_hex(0xFFFFFF))
#define BLACK (lv_color_hex(0x000000))
#define GREEN (lv_color_hex(0x37C557))
#define RED (lv_color_hex(0xFD3B2F))
#define YELLOW (lv_color_hex(0xFECC0B))


/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    /* <prop bindable="true">: a create() parameter AND an owned subject */
    lv_subject_t * value;
    lv_subject_t * charging;
    lv_subject_t * low_power;
    lv_subject_t * show_percentage;
    lv_subject_t * theme;
    lv_subject_t * low_threshold;
} battery_indicator_v3_t;

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static uint32_t battery_indicator_v3_get_instance_event;
static void battery_indicator_v3_get_instance_cb(lv_event_t * e);
static battery_indicator_v3_t * battery_indicator_v3_get_instance(lv_obj_t * obj);
static void battery_indicator_v3_destroy_instance(battery_indicator_v3_t * inst);
static void battery_indicator_v3_delete_cb(lv_event_t * e);
static lv_style_t * battery_indicator_v3_charging_mask_ref; /* set in create(), read by a binding callback */
static void battery_indicator_v3_battery_tip_style_bg_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_battery_mode_outline_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_mask_container_style_enabled_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_battery_border_style_border_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_battery_slider_a_mode_style_bg_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_img_thunder_charging_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_img_thunder_charging_style_image_recolor_opa_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_battery_slider_b_mode_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_battery_slider_b_mode_style_bg_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_battery_slider_b_mode_style_bg_color_binding_cb_2(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_pct_text_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_pct_text_style_text_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_img_thunder_charging_small_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject);
static void battery_indicator_v3_img_thunder_charging_small_style_image_recolor_opa_binding_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * battery_indicator_v3_create(lv_obj_t * parent, int32_t value, bool charging, bool low_power, bool show_percentage, int32_t theme, int32_t low_threshold)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t container;
    static lv_style_t tip;
    static lv_style_t hidden_knob;
    static lv_style_t outline_border;
    static lv_style_t outline_slider;
    static lv_style_t outline_fill;
    static lv_style_t charging_mask;
    static lv_style_t percentage_fill;
    static lv_style_t percentage_background;
    static lv_style_t percentage_text;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&container);
        lv_style_init(&tip);
        lv_style_init(&hidden_knob);
        lv_style_init(&outline_border);
        lv_style_init(&outline_slider);
        lv_style_init(&outline_fill);
        lv_style_init(&charging_mask);
        lv_style_init(&percentage_fill);
        lv_style_init(&percentage_background);
        lv_style_init(&percentage_text);

        lv_style_set_border_width(&container, 0);
        lv_style_set_bg_opa(&container, 0);
        lv_style_set_pad_all(&container, 0);
        lv_style_set_border_width(&tip, 0);
        lv_style_set_opa(&hidden_knob, 0);
        lv_style_set_radius(&outline_border, 14);
        lv_style_set_border_width(&outline_border, 3);
        lv_style_set_bg_opa(&outline_border, 0);
        lv_style_set_pad_all(&outline_border, 0);
        lv_style_set_radius(&outline_slider, 8);
        lv_style_set_bg_opa(&outline_slider, 0);
        lv_style_set_radius(&outline_fill, 8);
        lv_style_set_bitmap_mask_src(&charging_mask, img_battery_mask_v3);
        lv_style_set_radius(&percentage_fill, 0);
        lv_style_set_bg_opa(&percentage_background, 255);
        lv_style_set_border_width(&percentage_text, 0);
        lv_style_set_bg_opa(&percentage_text, 0);
        lv_style_set_pad_all(&percentage_text, 0);
        lv_style_set_layout(&percentage_text, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&percentage_text, LV_FLEX_FLOW_ROW);
        lv_style_set_pad_column(&percentage_text, 2);
        lv_style_set_pad_top(&percentage_text, 0);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    if(battery_indicator_v3_get_instance_event == 0) battery_indicator_v3_get_instance_event = lv_event_register_id();
    battery_indicator_v3_t * inst = lv_malloc(sizeof(battery_indicator_v3_t));
    lv_memzero(inst, sizeof(battery_indicator_v3_t));
    inst->value = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(inst->value, value);
    inst->charging = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(inst->charging, charging);
    inst->low_power = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(inst->low_power, low_power);
    inst->show_percentage = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(inst->show_percentage, show_percentage);
    inst->theme = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(inst->theme, theme);
    inst->low_threshold = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(inst->low_threshold, low_threshold);

    #if BATTERY_INDICATOR_CHECK_COMPILE_TARGET(BATTERY_INDICATOR_TARGET_ALL)
    if (battery_indicator_check_target(BATTERY_INDICATOR_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "battery_indicator_v3_#");
        lv_obj_add_event_cb(lv_obj_0, battery_indicator_v3_get_instance_cb, battery_indicator_v3_get_instance_event, inst);
        lv_obj_set_width(lv_obj_0, 79);
        lv_obj_set_height(lv_obj_0, 38);
        lv_obj_set_scrollable(lv_obj_0, false);

        lv_obj_add_style(lv_obj_0, &container, 0);
        lv_obj_t * battery_tip_container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(battery_tip_container, "battery_tip_container");
        lv_obj_set_width(battery_tip_container, 4);
        lv_obj_set_height(battery_tip_container, 12);
        lv_obj_set_align(battery_tip_container, LV_ALIGN_RIGHT_MID);
        lv_obj_set_scrollable(battery_tip_container, false);
        lv_obj_set_style_radius(battery_tip_container, 0, 0);
        lv_obj_set_style_border_width(battery_tip_container, 0, 0);
        lv_obj_set_style_pad_all(battery_tip_container, 0, 0);
        lv_obj_set_style_bg_opa(battery_tip_container, 0, 0);
        lv_obj_t * battery_tip = lv_obj_create(battery_tip_container);
        lv_obj_set_name(battery_tip, "battery_tip");
        lv_obj_set_width(battery_tip, 12);
        lv_obj_set_height(battery_tip, 12);
        lv_obj_set_align(battery_tip, LV_ALIGN_RIGHT_MID);
        lv_subject_add_observer_obj(inst->show_percentage, battery_indicator_v3_battery_tip_style_bg_color_binding_cb, battery_tip, inst);
        lv_subject_add_observer_obj(inst->value, battery_indicator_v3_battery_tip_style_bg_color_binding_cb, battery_tip, inst);
        lv_subject_add_observer_obj(inst->low_power, battery_indicator_v3_battery_tip_style_bg_color_binding_cb, battery_tip, inst);
        lv_subject_add_observer_obj(inst->low_threshold, battery_indicator_v3_battery_tip_style_bg_color_binding_cb, battery_tip, inst);
        lv_subject_add_observer_obj(inst->charging, battery_indicator_v3_battery_tip_style_bg_color_binding_cb, battery_tip, inst);
        lv_subject_add_observer_obj(inst->theme, battery_indicator_v3_battery_tip_style_bg_color_binding_cb, battery_tip, inst);
        lv_obj_add_style(battery_tip, &tip, 0);

        lv_obj_t * battery_mode_outline = lv_obj_create(lv_obj_0);
        lv_obj_set_name(battery_mode_outline, "battery_mode_outline");
        lv_obj_set_width(battery_mode_outline, 72);
        lv_obj_set_height(battery_mode_outline, 38);
        lv_obj_set_align(battery_mode_outline, LV_ALIGN_LEFT_MID);
        lv_obj_set_scrollable(battery_mode_outline, false);
        lv_subject_add_observer_obj(inst->show_percentage, battery_indicator_v3_battery_mode_outline_hidden_binding_cb, battery_mode_outline, inst);
        lv_obj_add_style(battery_mode_outline, &container, 0);
        lv_obj_t * mask_container = lv_obj_create(battery_mode_outline);
        lv_obj_set_name(mask_container, "mask_container");
        lv_obj_set_width(mask_container, 72);
        lv_obj_set_height(mask_container, 38);
        lv_obj_set_align(mask_container, LV_ALIGN_LEFT_MID);
        lv_obj_set_scrollable(mask_container, false);
        lv_obj_add_style(mask_container, &container, 0);
        lv_obj_add_style(mask_container, &charging_mask, 0);
        battery_indicator_v3_charging_mask_ref = &charging_mask;
        lv_subject_add_observer_obj(inst->charging, battery_indicator_v3_mask_container_style_enabled_cb, mask_container, inst);
        lv_obj_t * battery_border = lv_obj_create(mask_container);
        lv_obj_set_name(battery_border, "battery_border");
        lv_obj_set_width(battery_border, 72);
        lv_obj_set_height(battery_border, 38);
        lv_obj_set_align(battery_border, LV_ALIGN_LEFT_MID);
        lv_obj_set_scrollable(battery_border, false);
        lv_subject_add_observer_obj(inst->theme, battery_indicator_v3_battery_border_style_border_color_binding_cb, battery_border, inst);
        lv_obj_add_style(battery_border, &outline_border, 0);
        lv_obj_t * battery_slider_a_mode = lv_slider_create(battery_border);
        lv_obj_set_name(battery_slider_a_mode, "battery_slider_a_mode");
        lv_obj_set_width(battery_slider_a_mode, 60);
        lv_obj_set_height(battery_slider_a_mode, 26);
        lv_slider_set_min_value(battery_slider_a_mode, 0);
        lv_slider_set_max_value(battery_slider_a_mode, 100);
        lv_slider_set_value(battery_slider_a_mode, value, false);
        lv_obj_set_align(battery_slider_a_mode, LV_ALIGN_LEFT_MID);
        lv_obj_set_x(battery_slider_a_mode, 3);
        lv_obj_set_scrollable(battery_slider_a_mode, false);
        lv_subject_add_observer_obj(inst->low_power, battery_indicator_v3_battery_slider_a_mode_style_bg_color_binding_cb, battery_slider_a_mode, inst);
        lv_subject_add_observer_obj(inst->value, battery_indicator_v3_battery_slider_a_mode_style_bg_color_binding_cb, battery_slider_a_mode, inst);
        lv_subject_add_observer_obj(inst->low_threshold, battery_indicator_v3_battery_slider_a_mode_style_bg_color_binding_cb, battery_slider_a_mode, inst);
        lv_subject_add_observer_obj(inst->charging, battery_indicator_v3_battery_slider_a_mode_style_bg_color_binding_cb, battery_slider_a_mode, inst);
        lv_subject_add_observer_obj(inst->theme, battery_indicator_v3_battery_slider_a_mode_style_bg_color_binding_cb, battery_slider_a_mode, inst);
        lv_obj_add_style(battery_slider_a_mode, &outline_slider, 0);
        lv_obj_add_style(battery_slider_a_mode, &outline_fill, LV_PART_INDICATOR);
        lv_obj_add_style(battery_slider_a_mode, &hidden_knob, LV_PART_KNOB);

        lv_obj_t * img_thunder_charging = lv_image_create(battery_mode_outline);
        lv_obj_set_name(img_thunder_charging, "img_thunder_charging");
        lv_image_set_src(img_thunder_charging, img_thunder_v2);
        lv_obj_set_align(img_thunder_charging, LV_ALIGN_CENTER);
        lv_subject_add_observer_obj(inst->charging, battery_indicator_v3_img_thunder_charging_hidden_binding_cb, img_thunder_charging, inst);
        lv_obj_set_style_image_recolor(img_thunder_charging, BLACK, 0);
        lv_subject_add_observer_obj(inst->theme, battery_indicator_v3_img_thunder_charging_style_image_recolor_opa_binding_cb, img_thunder_charging, inst);

        lv_obj_t * battery_slider_b_mode = lv_slider_create(lv_obj_0);
        lv_obj_set_name(battery_slider_b_mode, "battery_slider_b_mode");
        lv_obj_set_width(battery_slider_b_mode, 72);
        lv_obj_set_height(battery_slider_b_mode, 38);
        lv_slider_set_min_value(battery_slider_b_mode, 0);
        lv_slider_set_max_value(battery_slider_b_mode, 100);
        lv_slider_set_value(battery_slider_b_mode, value, false);
        lv_obj_set_align(battery_slider_b_mode, LV_ALIGN_LEFT_MID);
        lv_obj_set_scrollable(battery_slider_b_mode, false);
        lv_subject_add_observer_obj(inst->show_percentage, battery_indicator_v3_battery_slider_b_mode_hidden_binding_cb, battery_slider_b_mode, inst);
        lv_obj_set_style_radius(battery_slider_b_mode, 14, 0);
        lv_subject_add_observer_obj(inst->theme, battery_indicator_v3_battery_slider_b_mode_style_bg_color_binding_cb, battery_slider_b_mode, inst);
        lv_subject_add_observer_obj(inst->low_power, battery_indicator_v3_battery_slider_b_mode_style_bg_color_binding_cb_2, battery_slider_b_mode, inst);
        lv_subject_add_observer_obj(inst->value, battery_indicator_v3_battery_slider_b_mode_style_bg_color_binding_cb_2, battery_slider_b_mode, inst);
        lv_subject_add_observer_obj(inst->low_threshold, battery_indicator_v3_battery_slider_b_mode_style_bg_color_binding_cb_2, battery_slider_b_mode, inst);
        lv_subject_add_observer_obj(inst->charging, battery_indicator_v3_battery_slider_b_mode_style_bg_color_binding_cb_2, battery_slider_b_mode, inst);
        lv_subject_add_observer_obj(inst->theme, battery_indicator_v3_battery_slider_b_mode_style_bg_color_binding_cb_2, battery_slider_b_mode, inst);
        lv_obj_add_style(battery_slider_b_mode, &hidden_knob, LV_PART_KNOB);
        lv_obj_add_style(battery_slider_b_mode, &percentage_fill, LV_PART_INDICATOR);
        lv_obj_add_style(battery_slider_b_mode, &percentage_background, 0);
        lv_obj_t * text_indicator_container = lv_obj_create(battery_slider_b_mode);
        lv_obj_set_name(text_indicator_container, "text_indicator_container");
        lv_obj_set_width(text_indicator_container, LV_SIZE_CONTENT);
        lv_obj_set_height(text_indicator_container, LV_SIZE_CONTENT);
        lv_obj_set_align(text_indicator_container, LV_ALIGN_CENTER);
        lv_obj_add_style(text_indicator_container, &percentage_text, 0);
        lv_obj_t * pct_text = lv_label_create(text_indicator_container);
        lv_obj_set_name(pct_text, "pct_text");
        lv_subject_add_observer_obj(inst->value, battery_indicator_v3_pct_text_text_binding_cb, pct_text, inst);
        lv_obj_set_style_text_font(pct_text, font_inter_semibold_30, 0);
        lv_obj_set_style_text_letter_space(pct_text, -1, 0);
        lv_obj_set_style_text_align(pct_text, LV_TEXT_ALIGN_LEFT, 0);
        lv_subject_add_observer_obj(inst->low_power, battery_indicator_v3_pct_text_style_text_color_binding_cb, pct_text, inst);
        lv_subject_add_observer_obj(inst->value, battery_indicator_v3_pct_text_style_text_color_binding_cb, pct_text, inst);
        lv_subject_add_observer_obj(inst->low_threshold, battery_indicator_v3_pct_text_style_text_color_binding_cb, pct_text, inst);
        lv_subject_add_observer_obj(inst->charging, battery_indicator_v3_pct_text_style_text_color_binding_cb, pct_text, inst);
        lv_subject_add_observer_obj(inst->theme, battery_indicator_v3_pct_text_style_text_color_binding_cb, pct_text, inst);

        lv_obj_t * img_thunder_charging_small = lv_image_create(text_indicator_container);
        lv_obj_set_name(img_thunder_charging_small, "img_thunder_charging_small");
        lv_image_set_src(img_thunder_charging_small, img_thunder_small_v2);
        lv_obj_set_style_pad_top(img_thunder_charging_small, 13, 0);
        lv_subject_add_observer_obj(inst->charging, battery_indicator_v3_img_thunder_charging_small_hidden_binding_cb, img_thunder_charging_small, inst);
        lv_obj_set_style_image_recolor(img_thunder_charging_small, BLACK, 0);
        lv_subject_add_observer_obj(inst->charging, battery_indicator_v3_img_thunder_charging_small_style_image_recolor_opa_binding_cb, img_thunder_charging_small, inst);
        lv_subject_add_observer_obj(inst->low_power, battery_indicator_v3_img_thunder_charging_small_style_image_recolor_opa_binding_cb, img_thunder_charging_small, inst);

        the_root = lv_obj_0;
    }
    #endif

    if(the_root) lv_obj_add_event_cb(the_root, battery_indicator_v3_delete_cb, LV_EVENT_DELETE, inst);
    else battery_indicator_v3_destroy_instance(inst); /* no target matched, so nothing owns it */

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

void battery_indicator_v3_set_value(lv_obj_t * obj, int32_t value)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    if(inst) lv_subject_set_int(inst->value, value);
}

int32_t battery_indicator_v3_get_value(lv_obj_t * obj)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    return inst ? (int32_t)lv_subject_get_int(inst->value) : (int32_t)0;
}

void battery_indicator_v3_set_charging(lv_obj_t * obj, int32_t charging)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    if(inst) lv_subject_set_int(inst->charging, charging);
}

int32_t battery_indicator_v3_get_charging(lv_obj_t * obj)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    return inst ? (int32_t)lv_subject_get_int(inst->charging) : (int32_t)0;
}

void battery_indicator_v3_set_low_power(lv_obj_t * obj, int32_t low_power)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    if(inst) lv_subject_set_int(inst->low_power, low_power);
}

int32_t battery_indicator_v3_get_low_power(lv_obj_t * obj)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    return inst ? (int32_t)lv_subject_get_int(inst->low_power) : (int32_t)0;
}

void battery_indicator_v3_set_show_percentage(lv_obj_t * obj, int32_t show_percentage)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    if(inst) lv_subject_set_int(inst->show_percentage, show_percentage);
}

int32_t battery_indicator_v3_get_show_percentage(lv_obj_t * obj)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    return inst ? (int32_t)lv_subject_get_int(inst->show_percentage) : (int32_t)0;
}

void battery_indicator_v3_set_theme(lv_obj_t * obj, int32_t theme)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    if(inst) lv_subject_set_int(inst->theme, theme);
}

int32_t battery_indicator_v3_get_theme(lv_obj_t * obj)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    return inst ? (int32_t)lv_subject_get_int(inst->theme) : (int32_t)0;
}

void battery_indicator_v3_set_low_threshold(lv_obj_t * obj, int32_t low_threshold)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    if(inst) lv_subject_set_int(inst->low_threshold, low_threshold);
}

int32_t battery_indicator_v3_get_low_threshold(lv_obj_t * obj)
{
    battery_indicator_v3_t * inst = battery_indicator_v3_get_instance(obj);
    return inst ? (int32_t)lv_subject_get_int(inst->low_threshold) : (int32_t)0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void battery_indicator_v3_get_instance_cb(lv_event_t * e)
{
    void ** out = lv_event_get_param(e);
    *out = lv_event_get_user_data(e);
}

static battery_indicator_v3_t * battery_indicator_v3_get_instance(lv_obj_t * obj)
{
    battery_indicator_v3_t * inst = NULL;
    for(lv_obj_t * o = obj; o && !inst; o = lv_obj_get_parent(o)) {
        lv_obj_send_event(o, battery_indicator_v3_get_instance_event, &inst);
    }
    return inst;
}

static void battery_indicator_v3_destroy_instance(battery_indicator_v3_t * inst)
{
    lv_subject_delete(inst->value);
    lv_subject_delete(inst->charging);
    lv_subject_delete(inst->low_power);
    lv_subject_delete(inst->show_percentage);
    lv_subject_delete(inst->theme);
    lv_subject_delete(inst->low_threshold);
    lv_free(inst);
}

static void battery_indicator_v3_delete_cb(lv_event_t * e)
{
    battery_indicator_v3_destroy_instance(lv_event_get_user_data(e));
}

static void battery_indicator_v3_battery_tip_style_bg_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_bg_color(obj, (lv_subject_get_int(inst->show_percentage) && lv_subject_get_int(inst->value) == 100) ? (lv_subject_get_int(inst->low_power) ? YELLOW : (lv_subject_get_int(inst->value) <= lv_subject_get_int(inst->low_threshold) ? RED : (lv_subject_get_int(inst->charging) ? GREEN : (lv_subject_get_int(inst->theme) == 1 ? BLACK : WHITE)))) : lv_subject_get_int(inst->theme) == 1 ? DARK_GREY : LIGHT_GREY, 0);
}

static void battery_indicator_v3_battery_mode_outline_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_hidden(obj, lv_subject_get_int(inst->show_percentage));
}

static void battery_indicator_v3_mask_container_style_enabled_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_enabled(obj, battery_indicator_v3_charging_mask_ref, 0, lv_subject_get_int(inst->charging));
}

static void battery_indicator_v3_battery_border_style_border_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_border_color(obj, lv_subject_get_int(inst->theme) == 1 ? DARK_GREY : LIGHT_GREY, 0);
}

static void battery_indicator_v3_battery_slider_a_mode_style_bg_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_bg_color(obj, lv_subject_get_int(inst->low_power) ? YELLOW : lv_subject_get_int(inst->value) <= lv_subject_get_int(inst->low_threshold) ? RED : (lv_subject_get_int(inst->charging) ? GREEN : (lv_subject_get_int(inst->theme) == 1 ? BLACK : WHITE)), LV_PART_INDICATOR);
}

static void battery_indicator_v3_img_thunder_charging_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_hidden(obj, !lv_subject_get_int(inst->charging));
}

static void battery_indicator_v3_img_thunder_charging_style_image_recolor_opa_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_image_recolor_opa(obj, lv_subject_get_int(inst->theme) == 1 ? 255 : 0, 0);
}

static void battery_indicator_v3_battery_slider_b_mode_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_hidden(obj, !lv_subject_get_int(inst->show_percentage));
}

static void battery_indicator_v3_battery_slider_b_mode_style_bg_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_bg_color(obj, lv_subject_get_int(inst->theme) == 1 ? DARK_GREY : LIGHT_GREY, 0);
}

static void battery_indicator_v3_battery_slider_b_mode_style_bg_color_binding_cb_2(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_bg_color(obj, lv_subject_get_int(inst->low_power) ? YELLOW : lv_subject_get_int(inst->value) <= lv_subject_get_int(inst->low_threshold) ? RED : (lv_subject_get_int(inst->charging) ? GREEN : (lv_subject_get_int(inst->theme) == 1 ? BLACK : WHITE)), LV_PART_INDICATOR);
}

static void battery_indicator_v3_pct_text_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    char eval_buf_1[LV_XML_EVAL_STRING_BUF_SIZE];
    lv_snprintf(eval_buf_1, sizeof(eval_buf_1), "%d", (int)(lv_subject_get_int(inst->value)));
    lv_label_set_text(obj, eval_buf_1);
}

static void battery_indicator_v3_pct_text_style_text_color_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_text_color(obj, lv_subject_get_int(inst->low_power) ? BLACK : ((lv_subject_get_int(inst->value) <= lv_subject_get_int(inst->low_threshold) || lv_subject_get_int(inst->charging)) ? WHITE : (lv_subject_get_int(inst->theme) == 1 ? WHITE : BLACK)), 0);
}

static void battery_indicator_v3_img_thunder_charging_small_hidden_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_hidden(obj, !lv_subject_get_int(inst->charging));
}

static void battery_indicator_v3_img_thunder_charging_small_style_image_recolor_opa_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    battery_indicator_v3_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    lv_obj_set_style_image_recolor_opa(obj, lv_subject_get_int(inst->charging) && lv_subject_get_int(inst->low_power) ? 255 : 0, 0);
}

