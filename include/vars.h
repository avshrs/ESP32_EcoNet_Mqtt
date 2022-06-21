#pragma once
#include "Arduino.h"


struct __attribute__((packed)) Ecomax_920_Frame_Header{
    uint8_t frame_begine;  	// 0
    short frame_size;       // 1
    uint8_t dst_address;    // 3
    uint8_t src_address;    // 4
    uint8_t nn_5;           // 5
    uint8_t nn_6;           // 6
    uint8_t payload_type;   // 7
};

struct __attribute__((packed)) Ecomax_920_Live_Data_Frame_payload{
    uint8_t nn_0 = 0;
    uint8_t nn_1 = 0;
    uint8_t nn_2 = 0;
    uint8_t nn_3 = 0;
    uint8_t nn_4 = 0;
    uint8_t nn_5 = 0;
    uint8_t nn_6 = 0;
    uint8_t nn_7 = 0;
    uint8_t nn_8 = 0;
    uint8_t nn_9 = 0;
    uint8_t nn_10 = 0;
    uint8_t nn_11 = 0;
    uint8_t nn_12 = 0;
    uint8_t nn_13 = 0;
    uint8_t nn_14 = 0;
    uint8_t nn_15 = 0;
    uint8_t nn_16 = 0;
    uint8_t nn_17 = 0;
    uint8_t nn_18 = 0;
    uint8_t nn_19 = 0;
    uint8_t nn_20 = 0;
    uint8_t nn_21 = 0;
    uint8_t nn_22 = 0;
    uint8_t nn_23 = 0;
    uint8_t nn_24 = 0;
    uint8_t nn_25 = 0;
    uint8_t nn_26 = 0;
    uint8_t nn_27 = 0;
    uint8_t nn_28 = 0;
    uint8_t operating_status = 0; //29
    uint8_t nn_30 = 0;
    uint8_t nn_31 = 0;
    uint8_t nn_32 = 0;
    uint8_t nn_33 = 0;
    uint8_t nn_34 = 0;
    uint8_t nn_35 = 0;
    uint8_t nn_36 = 0;
    uint8_t nn_37 = 0;
    uint8_t nn_38 = 0;
    uint8_t nn_39 = 0;
    uint8_t nn_40 = 0;
    uint8_t nn_41 = 0;
    uint8_t nn_42 = 0;
    uint8_t nn_43 = 0;
    uint8_t nn_44 = 0;
    uint8_t nn_45 = 0;
    uint8_t nn_46 = 0;
    uint8_t nn_47 = 0;
    uint8_t nn_48 = 0;
    uint8_t nn_49 = 0;
    uint8_t nn_50 = 0;
    uint8_t nn_51 = 0;
    uint8_t nn_52 = 0;
    uint8_t nn_53 = 0;
    uint8_t nn_54 = 0;
    uint8_t nn_55 = 0;
    uint8_t nn_56 = 0;
    uint8_t nn_57 = 0;
    uint8_t nn_58 = 0;
    uint8_t nn_59 = 0;
    uint8_t nn_60 = 0;
    uint8_t nn_61 = 0;
    uint8_t nn_62 = 0;
    uint8_t nn_63 = 0;
    uint8_t nn_64 = 0;
    uint8_t nn_65 = 0;
    uint8_t nn_66 = 0;
    uint8_t nn_67 = 0;
    uint8_t nn_68 = 0;
    uint8_t nn_69 = 0;
    uint8_t nn_70 = 0;
    uint8_t nn_71 = 0;
    uint8_t nn_72 = 0;
    uint8_t nn_73 = 0;
    uint8_t nn_74 = 0;
    uint8_t nn_75 = 0;
    uint8_t nn_76 = 0;
    uint8_t nn_77 = 0;
    float huw_temp = 0;   // 78



    float mixer_temp = 0;  // 82



    float weather_temp = 0;  //86



    float boiler_return_temp = 0; // 90 



    float exhaust_temp = 0;   // 94 



    float feeder_temp = 0;  // 98



    float boiler_temp = 0;  // 102



    float flame_sensor = 0;  // 106



    float upper_buffer_temp = 0;  // 110 



    float lower_buffer_temp = 0;  // 114  



    uint8_t nn_118 = 0;  
    uint8_t nn_119 = 0;
    uint8_t nn_120 = 0;
    uint8_t nn_121 = 0; 
    uint8_t nn_122 = 0;
    uint8_t nn_123 = 0;
    uint8_t nn_124 = 0;
    uint8_t nn_125 = 0;
    uint8_t nn_126 = 0;
    uint8_t nn_127 = 0;
    uint8_t nn_128 = 0;
    uint8_t nn_129 = 0;
    uint8_t nn_130 = 0;
    uint8_t nn_131 = 0;
    uint8_t nn_132 = 0;
    uint8_t nn_133 = 0;
    uint8_t nn_134 = 0;
    uint8_t nn_135 = 0;
    uint8_t nn_136 = 0;
    uint8_t nn_137 = 0;
    uint8_t nn_138 = 0;
    uint8_t nn_139 = 0;
    uint8_t nn_140 = 0;
    uint8_t nn_141 = 0;
    uint8_t nn_142 = 0;
    uint8_t nn_143 = 0;
    uint8_t nn_144 = 0;
    uint8_t nn_145 = 0;
    uint8_t nn_146 = 0;
    uint8_t nn_147 = 0;
    uint8_t nn_148 = 0;
    uint8_t nn_149 = 0;
    uint8_t nn_150 = 0;
    uint8_t nn_151 = 0;
    uint8_t nn_152 = 0;
    uint8_t nn_153 = 0;
    uint8_t nn_154 = 0;
    uint8_t nn_155 = 0;
    uint8_t nn_156 = 0;
    uint8_t nn_157 = 0;
    uint8_t nn_158 = 0;
    uint8_t nn_159 = 0;
    uint8_t nn_160 = 0;
    uint8_t nn_161 = 0;
    uint8_t nn_162 = 0;
    uint8_t nn_163 = 0;
    uint8_t nn_164 = 0;
    uint8_t nn_165 = 0;
    uint8_t huw_temp_target = 0;  // 166
    uint8_t mixer_temp_target = 0;  // 167
    uint8_t nn_168 = 0;
    uint8_t nn_169 = 0;
    uint8_t nn_170 = 0;
    uint8_t nn_171 = 0;
    uint8_t boiler_temp_target = 0; // 172
    uint8_t nn_173 = 0;
    uint8_t nn_174 = 0;
    uint8_t nn_175 = 0;
    uint8_t nn_176 = 0;
    uint8_t nn_177 = 0;
    uint8_t nn_178 = 0;
    uint8_t nn_179 = 0;
    uint8_t nn_180 = 0;
    uint8_t nn_181 = 0;
    uint8_t nn_182 = 0;
    uint8_t nn_183 = 0;
    uint8_t nn_184 = 0;
    uint8_t nn_185 = 0;
    uint8_t nn_186 = 0;
    uint8_t nn_187 = 0;
    uint8_t nn_188 = 0;
    uint8_t nn_189 = 0;
    uint8_t nn_190 = 0;
    uint8_t nn_191 = 0;
    uint8_t nn_192 = 0;
    uint8_t nn_193 = 0;
    uint8_t nn_194 = 0;
    uint8_t huw_pomp_state = 0;  // 195
    uint8_t nn_196 = 0;
    uint8_t nn_197 = 0;
    uint8_t nn_198 = 0;
    uint8_t nn_199 = 0;
    uint8_t nn_200 = 0;
    uint8_t nn_201 = 0;
    uint8_t nn_202 = 0;
    uint8_t nn_203 = 0;
    uint8_t nn_204 = 0;
    uint8_t nn_205 = 0;
    uint8_t nn_206 = 0;
    uint8_t nn_207 = 0;
    uint8_t nn_208 = 0;
    uint8_t nn_209 = 0;
    uint8_t nn_210 = 0;
    uint8_t nn_211 = 0;
    uint8_t nn_212 = 0;
    uint8_t nn_213 = 0;
    uint8_t nn_214 = 0;
    uint8_t nn_215 = 0;
    uint8_t nn_216 = 0;
    uint8_t fuel_level = 0; // 217
    uint8_t nn_218 = 0;
    uint8_t nn_219 = 0;
    uint8_t nn_220 = 0;
    uint8_t nn_221 = 0;
    uint8_t nn_222 = 0;
    uint8_t nn_223 = 0;
    uint8_t nn_224 = 0;
    uint8_t nn_225 = 0;
    uint8_t nn_226 = 0;
    uint8_t nn_227 = 0;
    uint8_t nn_228 = 0;
    uint8_t nn_229 = 0;
    uint8_t nn_230 = 0;
    uint8_t nn_231 = 0;
    uint8_t nn_232 = 0;
    uint8_t nn_233 = 0;
    uint8_t nn_234 = 0;
    uint8_t nn_235 = 0;
    uint8_t nn_236 = 0;
    uint8_t nn_237 = 0;
    uint8_t nn_238 = 0;
    uint8_t nn_239 = 0;
    uint8_t nn_240 = 0;
    uint8_t nn_241 = 0;
    uint8_t nn_242 = 0;
    uint8_t nn_243 = 0;
    uint8_t nn_244 = 0;
    uint8_t nn_245 = 0;
    uint8_t nn_246 = 0;
    uint8_t nn_247 = 0;
    uint8_t nn_248 = 0;
    uint8_t nn_249 = 0;
    uint8_t nn_250 = 0;
    uint8_t nn_251 = 0;
    uint8_t nn_252 = 0;
    uint8_t nn_253 = 0;
    uint8_t fan_in_power = 0; 	// 254
    uint8_t fan_out_power = 0;  // 255 
    float boiler_power_kw= 0;	// 256 



    float fuel_stream = 0;  	// 260



    uint8_t nn_264 = 0;
    uint8_t boiler_pomp_state = 0; // 265
    uint16_t power_max_time = 0;   // 266 	

    uint16_t power_medium_time = 0;  // 268

    uint16_t power_min_time = 0;   // 270

    uint16_t feeder_time = 0;      // 272

    uint16_t ignitions = 0;	   // 274

    uint16_t ignitions_fails = 0;  // 276

    uint8_t nn_278 = 0; 
    uint8_t nn_279 = 0;
    uint8_t nn_280 = 0;
    uint8_t nn_281 = 0;
    uint8_t nn_282 = 0;
    uint8_t nn_283 = 0;
    uint8_t nn_284 = 0;
    uint8_t nn_285 = 0;
    uint8_t nn_286 = 0;
    uint8_t nn_287 = 0;
    uint8_t nn_288 = 0;
    uint8_t nn_289 = 0;
    uint8_t nn_290 = 0;
    uint8_t nn_291 = 0;
    uint8_t nn_292 = 0;
    uint8_t nn_293 = 0;
    uint8_t nn_294 = 0;
    uint8_t nn_295 = 0;
    uint8_t nn_296 = 0;
    uint8_t nn_297 = 0;
    uint8_t nn_298 = 0;
    uint8_t nn_299 = 0;
    uint8_t nn_300 = 0;
    uint8_t nn_301 = 0;
    uint8_t nn_302 = 0;
    uint8_t nn_303 = 0;
    uint8_t nn_304 = 0;
    uint8_t nn_305 = 0;
    uint8_t nn_306 = 0;
    uint8_t nn_307 = 0;
    uint8_t nn_308 = 0;
    uint8_t nn_309 = 0;
    uint8_t nn_310 = 0;
    uint8_t nn_311 = 0;
    uint8_t nn_312 = 0;
    uint8_t nn_313 = 0;
    uint8_t nn_314 = 0;
    uint8_t nn_315 = 0;
    uint8_t nn_316 = 0;
    uint8_t nn_317 = 0;
    uint8_t nn_318 = 0;
    uint8_t nn_319 = 0;
    uint8_t nn_320 = 0;
    uint8_t nn_321 = 0;
    uint8_t frame_crc = 0;
    uint8_t frame_end_signature = 0;
    };



struct __attribute__((packed)) Ecoster_Live_Data_Frame_payload{
    uint8_t nn_0 = 0;
    uint8_t nn_1 = 0;
    uint8_t nn_2 = 0;
    uint8_t nn_3 = 0;
    uint8_t nn_4 = 0;
    uint8_t nn_5 = 0;
    uint8_t nn_6 = 0;
    uint8_t nn_7 = 0;
    uint8_t nn_8 = 0;
    uint8_t nn_9 = 0;
    uint8_t nn_10 = 0;
    uint8_t nn_11 = 0;
    uint8_t nn_12 = 0;
    uint8_t nn_13 = 0;
    uint8_t nn_14 = 0;
    uint8_t nn_15 = 0;
    float room_thermostat_temp_target = 0;
    float room_thermostat_home_temp = 0;
    float room_thermostat_ecoster_1_temp = 0;
    float room_thermostat_ecoster_2_temp = 0;
    uint8_t nn_32 = 0;
    uint8_t nn_33 = 0;
    uint8_t nn_34 = 0;
    uint8_t nn_35 = 0;
    uint8_t nn_36 = 0;
    uint8_t nn_37 = 0;
    uint8_t nn_38 = 0;
    uint8_t nn_39 = 0;
    uint8_t nn_40 = 0;
    uint8_t nn_41 = 0;
    uint8_t nn_42 = 0;
    uint8_t nn_43 = 0;
    uint8_t nn_44 = 0;
    uint8_t nn_45 = 0;
    uint8_t nn_46 = 0;
    uint8_t nn_47 = 0;
    uint8_t nn_48 = 0;
    uint8_t nn_49 = 0;
    uint8_t nn_50 = 0;
    uint8_t nn_51 = 0;
    uint8_t nn_52 = 0;
};






































struct __attribute__((packed)) Ecoster_Settings_Frame_payload{
    uint8_t nn_0 = 0;
    uint8_t nn_1 = 0;
    uint8_t nn_2 = 0;
    uint8_t room_thermostat_operating_mode = 0;
    uint8_t nn_4 = 0;
    uint8_t nn_5 = 0;
    uint8_t nn_6 = 0;
    uint8_t nn_7 = 0;
    uint8_t nn_8 = 0;
    uint8_t room_thermostat_party_temp = 0;
    uint8_t nn_10 = 0;
    uint8_t nn_11 = 0;
    uint8_t nn_12 = 0;
    uint8_t nn_13 = 0;
    uint8_t nn_14 = 0;
    uint8_t room_thermostat_holiday_temp = 0;
    uint8_t nn_16 = 0;
    uint8_t nn_17 = 0;
    uint8_t nn_18 = 0;
    uint8_t nn_19 = 0;
    uint8_t nn_20 = 0;
    uint8_t room_thermostat_out_of_house_duration = 0;
    uint8_t nn_22 = 0;
    uint8_t nn_23 = 0;
    uint8_t room_thermostat_ventilation_duration = 0;
    uint8_t nn_25 = 0;
    uint8_t nn_26 = 0;
    uint8_t room_thermostat_party_duration = 0;
    uint8_t nn_28 = 0;
    uint8_t nn_29 = 0;
    uint8_t room_thermostat_holiday_duration = 0;
    uint8_t nn_31 = 0;
    uint8_t nn_32 = 0;
    uint8_t room_thermostat_hysteresis = 0;
    uint8_t nn_34 = 0;
    uint8_t nn_35 = 0;
    uint8_t room_thermostat_day_temp_int = 0;
    uint8_t nn_37 = 0;
    uint8_t nn_38 = 0;
    uint8_t room_thermostat_day_temp_fract = 0;
    uint8_t nn_40 = 0;
    uint8_t nn_41 = 0;
    uint8_t room_thermostat_night_temp_int = 0;
    uint8_t nn_43 = 0;
    uint8_t nn_44 = 0;
    uint8_t room_thermostat_night_temp_fract = 0;
    uint8_t nn_46 = 0;
    uint8_t nn_47 = 0;
    uint8_t nn_48 = 0;
    uint8_t nn_49 = 0;
    uint8_t nn_50 = 0;
    uint8_t room_thermostat_antifreeze_temp = 0;
    uint8_t nn_52 = 0;
    uint8_t nn_53 = 0;
    uint8_t nn_54 = 0;
    uint8_t nn_55 = 0;
    uint8_t nn_56 = 0;
    uint8_t nn_57 = 0;
    uint8_t nn_58 = 0;
    uint8_t nn_59 = 0;
    uint8_t nn_60 = 0;
    uint8_t nn_61 = 0;
    uint8_t nn_62 = 0;
    uint8_t nn_63 = 0;
    uint8_t nn_64 = 0;
    uint8_t nn_65 = 0;
    uint8_t nn_66 = 0;
    uint8_t nn_67 = 0;
    uint8_t nn_68 = 0;
    uint8_t nn_69 = 0;
    uint8_t nn_70 = 0;
    uint8_t nn_71 = 0;
    uint8_t nn_72 = 0;
    uint8_t nn_73 = 0;
    uint8_t nn_74 = 0;
    uint8_t nn_75 = 0;
    uint8_t nn_76 = 0;
    uint8_t nn_77 = 0;
    uint8_t nn_78 = 0;
    uint8_t nn_79 = 0;
    uint8_t nn_80 = 0;
    uint8_t nn_81 = 0;
    uint8_t nn_82 = 0;
    uint8_t nn_83 = 0;
    uint8_t nn_84 = 0;
    uint8_t nn_85 = 0;
    uint8_t nn_86 = 0;
    uint8_t nn_87 = 0;
    uint8_t nn_88 = 0;
    uint8_t nn_89 = 0;
    uint8_t nn_90 = 0;
    uint8_t nn_91 = 0;
    uint8_t nn_92 = 0;
    uint8_t nn_93 = 0;
    uint8_t nn_94 = 0;
    uint8_t nn_95 = 0;
    uint8_t nn_96 = 0;
    uint8_t nn_97 = 0;
    uint8_t nn_98 = 0;
    uint8_t nn_99 = 0;
    uint8_t nn_100 = 0;
    uint8_t nn_101 = 0;
    uint8_t nn_102 = 0;
    uint8_t nn_103 = 0;
    uint8_t nn_104 = 0;
    uint8_t nn_105 = 0;
    uint8_t nn_106 = 0;
    uint8_t nn_107 = 0;
    uint8_t nn_108 = 0;
    uint8_t nn_109 = 0;
    uint8_t nn_110 = 0;
    uint8_t nn_111 = 0;
    uint8_t nn_112 = 0;
    uint8_t nn_113 = 0;
    uint8_t nn_114 = 0;
    uint8_t nn_115 = 0;
    uint8_t nn_116 = 0;
    uint8_t nn_117 = 0;
    uint8_t nn_118 = 0;
    uint8_t nn_119 = 0;
    uint8_t nn_120 = 0;
    uint8_t nn_121 = 0; 
    uint8_t nn_122 = 0;
    uint8_t nn_123 = 0;
    uint8_t nn_124 = 0;
    uint8_t nn_125 = 0;
    uint8_t nn_126 = 0;
    uint8_t nn_127 = 0;
    uint8_t nn_128 = 0;
    uint8_t nn_129 = 0;
    uint8_t nn_130 = 0;
    uint8_t nn_131 = 0;
    uint8_t nn_132 = 0;
    uint8_t nn_133 = 0;
    uint8_t nn_134 = 0;
    uint8_t nn_135 = 0;
    uint8_t nn_136 = 0;
    uint8_t nn_137 = 0;
    uint8_t nn_138 = 0;
    uint8_t nn_139 = 0;
    uint8_t nn_140 = 0;
    uint8_t nn_141 = 0;
    uint8_t nn_142 = 0;
    uint8_t nn_143 = 0;
    uint8_t nn_144 = 0;
    uint8_t nn_145 = 0;
    uint8_t nn_146 = 0;
    uint8_t nn_147 = 0;
    uint8_t nn_148 = 0;
    uint8_t nn_149 = 0;
    uint8_t nn_150 = 0;
    uint8_t nn_151 = 0;
    uint8_t nn_152 = 0;
    uint8_t nn_153 = 0;
    uint8_t nn_154 = 0;
    uint8_t nn_155 = 0;
    uint8_t frame_crc = 0;
    uint8_t frame_end_signature = 0;
};


struct EcoNet_cfg
{
    String serial_file;
    int boudrate;
    int remove_lead_zero;
};
struct __attribute__((packed)) Ecoster_payload
{
    float home_temp_target = 0; 
    float home_temp = 0;
    float ecoster_1_temp = 0;
    float ecoster_2_temp = 0;
};
struct Mqtt_config
{
    String ClientId;
    String ServerIp;
    String username;
    String password;
    int serverPort;
    String keepAliveTopic;
    String keepAliveMsg;
    String Substring;
    String Pubstring;
};

struct __attribute__((packed)) Ecomax_settings_Frame_payload{
    uint8_t nn_0 = 0;
    uint8_t nn_1 = 0;
    uint8_t boiler_max_power_kw = 0;
    uint8_t nn_3 = 0;
    uint8_t nn_4 = 0;
    uint8_t boiler_mid_power_kw = 0;
    uint8_t nn_6 = 0;
    uint8_t nn_7 = 0;
    uint8_t boiler_min_power_kw = 0;
    uint8_t nn_9 = 0;
    uint8_t nn_10 = 0;
    uint8_t boiler_max_power_fan = 0;
    uint8_t nn_12 = 0;
    uint8_t nn_13 = 0;
    uint8_t boiler_mid_power_fan = 0;
    uint8_t nn_15 = 0;
    uint8_t nn_16 = 0;
    uint8_t boiler_min_power_fan = 0;
    uint8_t nn_18 = 0;
    uint8_t nn_19 = 0;
    uint8_t nn_20 = 0;
    uint8_t nn_21 = 0;
    uint8_t nn_22 = 0;
    uint8_t nn_23 = 0;
    uint8_t nn_24 = 0;
    uint8_t nn_25 = 0;
    uint8_t nn_26 = 0;
    uint8_t nn_27 = 0;
    uint8_t nn_28 = 0;
    uint8_t nn_29 = 0;
    uint8_t nn_30 = 0;
    uint8_t nn_31 = 0;
    uint8_t nn_32 = 0;
    uint8_t nn_33 = 0;
    uint8_t nn_34 = 0;
    uint8_t nn_35 = 0;
    uint8_t nn_36 = 0;
    uint8_t nn_37 = 0;
    uint8_t nn_38 = 0;
    uint8_t nn_39 = 0;
    uint8_t nn_40 = 0;
    uint8_t nn_41 = 0;
    uint8_t nn_42 = 0;
    uint8_t nn_43 = 0;
    uint8_t nn_44 = 0;
    uint8_t nn_45 = 0;
    uint8_t nn_46 = 0;
    uint8_t nn_47 = 0;
    uint8_t nn_48 = 0;
    uint8_t nn_49 = 0;
    uint8_t nn_50 = 0;
    uint8_t nn_51 = 0;
    uint8_t nn_52 = 0;
    uint8_t nn_53 = 0;
    uint8_t nn_54 = 0;
    uint8_t nn_55 = 0;
    uint8_t nn_56 = 0;
    uint8_t nn_57 = 0;
    uint8_t nn_58 = 0;
    uint8_t nn_59 = 0;
    uint8_t nn_60 = 0;
    uint8_t nn_61 = 0;
    uint8_t nn_62 = 0;
    uint8_t nn_63 = 0;
    uint8_t nn_64 = 0;
    uint8_t nn_65 = 0;
    uint8_t nn_66 = 0;
    uint8_t nn_67 = 0;
    uint8_t nn_68 = 0;
    uint8_t nn_69 = 0;
    uint8_t nn_70 = 0;
    uint8_t nn_71 = 0;
    uint8_t nn_72 = 0;
    uint8_t nn_73 = 0;
    uint8_t nn_74 = 0;
    uint8_t nn_75 = 0;
    uint8_t nn_76 = 0;
    uint8_t nn_77 = 0;
    uint8_t nn_78 = 0;
    uint8_t nn_79 = 0;
    uint8_t nn_80 = 0;
    uint8_t nn_81 = 0;
    uint8_t nn_82 = 0;
    uint8_t nn_83 = 0;
    uint8_t nn_84 = 0;
    uint8_t nn_85 = 0;
    uint8_t nn_86 = 0;
    uint8_t nn_87 = 0;
    uint8_t nn_88 = 0;
    uint8_t nn_89 = 0;
    uint8_t nn_90 = 0;
    uint8_t nn_91 = 0;
    uint8_t nn_92 = 0;
    uint8_t nn_93 = 0;
    uint8_t nn_94 = 0;
    uint8_t nn_95 = 0;
    uint8_t nn_96 = 0;
    uint8_t nn_97 = 0;
    uint8_t nn_98 = 0;
    uint8_t nn_99 = 0;
    uint8_t nn_100 = 0;
    uint8_t nn_101 = 0;
    uint8_t nn_102 = 0;
    uint8_t nn_103 = 0;
    uint8_t nn_104 = 0;
    uint8_t nn_105 = 0;
    uint8_t nn_106 = 0;
    uint8_t nn_107 = 0;
    uint8_t nn_108 = 0;
    uint8_t nn_109 = 0;
    uint8_t nn_110 = 0;
    uint8_t nn_111 = 0;
    uint8_t nn_112 = 0;
    uint8_t nn_113 = 0;
    uint8_t nn_114 = 0;
    uint8_t nn_115 = 0;
    uint8_t nn_116 = 0;
    uint8_t nn_117 = 0;
    uint8_t nn_118 = 0;
    uint8_t nn_119 = 0;
    uint8_t nn_120 = 0;
    uint8_t nn_121 = 0;
    uint8_t nn_122 = 0;
    uint8_t nn_123 = 0;
    uint8_t nn_124 = 0;
    uint8_t nn_125 = 0;
    uint8_t nn_126 = 0;
    uint8_t nn_127 = 0;
    uint8_t nn_128 = 0;
    uint8_t nn_129 = 0;
    uint8_t nn_130 = 0;
    uint8_t nn_131 = 0;
    uint8_t nn_132 = 0;
    uint8_t nn_133 = 0;
    uint8_t nn_134 = 0;
    uint8_t nn_135 = 0;
    uint8_t nn_136 = 0;
    uint8_t nn_137 = 0;
    uint8_t nn_138 = 0;
    uint8_t nn_139 = 0;
    uint8_t feeder_efficiency = 0;
    uint8_t nn_141 = 0;
    uint8_t nn_142 = 0;
    uint8_t nn_143 = 0;
    uint8_t nn_144 = 0;
    uint8_t nn_145 = 0;
    uint8_t nn_146 = 0;
    uint8_t nn_147 = 0;
    uint8_t nn_148 = 0;
    uint8_t nn_149 = 0;
    uint8_t nn_150 = 0;
    uint8_t nn_151 = 0;
    uint8_t nn_152 = 0;
    uint8_t nn_153 = 0;
    uint8_t nn_154 = 0;
    uint8_t nn_155 = 0;
    uint8_t nn_156 = 0;
    uint8_t nn_157 = 0;
    uint8_t boiler_temp_target = 0;
    uint8_t nn_159 = 0;
    uint8_t nn_160 = 0;
    uint8_t nn_161 = 0;
    uint8_t nn_162 = 0;
    uint8_t nn_163 = 0;
    uint8_t nn_164 = 0;
    uint8_t nn_165 = 0;
    uint8_t nn_166 = 0;
    uint8_t huw_temp_target = 0;
    uint8_t nn_168 = 0;
    uint8_t nn_169 = 0;
    uint8_t nn_170 = 0;
    uint8_t nn_171 = 0;
    uint8_t nn_172 = 0;
    uint8_t nn_173 = 0;
    uint8_t nn_174 = 0;
    uint8_t nn_175 = 0;
    uint8_t huw_mode = 0;
    uint8_t nn_177 = 0;
    uint8_t nn_178 = 0;
    uint8_t huw_temp_hysteresis = 0;
    uint8_t nn_180 = 0;
    uint8_t nn_181 = 0;
    uint8_t huw_container_disinfection = 0;
    uint8_t nn_183 = 0;
    uint8_t nn_184 = 0;
    uint8_t nn_185 = 0;
    uint8_t nn_186 = 0;
    uint8_t nn_187 = 0;
    uint8_t boiler_summer_winter_mode = 0;
    uint8_t nn_189 = 0;
    uint8_t nn_190 = 0;
    uint8_t nn_191 = 0;
    uint8_t nn_192 = 0;
    uint8_t nn_193 = 0;
    uint8_t nn_194 = 0;
    uint8_t nn_195 = 0;
    uint8_t nn_196 = 0;
    uint8_t nn_197 = 0;
    uint8_t nn_198 = 0;
    uint8_t nn_199 = 0;
    uint8_t nn_200 = 0;
    uint8_t nn_201 = 0;
    uint8_t nn_202 = 0;
    uint8_t nn_203 = 0;
    uint8_t nn_204 = 0;
    uint8_t nn_205 = 0;
    uint8_t nn_206 = 0;
    uint8_t nn_207 = 0;
    uint8_t nn_208 = 0;
    uint8_t nn_209 = 0;
    uint8_t nn_210 = 0;
    uint8_t nn_211 = 0;
    uint8_t nn_212 = 0;
    uint8_t nn_213 = 0;
    uint8_t nn_214 = 0;
    uint8_t nn_215 = 0;
    uint8_t nn_216 = 0;
    uint8_t nn_217 = 0;
    uint8_t mixer_temp_target = 0;
    uint8_t nn_219 = 0;
    uint8_t nn_220 = 0;
    uint8_t nn_221 = 0;
    uint8_t nn_222 = 0;
    uint8_t nn_223 = 0;
    uint8_t nn_224 = 0;
    uint8_t nn_225 = 0;
    uint8_t nn_226 = 0;
    uint8_t nn_227 = 0;
    uint8_t nn_228 = 0;
    uint8_t nn_229 = 0;
    uint8_t nn_230 = 0;
    uint8_t nn_231 = 0;
    uint8_t nn_232 = 0;
    uint8_t nn_233 = 0;
    uint8_t nn_234 = 0;
    uint8_t nn_235 = 0;
    uint8_t nn_236 = 0;
    uint8_t nn_237 = 0;
    uint8_t nn_238 = 0;
    uint8_t nn_239 = 0;
    uint8_t nn_240 = 0;
    uint8_t nn_241 = 0;
    uint8_t nn_242 = 0;
    uint8_t nn_243 = 0;
    uint8_t nn_244 = 0;
    uint8_t nn_245 = 0;
    uint8_t nn_246 = 0;
    uint8_t nn_247 = 0;
    uint8_t nn_248 = 0;
    uint8_t nn_249 = 0;
    uint8_t nn_250 = 0;
    uint8_t nn_251 = 0;
    uint8_t nn_252 = 0;
    uint8_t nn_253 = 0;
    uint8_t nn_254 = 0;
    uint8_t nn_255 = 0;
    uint8_t nn_256 = 0;
    uint8_t nn_257 = 0;
    uint8_t nn_258 = 0;
    uint8_t nn_259 = 0;
    uint8_t nn_260 = 0;
    uint8_t nn_261 = 0;
    uint8_t nn_262 = 0;
    uint8_t nn_263 = 0;
    uint8_t nn_264 = 0;
    uint8_t nn_265 = 0;
    uint8_t nn_266 = 0;
    uint8_t nn_267 = 0;
    uint8_t nn_268 = 0;
    uint8_t nn_269 = 0;
    uint8_t nn_270 = 0;
    uint8_t nn_271 = 0;
    uint8_t nn_272 = 0;
    uint8_t nn_273 = 0;
    uint8_t nn_274 = 0;
    uint8_t nn_275 = 0;
    uint8_t nn_276 = 0;
    uint8_t nn_277 = 0;
    uint8_t nn_278 = 0;
    uint8_t nn_279 = 0;
    uint8_t nn_280 = 0;
    uint8_t nn_281 = 0;
    uint8_t nn_282 = 0;
    uint8_t nn_283 = 0;
    uint8_t nn_284 = 0;
    uint8_t nn_285 = 0;
    uint8_t nn_286 = 0;
    uint8_t nn_287 = 0;
    uint8_t nn_288 = 0;
    uint8_t nn_289 = 0;
    uint8_t nn_290 = 0;
    uint8_t nn_291 = 0;
    uint8_t nn_292 = 0;
    uint8_t nn_293 = 0;
    uint8_t nn_294 = 0;
    uint8_t nn_295 = 0;
    uint8_t nn_296 = 0;
    uint8_t nn_297 = 0;
    uint8_t nn_298 = 0;
    uint8_t nn_299 = 0;
    uint8_t nn_300 = 0;
    uint8_t nn_301 = 0;
    uint8_t nn_302 = 0;
    uint8_t nn_303 = 0;
    uint8_t nn_304 = 0;
    uint8_t nn_305 = 0;
    uint8_t nn_306 = 0;
    uint8_t nn_307 = 0;
    uint8_t nn_308 = 0;
    uint8_t nn_309 = 0;
    uint8_t nn_310 = 0;
    uint8_t nn_311 = 0;
    uint8_t nn_312 = 0;
    uint8_t nn_313 = 0;
    uint8_t nn_314 = 0;
    uint8_t nn_315 = 0;
    uint8_t nn_316 = 0;
    uint8_t nn_317 = 0;
    uint8_t nn_318 = 0;
    uint8_t nn_319 = 0;
    uint8_t nn_320 = 0;
    uint8_t nn_321 = 0;
    uint8_t nn_322 = 0;
    uint8_t nn_323 = 0;
    uint8_t nn_324 = 0;
    uint8_t nn_325 = 0;
    uint8_t nn_326 = 0;
    uint8_t nn_327 = 0;
    uint8_t nn_328 = 0;
    uint8_t nn_329 = 0;
    uint8_t nn_330 = 0;
    uint8_t nn_331 = 0;
    uint8_t nn_332 = 0;
    uint8_t nn_333 = 0;
    uint8_t nn_334 = 0;
    uint8_t nn_335 = 0;
    uint8_t nn_336 = 0;
    uint8_t nn_337 = 0;
    uint8_t nn_338 = 0;
    uint8_t nn_339 = 0;
    uint8_t nn_340 = 0;
    uint8_t nn_341 = 0;
    uint8_t nn_342 = 0;
    uint8_t nn_343 = 0;
    uint8_t nn_344 = 0;
    uint8_t nn_345 = 0;
    uint8_t nn_346 = 0;
    uint8_t nn_347 = 0;
    uint8_t nn_348 = 0;
    uint8_t nn_349 = 0;
    uint8_t nn_350 = 0;
    uint8_t nn_351 = 0;
    uint8_t nn_352 = 0;
    uint8_t nn_353 = 0;
    uint8_t nn_354 = 0;
    uint8_t nn_355 = 0;
    uint8_t nn_356 = 0;
    uint8_t nn_357 = 0;
    uint8_t nn_358 = 0;
    uint8_t nn_359 = 0;
    uint8_t nn_360 = 0;
    uint8_t nn_361 = 0;
    uint8_t nn_362 = 0;
    uint8_t nn_363 = 0;
    uint8_t nn_364 = 0;
    uint8_t nn_365 = 0;
    uint8_t nn_366 = 0;
    uint8_t nn_367 = 0;
    uint8_t nn_368 = 0;
    uint8_t nn_369 = 0;
    uint8_t nn_370 = 0;
    uint8_t nn_371 = 0;
    uint8_t nn_372 = 0;
    uint8_t nn_373 = 0;
    uint8_t nn_374 = 0;
    uint8_t nn_375 = 0;
    uint8_t nn_376 = 0;
    uint8_t nn_377 = 0;
    uint8_t nn_378 = 0;
    uint8_t nn_379 = 0;
    uint8_t nn_380 = 0;
    uint8_t nn_381 = 0;
    uint8_t nn_382 = 0;
    uint8_t nn_383 = 0;
    uint8_t nn_384 = 0;
    uint8_t nn_385 = 0;
    uint8_t nn_386 = 0;
    uint8_t nn_387 = 0;
    uint8_t nn_388 = 0;
    uint8_t nn_389 = 0;
    uint8_t nn_390 = 0;
    uint8_t nn_391 = 0;
    uint8_t nn_392 = 0;
    uint8_t nn_393 = 0;
    uint8_t nn_394 = 0;
    uint8_t nn_395 = 0;
    uint8_t nn_396 = 0;
    uint8_t nn_397 = 0;
    uint8_t nn_398 = 0;
    uint8_t nn_399 = 0;
    uint8_t nn_400 = 0;
    uint8_t nn_401 = 0;
    uint8_t nn_402 = 0;
    uint8_t nn_403 = 0;
    uint8_t nn_404 = 0;
    uint8_t nn_405 = 0;
    uint8_t nn_406 = 0;
    uint8_t nn_407 = 0;
    uint8_t nn_408 = 0;
    uint8_t nn_409 = 0;
    uint8_t nn_410 = 0;
    uint8_t nn_411 = 0;
    uint8_t nn_412 = 0;
    uint8_t nn_413 = 0;
    uint8_t nn_414 = 0;
    uint8_t nn_415 = 0;
    uint8_t nn_416 = 0;
    uint8_t nn_417 = 0;
    uint8_t nn_418 = 0;
    uint8_t nn_419 = 0;
    uint8_t nn_420 = 0;
    uint8_t nn_421 = 0;
    uint8_t nn_422 = 0;
    uint8_t nn_423 = 0;
    uint8_t nn_424 = 0;
    uint8_t nn_425 = 0;
    uint8_t nn_426 = 0;
    uint8_t nn_427 = 0;
    uint8_t nn_428 = 0;
    uint8_t nn_429 = 0;
    uint8_t nn_430 = 0;
    uint8_t nn_431 = 0;
    uint8_t nn_432 = 0;
    uint8_t nn_433 = 0;
    uint8_t nn_434 = 0;
    uint8_t nn_435 = 0;
    uint8_t nn_436 = 0;
    uint8_t nn_437 = 0;
    uint8_t nn_438 = 0;
    uint8_t nn_439 = 0;
    uint8_t nn_440 = 0;
    uint8_t nn_441 = 0;
    uint8_t nn_442 = 0;
    uint8_t nn_443 = 0;
    uint8_t nn_444 = 0;
    uint8_t nn_445 = 0;
    uint8_t nn_446 = 0;
    uint8_t nn_447 = 0;
    uint8_t nn_448 = 0;
    uint8_t nn_449 = 0;
    uint8_t nn_450 = 0;
    uint8_t nn_451 = 0;
    uint8_t mixer_room_temp_factor = 0;
    uint8_t nn_453 = 0;
    uint8_t nn_454 = 0;
    uint8_t nn_455 = 0;
    uint8_t nn_456 = 0;
    uint8_t nn_457 = 0;
    uint8_t nn_458 = 0;
    uint8_t nn_459 = 0;
    uint8_t nn_460 = 0;
    uint8_t nn_461 = 0;
    uint8_t nn_462 = 0;
    uint8_t nn_463 = 0;
    uint8_t nn_464 = 0;
    uint8_t nn_465 = 0;
    uint8_t nn_466 = 0;
    uint8_t nn_467 = 0;
    uint8_t nn_468 = 0;
    uint8_t nn_469 = 0;
    uint8_t nn_470 = 0;
    uint8_t nn_471 = 0;
    uint8_t nn_472 = 0;
    uint8_t nn_473 = 0;
    uint8_t nn_474 = 0;
    uint8_t nn_475 = 0;
    uint8_t nn_476 = 0;
    uint8_t nn_477 = 0;
    uint8_t nn_478 = 0;
    uint8_t nn_479 = 0;
    uint8_t nn_480 = 0;
    uint8_t nn_481 = 0;
    uint8_t nn_482 = 0;
    uint8_t nn_483 = 0;
    uint8_t nn_484 = 0;
    uint8_t nn_485 = 0;
    uint8_t nn_486 = 0;
    uint8_t nn_487 = 0;
    uint8_t nn_488 = 0;
    uint8_t nn_489 = 0;
    uint8_t nn_490 = 0;
    uint8_t nn_491 = 0;
    uint8_t nn_492 = 0;
    uint8_t nn_493 = 0;
    uint8_t nn_494 = 0;
    uint8_t nn_495 = 0;
    uint8_t nn_496 = 0;
    uint8_t nn_497 = 0;
    uint8_t nn_498 = 0;
    uint8_t nn_499 = 0;
    uint8_t nn_500 = 0;
    uint8_t nn_501 = 0;
    uint8_t nn_502 = 0;
    uint8_t nn_503 = 0;
    uint8_t nn_504 = 0;
    uint8_t nn_505 = 0;
    uint8_t nn_506 = 0;
    uint8_t nn_507 = 0;
    uint8_t nn_508 = 0;
    uint8_t nn_509 = 0;
    uint8_t nn_510 = 0;
    uint8_t nn_511 = 0;
    uint8_t nn_512 = 0;
    uint8_t nn_513 = 0;
    uint8_t nn_514 = 0;
    uint8_t nn_515 = 0;
    uint8_t nn_516 = 0;
    uint8_t nn_517 = 0;
    uint8_t nn_518 = 0;
    uint8_t nn_519 = 0;
    uint8_t nn_520 = 0;
    uint8_t nn_521 = 0;
    uint8_t nn_522 = 0;
    uint8_t nn_523 = 0;
    uint8_t nn_524 = 0;
    uint8_t nn_525 = 0;
    uint8_t nn_526 = 0;
    uint8_t nn_527 = 0;
    uint8_t nn_528 = 0;
    uint8_t nn_529 = 0;
    uint8_t nn_530 = 0;
    uint8_t nn_531 = 0;
    uint8_t nn_532 = 0;
    uint8_t nn_533 = 0;
    uint8_t nn_534 = 0;
    uint8_t nn_535 = 0;
    uint8_t nn_536 = 0;
    uint8_t nn_537 = 0;
    uint8_t nn_538 = 0;
    uint8_t nn_539 = 0;
    uint8_t nn_540 = 0;
    uint8_t nn_541 = 0;
    uint8_t nn_542 = 0;
    uint8_t nn_543 = 0;
    uint8_t nn_544 = 0;
    uint8_t nn_545 = 0;
    uint8_t nn_546 = 0;
    uint8_t nn_547 = 0;
    uint8_t nn_548 = 0;
    uint8_t nn_549 = 0;
    uint8_t nn_550 = 0;
    uint8_t nn_551 = 0;
    uint8_t nn_552 = 0;
    uint8_t nn_553 = 0;
    uint8_t nn_554 = 0;
    uint8_t nn_555 = 0;
    uint8_t nn_556 = 0;
    uint8_t nn_557 = 0;
    uint8_t nn_558 = 0;
    uint8_t nn_559 = 0;
    uint8_t nn_560 = 0;
    uint8_t nn_561 = 0;
    uint8_t nn_562 = 0;
    uint8_t nn_563 = 0;
    uint8_t nn_564 = 0;
    uint8_t nn_565 = 0;
    uint8_t nn_566 = 0;
    uint8_t nn_567 = 0;
    uint8_t nn_568 = 0;
    uint8_t nn_569 = 0;
    uint8_t nn_570 = 0;
    uint8_t nn_571 = 0;
    uint8_t nn_572 = 0;
    uint8_t nn_573 = 0;
    uint8_t nn_574 = 0;
    uint8_t nn_575 = 0;
    uint8_t nn_576 = 0;
    uint8_t nn_577 = 0;
    uint8_t nn_578 = 0;
    uint8_t nn_579 = 0;
    uint8_t nn_580 = 0;
    uint8_t nn_581 = 0;
    uint8_t nn_582 = 0;
    uint8_t nn_583 = 0;
    uint8_t nn_584 = 0;
    uint8_t nn_585 = 0;
    uint8_t nn_586 = 0;
    uint8_t nn_587 = 0;
    uint8_t nn_588 = 0;
    uint8_t nn_589 = 0;
    uint8_t nn_590 = 0;
    uint8_t nn_591 = 0;
    uint8_t nn_592 = 0;
    uint8_t nn_593 = 0;
    uint8_t nn_594 = 0;
    uint8_t nn_595 = 0;
    uint8_t nn_596 = 0;
    uint8_t nn_597 = 0;
    uint8_t nn_598 = 0;
    uint8_t nn_599 = 0;
    uint8_t nn_600 = 0;
    uint8_t nn_601 = 0;
    uint8_t nn_602 = 0;
    uint8_t nn_603 = 0;
    uint8_t nn_604 = 0;
    uint8_t nn_605 = 0;
    uint8_t nn_606 = 0;
    uint8_t nn_607 = 0;
    uint8_t nn_608 = 0;
    uint8_t nn_609 = 0;
    uint8_t nn_610 = 0;
    uint8_t nn_611 = 0;
    uint8_t nn_612 = 0;
    uint8_t nn_613 = 0;
    uint8_t nn_614 = 0;
    uint8_t nn_615 = 0;
    uint8_t nn_616 = 0;
    uint8_t nn_617 = 0;
    uint8_t nn_618 = 0;
    uint8_t nn_619 = 0;
    uint8_t nn_620 = 0;
    uint8_t nn_621 = 0;
    uint8_t nn_622 = 0;
    uint8_t nn_623 = 0;
    uint8_t nn_624 = 0;
    uint8_t nn_625 = 0;
    uint8_t nn_626 = 0;
    uint8_t nn_627 = 0;
    uint8_t nn_628 = 0;
    uint8_t nn_629 = 0;
    uint8_t nn_630 = 0;
    uint8_t nn_631 = 0;
    uint8_t nn_632 = 0;
    uint8_t nn_633 = 0;
    uint8_t nn_634 = 0;
    uint8_t nn_635 = 0;
    uint8_t nn_636 = 0;
    uint8_t nn_637 = 0;
    uint8_t nn_638 = 0;
    uint8_t nn_639 = 0;
    uint8_t nn_640 = 0;
    uint8_t nn_641 = 0;
    uint8_t nn_642 = 0;
    uint8_t nn_643 = 0;
    uint8_t nn_644 = 0;
    uint8_t nn_645 = 0;
    uint8_t nn_646 = 0;
    uint8_t nn_647 = 0;
    uint8_t nn_648 = 0;
    uint8_t nn_649 = 0;
    uint8_t nn_650 = 0;
    uint8_t nn_651 = 0;
    uint8_t nn_652 = 0;
    uint8_t nn_653 = 0;
    uint8_t nn_654 = 0;
    uint8_t nn_655 = 0;
    uint8_t nn_656 = 0;
    uint8_t nn_657 = 0;
    uint8_t nn_658 = 0;
    uint8_t nn_659 = 0;
    uint8_t frame_crc = 0;
    uint8_t frame_end_signature = 0;
};