#include "hid.h"

int ev_total = 32;  /* # of elements in array */
char *ev[32] = {
       "syn","key","rel","abs","msc","ev_5",
       "ev_6","ev_7","ev_8","ev_9","ev_10","ev_11",
       "ev_12","ev_13","ev_14","ev_15","ev_16","led",
       "snd","ev_19","rep","ff","pwr","ff_status",
       "ev_24","ev_25","ev_26","ev_27","ev_28","ev_29",
       "ev_30","ev_31"
 };


int ev_syn_total = 2;  /* # of elements in array */
char *ev_syn[2] = {
       "syn_report","syn_config"
 };


int ev_key_total = 512;  /* # of elements in array */
char *ev_key[512] = {
       "key_reserved","key_esc","key_1","key_2","key_3","key_4",
       "key_5","key_6","key_7","key_8","key_9","key_0",
       "key_minus","key_equal","key_backspace","key_tab","key_q","key_w",
       "key_e","key_r","key_t","key_y","key_u","key_i",
       "key_o","key_p","key_leftbrace","key_rightbrace","key_enter","key_leftctrl",
       "key_a","key_s","key_d","key_f","key_g","key_h",
       "key_j","key_k","key_l","key_semicolon","key_apostrophe","key_grave",
       "key_leftshift","key_backslash","key_z","key_x","key_c","key_v",
       "key_b","key_n","key_m","key_comma","key_dot","key_slash",
       "key_rightshift","key_kpasterisk","key_leftalt","key_space","key_capslock","key_f1",
       "key_f2","key_f3","key_f4","key_f5","key_f6","key_f7",
       "key_f8","key_f9","key_f10","key_numlock","key_scrolllock","key_kp7",
       "key_kp8","key_kp9","key_kpminus","key_kp4","key_kp5","key_kp6",
       "key_kpplus","key_kp1","key_kp2","key_kp3","key_kp0","key_kpdot",
       "key_84","key_zenkakuhankaku","key_102nd","key_f11","key_f12","key_ro",
       "key_katakana","key_hiragana","key_henkan","key_katakanahiragana","key_muhenkan","key_kpjpcomma",
       "key_kpenter","key_rightctrl","key_kpslash","key_sysrq","key_rightalt","key_linefeed",
       "key_home","key_up","key_pageup","key_left","key_right","key_end",
       "key_down","key_pagedown","key_insert","key_delete","key_macro","key_mute",
       "key_volumedown","key_volumeup","key_power","key_kpequal","key_kpplusminus","key_pause",
       "key_120","key_kpcomma","key_hanguel","key_hanja","key_yen","key_leftmeta",
       "key_rightmeta","key_compose","key_stop","key_again","key_props","key_undo",
       "key_front","key_copy","key_open","key_paste","key_find","key_cut",
       "key_help","key_menu","key_calc","key_setup","key_sleep","key_wakeup",
       "key_file","key_sendfile","key_deletefile","key_xfer","key_prog1","key_prog2",
       "key_www","key_msdos","key_coffee","key_direction","key_cyclewindows","key_mail",
       "key_bookmarks","key_computer","key_back","key_forward","key_closecd","key_ejectcd",
       "key_ejectclosecd","key_nextsong","key_playpause","key_previoussong","key_stopcd","key_record",
       "key_rewind","key_phone","key_iso","key_config","key_homepage","key_refresh",
       "key_exit","key_move","key_edit","key_scrollup","key_scrolldown","key_kpleftparen",
       "key_kprightparen","key_181","key_182","key_f13","key_f14","key_f15",
       "key_f16","key_f17","key_f18","key_f19","key_f20","key_f21",
       "key_f22","key_f23","key_f24","key_195","key_196","key_197",
       "key_198","key_199","key_playcd","key_pausecd","key_prog3","key_prog4",
       "key_204","key_suspend","key_close","key_play","key_fastforward","key_bassboost",
       "key_print","key_hp","key_camera","key_sound","key_question","key_email",
       "key_chat","key_search","key_connect","key_finance","key_sport","key_shop",
       "key_alterase","key_cancel","key_brightnessdown","key_brightnessup","key_media","key_227",
       "key_228","key_229","key_230","key_231","key_232","key_233",
       "key_234","key_235","key_236","key_237","key_238","key_239",
       "key_unknown","key_241","key_242","key_243","key_244","key_245",
       "key_246","key_247","key_248","key_249","key_250","key_251",
       "key_252","key_253","key_254","key_255","btn_0","btn_1",
       "btn_2","btn_3","btn_4","btn_5","btn_6","btn_7",
       "btn_8","btn_9","key_266","key_267","key_268","key_269",
       "key_270","key_271","btn_left","btn_right","btn_middle","btn_side",
       "btn_extra","btn_forward","btn_back","btn_task","key_280","key_281",
       "key_282","key_283","key_284","key_285","key_286","key_287",
       "btn_trigger","btn_thumb","btn_thumb2","btn_top","btn_top2","btn_pinkie",
       "btn_base","btn_base2","btn_base3","btn_base4","btn_base5","btn_base6",
       "key_300","key_301","key_302","btn_dead","btn_a","btn_b",
       "btn_c","btn_x","btn_y","btn_z","btn_tl","btn_tr",
       "btn_tl2","btn_tr2","btn_select","btn_start","btn_mode","btn_thumbl",
       "btn_thumbr","key_319","btn_tool_pen","btn_tool_rubber","btn_tool_brush","btn_tool_pencil",
       "btn_tool_airbrush","btn_tool_finger","btn_tool_mouse","btn_tool_lens","key_328","key_329",
       "btn_touch","btn_stylus","btn_stylus2","btn_tool_doubletap","btn_tool_tripletap","key_335",
       "btn_gear_down","btn_gear_up","key_338","key_339","key_340","key_341",
       "key_342","key_343","key_344","key_345","key_346","key_347",
       "key_348","key_349","key_350","key_351","key_ok","key_select",
       "key_goto","key_clear","key_power2","key_option","key_info","key_time",
       "key_vendor","key_archive","key_program","key_channel","key_favorites","key_epg",
       "key_pvr","key_mhp","key_language","key_title","key_subtitle","key_angle",
       "key_zoom","key_mode","key_keyboard","key_screen","key_pc","key_tv",
       "key_tv2","key_vcr","key_vcr2","key_sat","key_sat2","key_cd",
       "key_tape","key_radio","key_tuner","key_player","key_text","key_dvd",
       "key_aux","key_mp3","key_audio","key_video","key_directory","key_list",
       "key_memo","key_calendar","key_red","key_green","key_yellow","key_blue",
       "key_channelup","key_channeldown","key_first","key_last","key_ab","key_next",
       "key_restart","key_slow","key_shuffle","key_break","key_previous","key_digits",
       "key_teen","key_twen","key_416","key_417","key_418","key_419",
       "key_420","key_421","key_422","key_423","key_424","key_425",
       "key_426","key_427","key_428","key_429","key_430","key_431",
       "key_432","key_433","key_434","key_435","key_436","key_437",
       "key_438","key_439","key_440","key_441","key_442","key_443",
       "key_444","key_445","key_446","key_447","key_del_eol","key_del_eos",
       "key_ins_line","key_del_line","key_452","key_453","key_454","key_455",
       "key_456","key_457","key_458","key_459","key_460","key_461",
       "key_462","key_463","key_fn","key_fn_esc","key_fn_f1","key_fn_f2",
       "key_fn_f3","key_fn_f4","key_fn_f5","key_fn_f6","key_fn_f7","key_fn_f8",
       "key_fn_f9","key_fn_f10","key_fn_f11","key_fn_f12","key_fn_1","key_fn_2",
       "key_fn_d","key_fn_e","key_fn_f","key_fn_s","key_fn_b","key_485",
       "key_486","key_487","key_488","key_489","key_490","key_491",
       "key_492","key_493","key_494","key_495","key_496","key_497",
       "key_498","key_499","key_500","key_501","key_502","key_503",
       "key_504","key_505","key_506","key_507","key_508","key_509",
       "key_510","key_511"
 };


int ev_rel_total = 16;  /* # of elements in array */
char *ev_rel[16] = {
       "rel_x","rel_y","rel_z","rel_rx","rel_ry","rel_rz",
       "rel_hwheel","rel_dial","rel_wheel","rel_misc","rel_10","rel_11",
       "rel_12","rel_13","rel_14","rel_15"
 };


int ev_abs_total = 64;  /* # of elements in array */
char *ev_abs[64] = {
       "abs_x","abs_y","abs_z","abs_rx","abs_ry","abs_rz",
       "abs_throttle","abs_rudder","abs_wheel","abs_gas","abs_brake","abs_11",
       "abs_12","abs_13","abs_14","abs_15","abs_hat0x","abs_hat0y",
       "abs_hat1x","abs_hat1y","abs_hat2x","abs_hat2y","abs_hat3x","abs_hat3y",
       "abs_pressure","abs_distance","abs_tilt_x","abs_tilt_y","abs_tool_width","abs_29",
       "abs_30","abs_31","abs_volume","abs_33","abs_34","abs_35",
       "abs_36","abs_37","abs_38","abs_39","abs_misc","abs_41",
       "abs_42","abs_43","abs_44","abs_45","abs_46","abs_47",
       "abs_48","abs_49","abs_50","abs_51","abs_52","abs_53",
       "abs_54","abs_55","abs_56","abs_57","abs_58","abs_59",
       "abs_60","abs_61","abs_62","abs_63"
 };


int ev_msc_total = 8;  /* # of elements in array */
char *ev_msc[8] = {
       "msc_serial","msc_pulseled","msc_gesture","msc_raw","msc_scan","msc_5",
       "msc_6","msc_7"
 };


int ev_led_total = 16;  /* # of elements in array */
char *ev_led[16] = {
       "led_numl","led_capsl","led_scrolll","led_compose","led_kana","led_sleep",
       "led_suspend","led_mute","led_misc","led_mail","led_charging","led_11",
       "led_12","led_13","led_14","led_15"
 };


int ev_snd_total = 8;  /* # of elements in array */
char *ev_snd[8] = {
       "snd_click","snd_bell","snd_tone","snd_3","snd_4","snd_5",
       "snd_6","snd_7"
 };


int ev_rep_total = 2;  /* # of elements in array */
char *ev_rep[2] = {
       "rep_delay","rep_period"
 };


int ev_ff_total = 128;  /* # of elements in array */
char *ev_ff[128] = {
       "ff_0","ff_1","ff_2","ff_3","ff_4","ff_5",
       "ff_6","ff_7","ff_8","ff_9","ff_10","ff_11",
       "ff_12","ff_13","ff_14","ff_15","ff_16","ff_17",
       "ff_18","ff_19","ff_20","ff_21","ff_22","ff_23",
       "ff_24","ff_25","ff_26","ff_27","ff_28","ff_29",
       "ff_30","ff_31","ff_32","ff_33","ff_34","ff_35",
       "ff_36","ff_37","ff_38","ff_39","ff_40","ff_41",
       "ff_42","ff_43","ff_44","ff_45","ff_46","ff_47",
       "ff_48","ff_49","ff_50","ff_51","ff_52","ff_53",
       "ff_54","ff_55","ff_56","ff_57","ff_58","ff_59",
       "ff_60","ff_61","ff_62","ff_63","ff_64","ff_65",
       "ff_66","ff_67","ff_68","ff_69","ff_70","ff_71",
       "ff_72","ff_73","ff_74","ff_75","ff_76","ff_77",
       "ff_78","ff_79","ff_rumble","ff_periodic","ff_constant","ff_spring",
       "ff_friction","ff_damper","ff_inertia","ff_ramp","ff_square","ff_triangle",
       "ff_sine","ff_saw_up","ff_saw_down","ff_custom","ff_94","ff_95",
       "ff_gain","ff_autocenter","ff_98","ff_99","ff_100","ff_101",
       "ff_102","ff_103","ff_104","ff_105","ff_106","ff_107",
       "ff_108","ff_109","ff_110","ff_111","ff_112","ff_113",
       "ff_114","ff_115","ff_116","ff_117","ff_118","ff_119",
       "ff_120","ff_121","ff_122","ff_123","ff_124","ff_125",
       "ff_126","ff_127"
 };


char *ev_pwr[1] = { NULL };

int ev_ff_status_total = 2;  /* # of elements in array */
char *ev_ff_status[2] = {
       "ff_status_stopped","ff_status_playing"
 };



       int ev_5_total = 16;  /* # of elements in array */
char *ev_5[16] = {
       "ev_5_1","ev_5_2","ev_5_3","ev_5_4","ev_5_5","ev_5_6",
       "ev_5_7","ev_5_8","ev_5_9","ev_5_10","ev_5_11","ev_5_12",
       "ev_5_13","ev_5_14","ev_5_15","ev_5_16"
 };


int ev_6_total = 16;  /* # of elements in array */
char *ev_6[16] = {
       "ev_6_1","ev_6_2","ev_6_3","ev_6_4","ev_6_5","ev_6_6",
       "ev_6_7","ev_6_8","ev_6_9","ev_6_10","ev_6_11","ev_6_12",
       "ev_6_13","ev_6_14","ev_6_15","ev_6_16"
 };



       int ev_7_total = 16;  /* # of elements in array */
char *ev_7[16] = {
       "ev_7_1","ev_7_2","ev_7_3","ev_7_4","ev_7_5","ev_7_6",
       "ev_7_7","ev_7_8","ev_7_9","ev_7_10","ev_7_11","ev_7_12",
       "ev_7_13","ev_7_14","ev_7_15","ev_7_16"
 };


int ev_8_total = 16;  /* # of elements in array */
char *ev_8[16] = {
       "ev_8_1","ev_8_2","ev_8_3","ev_8_4","ev_8_5","ev_8_6",
       "ev_8_7","ev_8_8","ev_8_9","ev_8_10","ev_8_11","ev_8_12",
       "ev_8_13","ev_8_14","ev_8_15","ev_8_16"
 };


int ev_9_total = 16;  /* # of elements in array */
char *ev_9[16] = {
       "ev_9_1","ev_9_2","ev_9_3","ev_9_4","ev_9_5","ev_9_6",
       "ev_9_7","ev_9_8","ev_9_9","ev_9_10","ev_9_11","ev_9_12",
       "ev_9_13","ev_9_14","ev_9_15","ev_9_16"
 };


int ev_10_total = 16;  /* # of elements in array */
char *ev_10[16] = {
       "ev_10_1","ev_10_2","ev_10_3","ev_10_4","ev_10_5","ev_10_6",
       "ev_10_7","ev_10_8","ev_10_9","ev_10_10","ev_10_11","ev_10_12",
       "ev_10_13","ev_10_14","ev_10_15","ev_10_16"
 };


int ev_11_total = 16;  /* # of elements in array */
char *ev_11[16] = {
       "ev_11_1","ev_11_2","ev_11_3","ev_11_4","ev_11_5","ev_11_6",
       "ev_11_7","ev_11_8","ev_11_9","ev_11_10","ev_11_11","ev_11_12",
       "ev_11_13","ev_11_14","ev_11_15","ev_11_16"
 };


int ev_12_total = 16;  /* # of elements in array */
char *ev_12[16] = {
       "ev_12_1","ev_12_2","ev_12_3","ev_12_4","ev_12_5","ev_12_6",
       "ev_12_7","ev_12_8","ev_12_9","ev_12_10","ev_12_11","ev_12_12",
       "ev_12_13","ev_12_14","ev_12_15","ev_12_16"
 };



       int ev_13_total = 16;  /* # of elements in array */
char *ev_13[16] = {
       "ev_13_1","ev_13_2","ev_13_3","ev_13_4","ev_13_5","ev_13_6",
       "ev_13_7","ev_13_8","ev_13_9","ev_13_10","ev_13_11","ev_13_12",
       "ev_13_13","ev_13_14","ev_13_15","ev_13_16"
 };


int ev_14_total = 16;  /* # of elements in array */
char *ev_14[16] = {
       "ev_14_1","ev_14_2","ev_14_3","ev_14_4","ev_14_5","ev_14_6",
       "ev_14_7","ev_14_8","ev_14_9","ev_14_10","ev_14_11","ev_14_12",
       "ev_14_13","ev_14_14","ev_14_15","ev_14_16"
 };


int ev_15_total = 16;  /* # of elements in array */
char *ev_15[16] = {
       "ev_15_1","ev_15_2","ev_15_3","ev_15_4","ev_15_5","ev_15_6",
       "ev_15_7","ev_15_8","ev_15_9","ev_15_10","ev_15_11","ev_15_12",
       "ev_15_13","ev_15_14","ev_15_15","ev_15_16"
 };


int ev_16_total = 16;  /* # of elements in array */
char *ev_16[16] = {
       "ev_16_1","ev_16_2","ev_16_3","ev_16_4","ev_16_5","ev_16_6",
       "ev_16_7","ev_16_8","ev_16_9","ev_16_10","ev_16_11","ev_16_12",
       "ev_16_13","ev_16_14","ev_16_15","ev_16_16"
 };



       int ev_19_total = 16;  /* # of elements in array */
char *ev_19[16] = {
       "ev_19_1","ev_19_2","ev_19_3","ev_19_4","ev_19_5","ev_19_6",
       "ev_19_7","ev_19_8","ev_19_9","ev_19_10","ev_19_11","ev_19_12",
       "ev_19_13","ev_19_14","ev_19_15","ev_19_16"
 };


int ev_24_total = 16;  /* # of elements in array */
char *ev_24[16] = {
       "ev_24_1","ev_24_2","ev_24_3","ev_24_4","ev_24_5","ev_24_6",
       "ev_24_7","ev_24_8","ev_24_9","ev_24_10","ev_24_11","ev_24_12",
       "ev_24_13","ev_24_14","ev_24_15","ev_24_16"
 };



       int ev_25_total = 16;  /* # of elements in array */
char *ev_25[16] = {
       "ev_25_1","ev_25_2","ev_25_3","ev_25_4","ev_25_5","ev_25_6",
       "ev_25_7","ev_25_8","ev_25_9","ev_25_10","ev_25_11","ev_25_12",
       "ev_25_13","ev_25_14","ev_25_15","ev_25_16"
 };


int ev_26_total = 16;  /* # of elements in array */
char *ev_26[16] = {
       "ev_26_1","ev_26_2","ev_26_3","ev_26_4","ev_26_5","ev_26_6",
       "ev_26_7","ev_26_8","ev_26_9","ev_26_10","ev_26_11","ev_26_12",
       "ev_26_13","ev_26_14","ev_26_15","ev_26_16"
 };


int ev_27_total = 16;  /* # of elements in array */
char *ev_27[16] = {
       "ev_27_1","ev_27_2","ev_27_3","ev_27_4","ev_27_5","ev_27_6",
       "ev_27_7","ev_27_8","ev_27_9","ev_27_10","ev_27_11","ev_27_12",
       "ev_27_13","ev_27_14","ev_27_15","ev_27_16"
 };


int ev_28_total = 16;  /* # of elements in array */
char *ev_28[16] = {
       "ev_28_1","ev_28_2","ev_28_3","ev_28_4","ev_28_5","ev_28_6",
       "ev_28_7","ev_28_8","ev_28_9","ev_28_10","ev_28_11","ev_28_12",
       "ev_28_13","ev_28_14","ev_28_15","ev_28_16"
 };


int ev_29_total = 16;  /* # of elements in array */
char *ev_29[16] = {
       "ev_29_1","ev_29_2","ev_29_3","ev_29_4","ev_29_5","ev_29_6",
       "ev_29_7","ev_29_8","ev_29_9","ev_29_10","ev_29_11","ev_29_12",
       "ev_29_13","ev_29_14","ev_29_15","ev_29_16"
 };


int ev_30_total = 16;  /* # of elements in array */
char *ev_30[16] = {
       "ev_30_1","ev_30_2","ev_30_3","ev_30_4","ev_30_5","ev_30_6",
       "ev_30_7","ev_30_8","ev_30_9","ev_30_10","ev_30_11","ev_30_12",
       "ev_30_13","ev_30_14","ev_30_15","ev_30_16"
 };



       int ev_31_total = 16;  /* # of elements in array */
char *ev_31[16] = {
       "ev_31_1","ev_31_2","ev_31_3","ev_31_4","ev_31_5","ev_31_6",
       "ev_31_7","ev_31_8","ev_31_9","ev_31_10","ev_31_11","ev_31_12",
       "ev_31_13","ev_31_14","ev_31_15","ev_31_16"
 };


char **event_names[32] = {ev_syn,
       ev_key,ev_rel,ev_abs,ev_msc,ev_5,ev_6,
       ev_7,ev_8,ev_9,ev_10,ev_11,ev_12,
       ev_13,ev_14,ev_15,ev_16,ev_led,ev_snd,
       ev_19,ev_rep,ev_ff,ev_pwr,ev_ff_status,ev_24,
       ev_25,ev_26,ev_27,ev_28,ev_29,ev_30,ev_31
 };
