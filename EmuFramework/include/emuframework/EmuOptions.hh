#pragma once

/*  This file is part of EmuFramework.

	Imagine is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Imagine is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with EmuFramework.  If not, see <http://www.gnu.org/licenses/> */

#include <emuframework/Option.hh>
#include <emuframework/EmuSystem.hh>
#include <imagine/bluetooth/BluetoothAdapter.hh>
#include <imagine/audio/Audio.hh>

extern Byte1Option optionAutoSaveState;
extern Byte1Option optionConfirmAutoLoadState;
extern Byte1Option optionSound;
#ifdef CONFIG_AUDIO_LATENCY_HINT
	#if defined CONFIG_AUDIO_ALSA || defined CONFIG_AUDIO_OPENSL_ES || defined CONFIG_AUDIO_PULSEAUDIO
	// these backends may have additional buffering in the OS/driver
	static constexpr uint OPTION_SOUND_BUFFERS_MIN = 2;
	#else
	static constexpr uint OPTION_SOUND_BUFFERS_MIN = 3;
	#endif
extern Byte1Option optionSoundBuffers;
#endif
#if defined CONFIG_AUDIO_OPENSL_ES && !defined CONFIG_MACHINE_OUYA
#define EMU_FRAMEWORK_STRICT_UNDERRUN_CHECK_OPTION
extern OptionAudioHintStrictUnderrunCheck optionSoundUnderrunCheck;
#endif
#ifdef CONFIG_AUDIO_MANAGER_SOLO_MIX
using OptionAudioSoloMix = Option<OptionMethodFunc<bool, AudioManager::soloMix, AudioManager::setSoloMix>, uint8>;
extern OptionAudioSoloMix optionAudioSoloMix;
#endif
extern Byte4Option optionSoundRate;
extern Byte2Option optionFontSize;
extern Byte1Option optionVibrateOnPush;
extern Byte1Option optionPauseUnfocused;
extern Byte1Option optionNotificationIcon;
extern Byte1Option optionTitleBar;
extern OptionBackNavigation optionBackNavigation;
extern Byte1Option optionRememberLastMenu;
extern Byte1Option optionLowProfileOSNav;
extern Byte1Option optionHideOSNav;
extern Byte1Option optionIdleDisplayPowerSave;
extern Byte1Option optionHideStatusBar;
extern OptionSwappedGamepadConfirm optionSwappedGamepadConfirm;
extern Byte1Option optionConfirmOverwriteState;
extern Byte1Option optionFastForwardSpeed;
#ifdef CONFIG_INPUT_DEVICE_HOTSWAP
extern Byte1Option optionNotifyInputDeviceChange;
#endif
#ifdef CONFIG_INPUT_ANDROID_MOGA
extern Byte1Option optionMOGAInputSystem;
#endif

#ifdef CONFIG_BLUETOOTH
extern Byte1Option optionKeepBluetoothActive;
extern Byte1Option optionShowBluetoothScan;
	#ifdef CONFIG_BLUETOOTH_SCAN_CACHE_USAGE
	extern OptionBlueToothScanCache optionBlueToothScanCache;
	#endif
#endif

extern Byte1Option optionImgFilter;
extern OptionAspectRatio optionAspectRatio;
#ifdef CONFIG_GFX_OPENGL_SHADER_PIPELINE
extern Byte1Option optionImgEffect;
extern Byte1Option optionImageEffectPixelFormat;
#endif
extern Byte1Option optionOverlayEffect;
extern Byte1Option optionOverlayEffectLevel;

#ifdef CONFIG_INPUT_RELATIVE_MOTION_DEVICES
static const uint optionRelPointerDecelLow = 500, optionRelPointerDecelMed = 250, optionRelPointerDecelHigh = 125;
extern Byte4Option optionRelPointerDecel;
#endif

extern Byte4s1Option optionGameOrientation;
extern Byte4s1Option optionMenuOrientation;

#ifdef CONFIG_VCONTROLS_GAMEPAD
extern Byte1Option optionTouchCtrl;
extern Byte4s2Option optionTouchCtrlSize;
extern Byte4s2Option optionTouchDpadDeadzone;
extern Byte4s2Option optionTouchDpadDiagonalSensitivity;
extern Byte4s2Option optionTouchCtrlBtnSpace;
extern Byte4s2Option optionTouchCtrlBtnStagger;
extern Byte1Option optionTouchCtrlTriggerBtnPos;
extern Byte4s2Option optionTouchCtrlExtraXBtnSize;
extern Byte4s2Option optionTouchCtrlExtraYBtnSize;
extern Byte4s2Option optionTouchCtrlExtraYBtnSizeMultiRow;
extern Byte1Option optionTouchCtrlBoundingBoxes;
extern Byte1Option optionTouchCtrlShowOnTouch;
	#if defined(CONFIG_BASE_ANDROID)
	extern OptionTouchCtrlScaledCoordinates optionTouchCtrlScaledCoordinates;
	#endif
#endif
extern Byte1Option optionTouchCtrlAlpha;
extern OptionVControllerLayoutPosition optionVControllerLayoutPos;

#if defined CONFIG_BASE_SCREEN_FRAME_INTERVAL
extern Byte1Option optionFrameInterval;
#endif
extern Byte1Option optionSkipLateFrames;
extern DoubleOption optionFrameRate;
extern DoubleOption optionFrameRatePAL;
extern DoubleOption optionRefreshRateOverride;

static const uint optionImageZoomIntegerOnly = 255, optionImageZoomIntegerOnlyY = 254;
extern Byte1Option optionImageZoom;
extern Byte1Option optionViewportZoom;
extern Byte1Option optionShowOnSecondScreen;

extern OptionRecentGames optionRecentGames;

#ifdef __ANDROID__
static constexpr uint8 OPTION_ANDROID_TEXTURE_STORAGE_AUTO = 0;
static constexpr uint8 OPTION_ANDROID_TEXTURE_STORAGE_NONE = 1;
static constexpr uint8 OPTION_ANDROID_TEXTURE_STORAGE_GRAPHIC_BUFFER = 2;
static constexpr uint8 OPTION_ANDROID_TEXTURE_STORAGE_SURFACE_TEXTURE = 3;
static constexpr uint8 OPTION_ANDROID_TEXTURE_STORAGE_MAX_VALUE = OPTION_ANDROID_TEXTURE_STORAGE_SURFACE_TEXTURE;
extern Byte1Option optionAndroidTextureStorage;
Gfx::Texture::AndroidStorageImpl makeAndroidStorageImpl(uint8 val);
extern SByte1Option optionProcessPriority;
extern Byte1Option optionFakeUserActivity;
#endif

extern Byte1Option optionDitherImage;

#ifdef EMU_FRAMEWORK_WINDOW_PIXEL_FORMAT_OPTION
extern Byte1Option optionWindowPixelFormat;
#endif

static const char *optionSavePathDefaultToken = ":DEFAULT:";
extern PathOption optionSavePath;
extern PathOption optionLastLoadPath;
extern Byte1Option optionCheckSavePathWriteAccess;

extern Byte1Option optionShowBundledGames;

// Common options handled per-emulator backend
extern PathOption optionFirmwarePath;

void initOptions();
void setupFont(Gfx::Renderer &r);
