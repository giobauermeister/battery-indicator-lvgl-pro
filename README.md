# An iOS inspired battery indicator made in LVGL's UI Editor

<!-- ![alt text](gh_assets/battery_indicator.gif)
![alt text](gh_assets/battery_indicator_widget.gif) -->

<p align="center">
  <img src="gh_assets/battery_indicator.gif" width="30%"/>
  <img src="gh_assets/battery_indicator_widget.gif" width="30%"/>
  <img src="gh_assets/battery_indicator_widget_v2.gif" width="30%"/>
</p>

This project is a battery indicator component example to be used in LVGL's UI Editor.
It includes 3 different battery indicator designs that explore XML components, data bindings and custom widgets (XML + C custom code).

To test each battery design, chose one of them in the `top_bar.xml` file inside `components/top_bar`:
```
<!-- Try here the 3 different battery indicators -->

<!-- Old iOS battery indicator, full XML component -->
<!-- <battery align="right_mid"></battery> -->

<!-- New iOS battery indicator, without the normal light state, full XML component -->
<!-- <battery_indicator_2 align="right_mid"></battery_indicator_2> -->

<!-- New iOS battery indicator with light state and fully functional as a widget (XML + custom C code) -->
<wd_battery bind_charging="battery_charging" bind_low_power="low_power_mode" bind_value="battery_value" align="right_mid"></wd_battery>
```

There is a new battery indicator widget `wd_battery_v2` which has all features built in:
- Percetage mode
- Charging icon mask
- Dark/Light themes

All the features can be controlled via subjects.

This new widget can be seen and tested on the `smartwatch_v2.xml` screen.

Download this repo and open the folder containing `project.xml` in LVGL Pro 2.1.0.

![alt text](gh_assets/battery_indicator_editor.png)

You can also see it live in the online preview: [Battery Indicator Online Live Preview](https://viewer.lvgl.io/?repo=https://github.com/giobauermeister/battery-indicator-lvgl-editor/tree/main/battery_indicator)

Figma design. Access [here](https://www.figma.com/design/HVvM9m0egZy0wYZDLKKPTA/Battery-Indicator).

![alt text](gh_assets/battery_indicator_figma.png)

Tested in a real hardware. Waveshare smartwatch: [https://www.waveshare.com/esp32-s3-touch-amoled-2.06.htm](https://www.waveshare.com/esp32-s3-touch-amoled-2.06.htm)

![alt text](gh_assets/smartwatch.jpg)

Please visit [https://lvgl.io/editor](https://lvgl.io/editor) for more information.


## LVGL Pro 2.1

This project targets LVGL 9.6.0 and is validated and generated with LVGL Pro CLI 2.1.0.
From the directory containing `project.xml`, run:

```sh
lvglpro validate "$PWD"
lvglpro build
lvglpro compile "$PWD" --target cli
lvglpro run-all-tests "$PWD"
lvglpro compile "$PWD" --target editor
```

`lvglpro` is the local CLI wrapper; `build` generates the C sources and compiles
with `--target editor`. Edit the XML and custom C sources, then regenerate;
never hand-edit `*_gen.c`, `*_gen.h`, or `*_private_gen.h`. Tests use a separate
CLI runtime, so rebuild it before testing custom C changes. The final compile
restores the Editor build configuration.

The global subjects `charging` and `show_percentage` are now named
`battery_charging` and `battery_show_percentage` to avoid conflicts with widget
API properties in the 2.1 validator. Widget property and binding names are
unchanged. Generated global subjects are now `lv_subject_t *`: pass them directly
to `lv_subject_get_int` / `lv_subject_set_int`, without `&`.

Custom widget parsers use the standalone `lv_xml_private` headers. The unused
charging animation timelines were removed from `wd_battery_v2.xml` because 2.1
supports XML timelines in components and screens, but not widgets. Charging still
switches immediately through the existing widget logic. Indicator thresholds,
colors, masks, themes, and subject defaults retain their existing behavior.
