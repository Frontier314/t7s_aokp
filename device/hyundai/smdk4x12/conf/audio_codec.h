/*
** Copyright 2008, The Android Open-Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef ANDROID_AUDIO_CODEC_H
#define ANDROID_AUDIO_CODEC_H

// wm8994-path.c should be changed together
// zsb, 0: direct setting codec registers          
// zsb, 1: use kcontrol and dapm widget to set codec 			 
// DAPM struture does not deal with RCV path, but meizu does
#define USE_DAPM_AUDIO	1

namespace android_audio_legacy {

typedef struct AudioMixer_tag {
    const char *ctl;
    const int   val;
} AudioMixer;

// ----------------------------------------------------------------------------
//  codec mixer settings
//  : These settings depend on your sound codec driver.
//  : You have to modify.

#if (USE_DAPM_AUDIO == 1)
const AudioMixer device_out_SPK[] = { //playback_speaker
//path
    {"AIF1DACL Source", 0},		//Left DAC receive left channel
    {"AIF1DACR Source", 1},		//Right DAC receive right channel
    {"AIF1DAC Mux", 0},			//AIF1DAC, select AIF1DACDAT
    {"DAC1L Mixer AIF1.1 Switch", 1},	//AIF1DAC1L --> DAC1L Mixer
    {"DAC1R Mixer AIF1.1 Switch", 1},	//AIF1DAC1R --> DAC1R Mixer
    {"SPKL DAC1 Switch", 1},		//DAC1L --> SPKL
    {"SPKR DAC1 Switch", 1},		//DAC1R --> SPKR
    {"SPKL Boost SPKL Switch", 1},	//SPKL --> SPKL Boost
    {"SPKR Boost SPKR Switch", 1},	//SPKR --> SPKR Bootst
//gain
    {"Headphone Switch", 0},		//HPOUT PGA mute
    {"Speaker Mode", 0},		//Class D
    {"Speaker ZC Switch", 0},		//disable ZC
    {"Speaker Volume", 60},		//SPK volume, +3dB 
    {"Speaker Boost Volume", 4},	//2.0x boost, +6.0dB
    {"Speaker Mixer Volume", 3},	//SPK Mixer Volume 0dB
    {"Speaker Switch", 1},		//SPK OUTPUT PGA unmute
    {"DAC1 Volume", 96},		//DAC1 Volume, 0dB
    {"DAC1 Switch", 1},			//DAC1 Switch, unmute
    {"AIF1DAC1 Volume", 96},		//AIF1DAC1 Input Volume, 0dB
    {NULL, 0}
};
const AudioMixer device_out_RCV[] = {	// TC4 has no receiver
    {NULL, NULL}
};
const AudioMixer device_out_RING_SPK[] = { //playback_speaker
//path
    {"AIF1DACL Source", 0},		//Left DAC receive left channel
    {"AIF1DACR Source", 1},		//Right DAC receive right channel
    {"AIF1DAC Mux", 0},			//AIF1DAC, select AIF1DACDAT
    {"DAC1L Mixer AIF1.1 Switch", 1},	//AIF1DAC1L --> DAC1L Mixer
    {"DAC1R Mixer AIF1.1 Switch", 1},	//AIF1DAC1R --> DAC1R Mixer
    {"SPKL DAC1 Switch", 1},		//DAC1L --> SPKL
    {"SPKR DAC1 Switch", 1},		//DAC1R --> SPKR
    {"SPKL Boost SPKL Switch", 1},	//SPKL --> SPKL Boost
    {"SPKR Boost SPKR Switch", 1},	//SPKR --> SPKR Bootst
//gain
    {"Headphone Switch", 0},		//HPOUT PGA mute
    {"Speaker Mode", 0},		//Class D
    {"Speaker ZC Switch", 0},		//disable ZC
    {"Speaker Volume", 60},		//SPK volume, +3dB 
    {"Speaker Boost Volume", 4},	//2.0x boost, +6.0dB
    {"Speaker Mixer Volume", 3},	//SPK Mixer Volume 0dB
    {"Speaker Switch", 1},		//SPK OUTPUT PGA unmute
    {"DAC1 Volume", 96},		//DAC1 Volume, 0dB
    {"DAC1 Switch", 1},			//DAC1 Switch, unmute
    {"AIF1DAC1 Volume", 96},		//AIF1DAC1 Input Volume, 0dB
    {NULL, 0}
};
const AudioMixer device_out_RING_NO_MIC[] = {
    {NULL, NULL}
};
const AudioMixer device_out_HP_NO_MIC[] = {
    {NULL, NULL}
};
const AudioMixer device_out_RING_HP[] = { //playback_headphone
    {"AIF1DACL Source", 0},		//Left DAC receive left channel
    {"AIF1DACR Source", 1},		//Right DAC receive right channel
    {"AIF1DAC Mux", 0},			//AIF1DAC, select AIF1DACDAT
    {"DAC1L Mixer AIF1.1 Switch", 1},	//AIF1DAC1L --> DAC1L Mixer
    {"DAC1R Mixer AIF1.1 Switch", 1},	//AIF1DAC1R --> DAC1R Mixer
    {"Left Headphone Mux", 1},		//DACL --> Headphone Mux
    {"Right Headphone Mux", 1},		//DACR --> Headphone Mux

    {"Speaker Switch", 0},		//SPK OUTPUT PGA mute
    {"Headphone ZC Switch", 0},		//ZC disable
    {"Headphone Volume", 63},		//HPOUT Volume, +6dB
    {"Headphone Switch", 1},		//HPOUT PGA unmute
    {"DAC1 Volume", 96},		//DAC1 Volume, 0dB
    {"DAC1 Switch", 1},			//DAC1 Switch, unmute
    {"AIF1DAC1 Volume", 96},		//AIF1DAC1 Input Volume, 0dB
    {NULL, 0}
};
const AudioMixer device_out_HP[] = { //playback_headphone
    {"AIF1DACL Source", 0},		//Left DAC receive left channel
    {"AIF1DACR Source", 1},		//Right DAC receive right channel
    {"AIF1DAC Mux", 0},			//AIF1DAC, select AIF1DACDAT
    {"DAC1L Mixer AIF1.1 Switch", 1},	//AIF1DAC1L --> DAC1L Mixer
    {"DAC1R Mixer AIF1.1 Switch", 1},	//AIF1DAC1R --> DAC1R Mixer
    {"Left Headphone Mux", 1},		//DACL --> Headphone Mux
    {"Right Headphone Mux", 1},		//DACR --> Headphone Mux

    {"Speaker Switch", 0},		//SPK OUTPUT PGA mute
    {"Headphone ZC Switch", 0},		//ZC disable
    {"Headphone Volume", 63},		//HPOUT Volume, +6dB
    {"Headphone Switch", 1},		//HPOUT PGA unmute
    {"DAC1 Volume", 96},		//DAC1 Volume, 0dB
    {"DAC1 Switch", 1},			//DAC1 Switch, unmute
    {"AIF1DAC1 Volume", 96},		//AIF1DAC1 Input Volume, 0dB
    {NULL, 0}
};
const AudioMixer device_out_RING_SPK_HP[] = {
//path
    {"AIF1DACL Source", 0},		//Left DAC receive left channel
    {"AIF1DACR Source", 1},		//Right DAC receive right channel
    {"AIF1DAC Mux", 0},			//AIF1DAC, select AIF1DACDAT
    {"DAC1L Mixer AIF1.1 Switch", 1},	//AIF1DAC1L --> DAC1L Mixer
    {"DAC1R Mixer AIF1.1 Switch", 1},	//AIF1DAC1R --> DAC1R Mixer
    {"SPKL DAC1 Switch", 1},		//DAC1L --> SPKL
    {"SPKR DAC1 Switch", 1},		//DAC1R --> SPKR
    {"SPKL Boost SPKL Switch", 1},	//SPKL --> SPKL Boost
    {"SPKR Boost SPKR Switch", 1},	//SPKR --> SPKR Bootst
    {"Left Headphone Mux", 1},		//DACL --> Headphone Mux
    {"Right Headphone Mux", 1},		//DACR --> Headphone Mux
//gain
    {"Speaker Mode", 0},		//Class D
    {"Speaker ZC Switch", 0},		//disable ZC
    {"Speaker Volume", 60},		//SPK volume, +3dB 
    {"Speaker Boost Volume", 4},	//2.0x boost, +6.0dB
    {"Speaker Mixer Volume", 3},	//SPK Mixer Volume 0dB
    {"Speaker Switch", 1},		//SPK OUTPUT PGA unmute
    {"DAC1 Volume", 96},		//DAC1 Volume, 0dB
    {"DAC1 Switch", 1},			//DAC1 Switch, unmute
    {"AIF1DAC1 Volume", 96},		//AIF1DAC1 Input Volume, 0dB
    {"Headphone ZC Switch", 0},		//ZC disable
    {"Headphone Volume", 63},		//HPOUT Volume, +6dB
    {"Headphone Switch", 1},		//HPOUT PGA unmute
    {"DAC1 Volume", 96},		//DAC1 Volume, 0dB
    {"DAC1 Switch", 1},			//DAC1 Switch, unmute
    {"AIF1DAC1 Volume", 96},		//AIF1DAC1 Input Volume, 0dB
    {NULL, 0}
};
const AudioMixer device_out_SPK_HP[] = {
//path
    {"AIF1DACL Source", 0},		//Left DAC receive left channel
    {"AIF1DACR Source", 1},		//Right DAC receive right channel
    {"AIF1DAC Mux", 0},			//AIF1DAC, select AIF1DACDAT
    {"DAC1L Mixer AIF1.1 Switch", 1},	//AIF1DAC1L --> DAC1L Mixer
    {"DAC1R Mixer AIF1.1 Switch", 1},	//AIF1DAC1R --> DAC1R Mixer
    {"SPKL DAC1 Switch", 1},		//DAC1L --> SPKL
    {"SPKR DAC1 Switch", 1},		//DAC1R --> SPKR
    {"SPKL Boost SPKL Switch", 1},	//SPKL --> SPKL Boost
    {"SPKR Boost SPKR Switch", 1},	//SPKR --> SPKR Bootst
    {"Left Headphone Mux", 1},		//DACL --> Headphone Mux
    {"Right Headphone Mux", 1},		//DACR --> Headphone Mux
//gain
    {"Speaker Mode", 0},		//Class D
    {"Speaker ZC Switch", 0},		//disable ZC
    {"Speaker Volume", 60},		//SPK volume, +3dB 
    {"Speaker Boost Volume", 4},	//2.0x boost, +6.0dB
    {"Speaker Mixer Volume", 3},	//SPK Mixer Volume 0dB
    {"Speaker Switch", 1},		//SPK OUTPUT PGA unmute
    {"DAC1 Volume", 96},		//DAC1 Volume, 0dB
    {"DAC1 Switch", 1},			//DAC1 Switch, unmute
    {"AIF1DAC1 Volume", 96},		//AIF1DAC1 Input Volume, 0dB
    {"Headphone ZC Switch", 0},		//ZC disable
    {"Headphone Volume", 63},		//HPOUT Volume, +6dB
    {"Headphone Switch", 1},		//HPOUT PGA unmute
    {"DAC1 Volume", 96},		//DAC1 Volume, 0dB
    {"DAC1 Switch", 1},			//DAC1 Switch, unmute
    {"AIF1DAC1 Volume", 96},		//AIF1DAC1 Input Volume, 0dB
    {NULL, 0}
};
const AudioMixer device_out_BT[] = {
    {NULL, NULL}
};
const AudioMixer device_out_OFF[] = {
    {NULL, NULL}
};

//wenpin.cui: Voice call, don't solve at master branch
const AudioMixer device_voice_RCV[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_SPK[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_TTY_VCO[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_TTY_HCO[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_TTY_FULL[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_HP_NO_MIC[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_HP[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_BT[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_OFF[] = {
    {NULL, NULL}
};
const AudioMixer device_input_Main_Mic[] = {
//path
    {"IN1L PGA IN1LP Switch", 1},		//IN1LP --> IN1L PGA
    {"IN1L PGA IN1LN Switch", 1},		//IN1LN --> IN1L PGA
    {"MIXINL IN1L Switch", 1},			//IN1L PGA --> MIXINL
    {"ADCL Mux", 0},				//ADCL Mux, select ADCL
    {"AIF1ADC1L Mixer ADC/DMIC Switch", 1},	//ADCL Mux --> AIF1ADCL Mixer
    {"AIF1ADCL Source", 0},			//AIF1ADCL Source: Left
    {"AIF1ADCR Source", 0},			//AIF1ADCR Source: Left
//gain
    {"MIXINR IN1R Switch", 0},			//IN1R PGA !-> MIXINR
    {"IN1R Switch", 0},
    {"IN1L ZC Switch", 0},			//change gain immediately
    {"IN1L Volume", 11},			//IN1L Volume, 0dB
    {"IN1L Switch", 1},				//IN1L unmute
    {"MIXINL IN1L Volume", 1},			//IN1L to MIXINL Gain, 30dB   
    {"AIF1ADC1 Volume", 96},			//AIF1ADC1 Volume, 0dB
    {NULL, 0}
};
const AudioMixer device_input_Hands_Free_Mic[] = {
//path
    {"IN1R PGA IN1RP Switch", 1},		//IN1RP --> IN1R PGA
    {"IN1R PGA IN1RN Switch", 1},		//IN1RN --> IN1R PGA
    {"MIXINR IN1R Switch", 1},			//IN1R PGA --> MIXINR
    {"ADCR Mux", 0},				//ADCR Mux, select ADCR
    {"AIF1ADC1R Mixer ADC/DMIC Switch", 1},	//ADCR Mux --> AIF1ADCR Mixer
    {"AIF1ADCL Source", 1},			//AIF1ADCL Source: Right
    {"AIF1ADCR Source", 1},			//AIF1ADCR Source: Right
//gain
    {"MIXINL IN1L Switch", 0},			//IN1L PGA !-> MIXINL
    {"IN1L Switch", 0},
    {"IN1R ZC Switch", 0},			//change gain immediately
    {"IN1R Volume", 11},			//IN1R Volume, 0dB
    {"IN1R Switch", 1},				//IN1R unmute
    {"MIXINR IN1R Volume", 1},			//IN1R to MIXINR Gain, 30dB   
    {"AIF1ADC1 Volume", 96},			//AIF1ADC1 Volume, 0dB
    {NULL, 0}
};
const AudioMixer device_input_BT_Sco_Mic[] = {
    {NULL, NULL}
};
const AudioMixer device_input_MIC_OFF[] = {
    {NULL, NULL}
};

#else // USE_DAPM_AUDIO = 0
//
//  Playback_path Selection { None=0, Speaker Nomal=1, Headphone Nomal=2, Receiver Nomal=3, 
//	Spk_Hp Nomal=4, Speaker incall=5, Headset incall=6, Receiver incall=7, Spk_Hs incall=8, 
//	Speaker ringtone=9, Headphone ringtone=10, Receiver ringtone=11, Spk_Hp ringtone=12, 
//	Headphone incall=13, Spk_Hp incall=14 }
/***************************************************************************************/
/** Directly set codec registers                                                      **/
/***************************************************************************************/

const AudioMixer device_out_SPK[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 1},
    {NULL, NULL}
};
const AudioMixer device_out_RCV[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 1},
    {NULL, NULL}
};
const AudioMixer device_out_RING_SPK[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 1},
    {NULL, NULL}
};
const AudioMixer device_out_RING_NO_MIC[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 1},
    {NULL, NULL}
};
const AudioMixer device_out_HP_NO_MIC[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 2},
    {NULL, NULL}
};
const AudioMixer device_out_RING_HP[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 2},
    {NULL, NULL}
};
const AudioMixer device_out_HP[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 2},
    {NULL, NULL}
};
const AudioMixer device_out_RING_SPK_HP[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 4},
    {NULL, NULL}
};
const AudioMixer device_out_SPK_HP[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 4},
    {NULL, NULL}
};
const AudioMixer device_out_BT[] = {
    {NULL, NULL}
};
const AudioMixer device_out_OFF[] = {
    {"Capture_path Selection", 0},		//yyd- 120202
    {"Playback_path Selection", 0},
    {NULL, NULL}
};

//  Playback_path Selection { None=0, Speaker Nomal=1, Headphone Nomal=2, Receiver Nomal=3, 
//	Spk_Hp Nomal=4, Speaker incall=5, Headset incall=6, Receiver incall=7, Spk_Hs incall=8, 
//	Speaker ringtone=9, Headphone ringtone=10, Receiver ringtone=11, Spk_Hp ringtone=12, 
//	Headphone incall=13, Spk_Hp incall=14 }

const AudioMixer device_voice_RCV[] = {
    {"Playback_path Selection", 5},
    {NULL, NULL}
};
const AudioMixer device_voice_SPK[] = {		// zsb add
    {"Playback_path Selection", 5},
    {NULL, NULL}
};
const AudioMixer device_voice_TTY_VCO[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_TTY_HCO[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_TTY_FULL[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_HP_NO_MIC[] = {
    {NULL, NULL}
};
const AudioMixer device_voice_HP[] = {		// zsb add
    {"Playback_path Selection", 13},
    {NULL, NULL}
};
const AudioMixer device_voice_BT[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 15},		// BT incall = 15
    {NULL, NULL}
};
const AudioMixer device_voice_OFF[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 0},
    {NULL, NULL}
};


//  Capture_path Selection { None=0, Main_Mic Nomal=1, Sencond_Mic Nomal=2, Hand_Mic Nomal=3, 
//	Main_Mic incall=4, Sencond_Mic incall=5, Hand_Mic incall=6 }

const AudioMixer device_input_Main_Mic[] = {
    {"Capture_path Selection", 1},
    {"Playback_path Selection", 0},
    {NULL, NULL}
};
const AudioMixer device_input_Hands_Free_Mic[] = {
    {"Capture_path Selection", 3},
    {"Playback_path Selection", 0},
    {NULL, NULL}
};
const AudioMixer device_input_BT_Sco_Mic[] = {
    {NULL, NULL}
};
const AudioMixer device_input_MIC_OFF[] = {
    {"Capture_path Selection", 0},
    {"Playback_path Selection", 0},	// yyd- 120202
    {NULL, NULL}
};

#endif // USE_DAPM_AUDIO
}; // namespace android

#endif //ANDROID_AUDIO_CODEC_H
