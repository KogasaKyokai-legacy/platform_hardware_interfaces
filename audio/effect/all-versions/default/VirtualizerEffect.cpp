/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "Virtualizer_HAL"

#include "VirtualizerEffect.h"

#include <memory.h>
#include <stdlib.h>

#include <HidlUtils.h>
#include <android/log.h>
#include <system/audio_effects/effect_virtualizer.h>

#include "VersionUtils.h"

namespace android {
namespace hardware {
namespace audio {
namespace effect {
namespace CPP_VERSION {
namespace implementation {

using ::android::hardware::audio::common::COMMON_TYPES_CPP_VERSION::implementation::HidlUtils;

VirtualizerEffect::VirtualizerEffect(effect_handle_t handle)
    : mEffect(new Effect(false /*isInput*/, handle)) {}

// Methods from ::android::hardware::audio::effect::CPP_VERSION::IEffect follow.
Return<Result> VirtualizerEffect::init() {
    return mEffect->init();
}

Return<Result> VirtualizerEffect::setConfig(
    const EffectConfig& config, const sp<IEffectBufferProviderCallback>& inputBufferProvider,
    const sp<IEffectBufferProviderCallback>& outputBufferProvider) {
    return mEffect->setConfig(config, inputBufferProvider, outputBufferProvider);
}

Return<Result> VirtualizerEffect::reset() {
    return mEffect->reset();
}

Return<Result> VirtualizerEffect::enable() {
    return mEffect->enable();
}

Return<Result> VirtualizerEffect::disable() {
    return mEffect->disable();
}

#if MAJOR_VERSION <= 6
Return<Result> VirtualizerEffect::setAudioSource(AudioSource source) {
    return mEffect->setAudioSource(source);
}

Return<Result> VirtualizerEffect::setDevice(AudioDeviceBitfield device) {
    return mEffect->setDevice(device);
}

Return<Result> VirtualizerEffect::setInputDevice(AudioDeviceBitfield device) {
    return mEffect->setInputDevice(device);
}
#else
Return<Result> VirtualizerEffect::setAudioSource(const AudioSource& source) {
    return mEffect->setAudioSource(source);
}

Return<Result> VirtualizerEffect::setDevice(const DeviceAddress& device) {
    return mEffect->setDevice(device);
}

Return<Result> VirtualizerEffect::setInputDevice(const DeviceAddress& device) {
    return mEffect->setInputDevice(device);
}
#endif

Return<void> VirtualizerEffect::setAndGetVolume(const hidl_vec<uint32_t>& volumes,
                                                setAndGetVolume_cb _hidl_cb) {
    return mEffect->setAndGetVolume(volumes, _hidl_cb);
}

Return<Result> VirtualizerEffect::volumeChangeNotification(const hidl_vec<uint32_t>& volumes) {
    return mEffect->volumeChangeNotification(volumes);
}

Return<Result> VirtualizerEffect::setAudioMode(AudioMode mode) {
    return mEffect->setAudioMode(mode);
}

Return<Result> VirtualizerEffect::setConfigReverse(
    const EffectConfig& config, const sp<IEffectBufferProviderCallback>& inputBufferProvider,
    const sp<IEffectBufferProviderCallback>& outputBufferProvider) {
    return mEffect->setConfigReverse(config, inputBufferProvider, outputBufferProvider);
}

Return<void> VirtualizerEffect::getConfig(getConfig_cb _hidl_cb) {
    return mEffect->getConfig(_hidl_cb);
}

Return<void> VirtualizerEffect::getConfigReverse(getConfigReverse_cb _hidl_cb) {
    return mEffect->getConfigReverse(_hidl_cb);
}

Return<void> VirtualizerEffect::getSupportedAuxChannelsConfigs(
    uint32_t maxConfigs, getSupportedAuxChannelsConfigs_cb _hidl_cb) {
    return mEffect->getSupportedAuxChannelsConfigs(maxConfigs, _hidl_cb);
}

Return<void> VirtualizerEffect::getAuxChannelsConfig(getAuxChannelsConfig_cb _hidl_cb) {
    return mEffect->getAuxChannelsConfig(_hidl_cb);
}

Return<Result> VirtualizerEffect::setAuxChannelsConfig(const EffectAuxChannelsConfig& config) {
    return mEffect->setAuxChannelsConfig(config);
}

Return<Result> VirtualizerEffect::offload(const EffectOffloadParameter& param) {
    return mEffect->offload(param);
}

Return<void> VirtualizerEffect::getDescriptor(getDescriptor_cb _hidl_cb) {
    return mEffect->getDescriptor(_hidl_cb);
}

Return<void> VirtualizerEffect::prepareForProcessing(prepareForProcessing_cb _hidl_cb) {
    return mEffect->prepareForProcessing(_hidl_cb);
}

Return<Result> VirtualizerEffect::setProcessBuffers(const AudioBuffer& inBuffer,
                                                    const AudioBuffer& outBuffer) {
    return mEffect->setProcessBuffers(inBuffer, outBuffer);
}

Return<void> VirtualizerEffect::command(uint32_t commandId, const hidl_vec<uint8_t>& data,
                                        uint32_t resultMaxSize, command_cb _hidl_cb) {
    return mEffect->command(commandId, data, resultMaxSize, _hidl_cb);
}

Return<Result> VirtualizerEffect::setParameter(const hidl_vec<uint8_t>& parameter,
                                               const hidl_vec<uint8_t>& value) {
    return mEffect->setParameter(parameter, value);
}

Return<void> VirtualizerEffect::getParameter(const hidl_vec<uint8_t>& parameter,
                                             uint32_t valueMaxSize, getParameter_cb _hidl_cb) {
    return mEffect->getParameter(parameter, valueMaxSize, _hidl_cb);
}

Return<void> VirtualizerEffect::getSupportedConfigsForFeature(
    uint32_t featureId, uint32_t maxConfigs, uint32_t configSize,
    getSupportedConfigsForFeature_cb _hidl_cb) {
    return mEffect->getSupportedConfigsForFeature(featureId, maxConfigs, configSize, _hidl_cb);
}

Return<void> VirtualizerEffect::getCurrentConfigForFeature(uint32_t featureId, uint32_t configSize,
                                                           getCurrentConfigForFeature_cb _hidl_cb) {
    return mEffect->getCurrentConfigForFeature(featureId, configSize, _hidl_cb);
}

Return<Result> VirtualizerEffect::setCurrentConfigForFeature(uint32_t featureId,
                                                             const hidl_vec<uint8_t>& configData) {
    return mEffect->setCurrentConfigForFeature(featureId, configData);
}

Return<Result> VirtualizerEffect::close() {
    return mEffect->close();
}

Return<void> VirtualizerEffect::debug(const hidl_handle& fd, const hidl_vec<hidl_string>& options) {
    return mEffect->debug(fd, options);
}

// Methods from ::android::hardware::audio::effect::CPP_VERSION::IVirtualizerEffect follow.
Return<bool> VirtualizerEffect::isStrengthSupported() {
    bool halSupported = false;
    mEffect->getParam(VIRTUALIZER_PARAM_STRENGTH_SUPPORTED, halSupported);
    return halSupported;
}

Return<Result> VirtualizerEffect::setStrength(uint16_t strength) {
    return mEffect->setParam(VIRTUALIZER_PARAM_STRENGTH, strength);
}

Return<void> VirtualizerEffect::getStrength(getStrength_cb _hidl_cb) {
    return mEffect->getIntegerParam(VIRTUALIZER_PARAM_STRENGTH, _hidl_cb);
}

Return<void> VirtualizerEffect::getVirtualSpeakerAngles(
#if MAJOR_VERSION <= 6
        AudioChannelBitfield mask, AudioDevice device, getVirtualSpeakerAngles_cb _hidl_cb) {
    audio_channel_mask_t halChannelMask = static_cast<audio_channel_mask_t>(mask);
    audio_devices_t halDeviceType = static_cast<audio_devices_t>(device);
#else
        const AudioChannelMask& mask, const DeviceAddress& device,
        getVirtualSpeakerAngles_cb _hidl_cb) {
    audio_channel_mask_t halChannelMask;
    if (status_t status = HidlUtils::audioChannelMaskToHal(mask, &halChannelMask);
        status != NO_ERROR) {
        _hidl_cb(mEffect->analyzeStatus(__func__, "audioChannelMaskToHal",
                                        Effect::sContextConversion, status),
                 SpeakerAngles{});
        return Void();
    }
    audio_devices_t halDeviceType;
    char halDeviceAddress[AUDIO_DEVICE_MAX_ADDRESS_LEN];
    if (status_t status = HidlUtils::deviceAddressToHal(device, &halDeviceType, halDeviceAddress);
        status != NO_ERROR) {
        _hidl_cb(mEffect->analyzeStatus(__func__, "deviceAddressToHal", Effect::sContextConversion,
                                        status),
                 SpeakerAngles{});
        return Void();
    }
#endif
    uint32_t channelCount = audio_channel_count_from_out_mask(halChannelMask);
    size_t halSpeakerAnglesSize = sizeof(int32_t) * 3 * channelCount;
    uint32_t halParam[3] = {VIRTUALIZER_PARAM_VIRTUAL_SPEAKER_ANGLES, halChannelMask,
                            halDeviceType};
    SpeakerAngles speakerAngles;
    status_t status = NO_ERROR;
    Result retval = mEffect->getParameterImpl(
            sizeof(halParam), halParam, halSpeakerAnglesSize,
            [&](uint32_t valueSize, const void* valueData) {
                if (valueSize < halSpeakerAnglesSize) {
                    channelCount = valueSize / (sizeof(int32_t) * 3);
                }
                status = speakerAnglesFromHal(reinterpret_cast<const int32_t*>(valueData),
                                              channelCount, speakerAngles);
            });
    if (retval == Result::OK) {
        retval = mEffect->analyzeStatus(__func__, "speakerAnglesFromHal", "", status);
    }
    _hidl_cb(retval, speakerAngles);
    return Void();
}

Return<void> VirtualizerEffect::getVirtualizationMode(getVirtualizationMode_cb _hidl_cb) {
    uint32_t halMode = 0;
    Result retval = mEffect->getParam(VIRTUALIZER_PARAM_FORCE_VIRTUALIZATION_MODE, halMode);
#if MAJOR_VERSION <= 6
    _hidl_cb(retval, AudioDevice(halMode));
#else
    DeviceAddress device;
    (void)HidlUtils::deviceAddressFromHal(static_cast<audio_devices_t>(halMode), nullptr, &device);
    _hidl_cb(retval, device);
#endif
    return Void();
}

Return<Result> VirtualizerEffect::forceVirtualizationMode(
#if MAJOR_VERSION <= 6
        AudioDevice device) {
    audio_devices_t halDeviceType = static_cast<audio_devices_t>(device);
#else
        const DeviceAddress& device) {
    audio_devices_t halDeviceType;
    char halDeviceAddress[AUDIO_DEVICE_MAX_ADDRESS_LEN];
    (void)HidlUtils::deviceAddressToHal(device, &halDeviceType, halDeviceAddress);
#endif
    return mEffect->setParam(VIRTUALIZER_PARAM_FORCE_VIRTUALIZATION_MODE, halDeviceType);
}

#if MAJOR_VERSION <= 6
// static
status_t VirtualizerEffect::speakerAnglesFromHal(const int32_t* halAngles, uint32_t channelCount,
                                                 hidl_vec<SpeakerAngle>& speakerAngles) {
    speakerAngles.resize(channelCount);
    for (uint32_t i = 0; i < channelCount; ++i) {
        speakerAngles[i].mask = AudioChannelBitfield(*halAngles++);
        speakerAngles[i].azimuth = *halAngles++;
        speakerAngles[i].elevation = *halAngles++;
    }
    return NO_ERROR;
}
#else
static int compare_channels(const void* lhs, const void* rhs) {
    return *(int32_t*)lhs - *(int32_t*)rhs;
}

// static
status_t VirtualizerEffect::speakerAnglesFromHal(const int32_t* halAngles, uint32_t channelCount,
                                                 SpeakerAngles& speakerAngles) {
    speakerAngles.azimuth.resize(channelCount);
    speakerAngles.elevation.resize(channelCount);
    int32_t halAnglesSorted[channelCount * 3];
    memcpy(halAnglesSorted, halAngles, sizeof(halAnglesSorted));
    // Ensure that channels are ordered from LSb to MSb.
    qsort(halAnglesSorted, channelCount, sizeof(int32_t) * 3, compare_channels);
    audio_channel_mask_t halMask = AUDIO_CHANNEL_NONE;
    int32_t* halAnglesPtr = halAnglesSorted;
    for (uint32_t i = 0; i < channelCount; ++i) {
        halMask = static_cast<audio_channel_mask_t>(halMask | *halAnglesPtr++);
        speakerAngles.azimuth[i] = *halAnglesPtr++;
        speakerAngles.elevation[i] = *halAnglesPtr++;
    }
    return HidlUtils::audioChannelMaskFromHal(halMask, false /*isInput*/, &speakerAngles.mask);
}
#endif

}  // namespace implementation
}  // namespace CPP_VERSION
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
