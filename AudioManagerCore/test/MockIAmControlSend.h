/**
 * SPDX license identifier: MPL-2.0
 *
 * Copyright (C) 2012, BMW AG
 *
 * This file is part of GENIVI Project AudioManager.
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 *
 * \author Christian Linke, christian.linke@bmw.de BMW 2011,2012
 *
 * For further information see http://www.genivi.org/.
 *
 */

#ifndef MOCKCONTROLINTERFACE_H_
#define MOCKCONTROLINTERFACE_H_

#include "IAmControl.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace am {

class MockIAmControlSend : public IAmControlSend {
 public:
  MOCK_CONST_METHOD1(getInterfaceVersion,
      void(std::string& version));
  MOCK_METHOD1(startupController,
      am_Error_e(IAmControlReceive* controlreceiveinterface));
  MOCK_METHOD0(setControllerReady,
      void());
  MOCK_METHOD1(setControllerRundown,
      void(const int16_t signal));
  MOCK_METHOD3(hookUserConnectionRequest,
      am_Error_e(const am_sourceID_t sourceID, const am_sinkID_t sinkID, am_mainConnectionID_t& mainConnectionID));
  MOCK_METHOD1(hookUserDisconnectionRequest,
      am_Error_e(const am_mainConnectionID_t connectionID));
  MOCK_METHOD2(hookUserSetMainSinkSoundProperty,
      am_Error_e(const am_sinkID_t sinkID, const am_MainSoundProperty_s& soundProperty));
  MOCK_METHOD2(hookUserSetMainSinkSoundProperties,
      am_Error_e(const am_sinkID_t sinkID, const std::vector<am_MainSoundProperty_s > &listSoundProperty));
  MOCK_METHOD2(hookUserSetMainSourceSoundProperty,
      am_Error_e(const am_sourceID_t sourceID, const am_MainSoundProperty_s& soundProperty));
  MOCK_METHOD2(hookUserSetMainSourceSoundProperties,
      am_Error_e(const am_sourceID_t sourceID, const std::vector<am_MainSoundProperty_s > &listSoundProperty));
  MOCK_METHOD1(hookUserSetSystemProperty,
      am_Error_e(const am_SystemProperty_s& property));
  MOCK_METHOD1(hookUserSetSystemProperties,
      am_Error_e(const std::vector<am_SystemProperty_s>& listSystemProperties));
  MOCK_METHOD2(hookUserVolumeChange,
      am_Error_e(const am_sinkID_t SinkID, const am_mainVolume_t newVolume));
  MOCK_METHOD2(hookUserVolumeStep,
      am_Error_e(const am_sinkID_t SinkID, const int16_t increment));
  MOCK_METHOD2(hookUserSetSinkMuteState,
      am_Error_e(const am_sinkID_t sinkID, const am_MuteState_e muteState));
  MOCK_METHOD2(hookSystemRegisterDomain,
      am_Error_e(const am_Domain_s& domainData, am_domainID_t& domainID));
  MOCK_METHOD1(hookSystemDeregisterDomain,
      am_Error_e(const am_domainID_t domainID));
  MOCK_METHOD1(hookSystemDomainRegistrationComplete,
      void(const am_domainID_t domainID));
  MOCK_METHOD2(hookSystemRegisterSink,
      am_Error_e(const am_Sink_s& sinkData, am_sinkID_t& sinkID));
  MOCK_METHOD1(hookSystemDeregisterSink,
      am_Error_e(const am_sinkID_t sinkID));
  MOCK_METHOD2(hookSystemRegisterSource,
      am_Error_e(const am_Source_s& sourceData, am_sourceID_t& sourceID));
  MOCK_METHOD1(hookSystemDeregisterSource,
      am_Error_e(const am_sourceID_t sourceID));
  MOCK_METHOD2(hookSystemRegisterConverter,
      am_Error_e(const am_Converter_s& converterData, am_converterID_t& converterID));
  MOCK_METHOD2(hookSystemRegisterGateway,
      am_Error_e(const am_Gateway_s& gatewayData, am_gatewayID_t& gatewayID));
  MOCK_METHOD1(hookSystemDeregisterConverter,
      am_Error_e(const am_converterID_t converterID));
  MOCK_METHOD1(hookSystemDeregisterGateway,
      am_Error_e(const am_gatewayID_t gatewayID));
  MOCK_METHOD2(hookSystemRegisterCrossfader,
      am_Error_e(const am_Crossfader_s& crossfaderData, am_crossfaderID_t& crossfaderID));
  MOCK_METHOD1(hookSystemDeregisterCrossfader,
      am_Error_e(const am_crossfaderID_t crossfaderID));
  MOCK_METHOD3(hookSystemSinkVolumeTick,
      void(const am_Handle_s handle, const am_sinkID_t sinkID, const am_volume_t volume));
  MOCK_METHOD3(hookSystemSourceVolumeTick,
      void(const am_Handle_s handle, const am_sourceID_t sourceID, const am_volume_t volume));
  MOCK_METHOD2(hookSystemInterruptStateChange,
      void(const am_sourceID_t sourceID, const am_InterruptState_e interruptState));
  MOCK_METHOD2(hookSystemSinkAvailablityStateChange,
      void(const am_sinkID_t sinkID, const am_Availability_s& availability));
  MOCK_METHOD2(hookSystemSourceAvailablityStateChange,
      void(const am_sourceID_t sourceID, const am_Availability_s& availability));
  MOCK_METHOD2(hookSystemDomainStateChange,
      void(const am_domainID_t domainID, const am_DomainState_e state));
  MOCK_METHOD1(hookSystemReceiveEarlyData,
      void(const std::vector<am_EarlyData_s>& data));
  MOCK_METHOD1(hookSystemSpeedChange,
      void(const am_speed_t speed));
  MOCK_METHOD2(hookSystemTimingInformationChanged,
      void(const am_mainConnectionID_t mainConnectionID, const am_timeSync_t time));
  MOCK_METHOD3(hookSystemRegisterEarlyMainConnection,
      am_Error_e(am_domainID_t domainID, const am_MainConnection_s &mainConnectionData, const am_Route_s &route));
  MOCK_METHOD2(cbAckConnect,
      void(const am_Handle_s handle, const am_Error_e errorID));
  MOCK_METHOD2(cbAckDisconnect,
      void(const am_Handle_s handle, const am_Error_e errorID));
  MOCK_METHOD2(cbAckTransferConnection,
      void(const am_Handle_s handle, const am_Error_e errorID));
  MOCK_METHOD3(cbAckCrossFade,
      void(const am_Handle_s handle, const am_HotSink_e hostsink, const am_Error_e error));
  MOCK_METHOD3(cbAckSetSinkVolumeChange,
      void(const am_Handle_s handle, const am_volume_t volume, const am_Error_e error));
  MOCK_METHOD3(cbAckSetSourceVolumeChange,
      void(const am_Handle_s handle, const am_volume_t voulme, const am_Error_e error));
  MOCK_METHOD2(cbAckSetSourceState,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(cbAckSetSourceSoundProperties,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(cbAckSetSourceSoundProperty,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(cbAckSetSinkSoundProperties,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(cbAckSetSinkSoundProperty,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD5(getConnectionFormatChoice,
      am_Error_e(const am_sourceID_t sourceID, const am_sinkID_t sinkID, const am_Route_s listRoute, const std::vector<am_CustomConnectionFormat_t> listPossibleConnectionFormats, std::vector<am_CustomConnectionFormat_t>& listPrioConnectionFormats));
  MOCK_METHOD1(confirmCommandReady,
      void(const am_Error_e error));
  MOCK_METHOD1(confirmRoutingReady,
      void(const am_Error_e error));
  MOCK_METHOD1(confirmCommandRundown,
      void(const am_Error_e error));
  MOCK_METHOD1(confirmRoutingRundown,
      void(const am_Error_e error));
  MOCK_METHOD5(hookSystemUpdateSink,
      am_Error_e(const am_sinkID_t sinkID, const am_sinkClass_t sinkClassID, const std::vector<am_SoundProperty_s>& listSoundProperties, const std::vector<am_CustomConnectionFormat_t>& listConnectionFormats, const std::vector<am_MainSoundProperty_s>& listMainSoundProperties));
  MOCK_METHOD5(hookSystemUpdateSource,
      am_Error_e(const am_sourceID_t sourceID, const am_sourceClass_t sourceClassID, const std::vector<am_SoundProperty_s>& listSoundProperties, const std::vector<am_CustomConnectionFormat_t>& listConnectionFormats, const std::vector<am_MainSoundProperty_s>& listMainSoundProperties));
  MOCK_METHOD4(hookSystemUpdateConverter,
      am_Error_e(const am_converterID_t converterID, const std::vector<am_CustomConnectionFormat_t>& listSourceConnectionFormats, const std::vector<am_CustomConnectionFormat_t>& listSinkConnectionFormats, const std::vector<bool>& convertionMatrix));
  MOCK_METHOD4(hookSystemUpdateGateway,
      am_Error_e(const am_gatewayID_t gatewayID, const std::vector<am_CustomConnectionFormat_t>& listSourceConnectionFormats, const std::vector<am_CustomConnectionFormat_t>& listSinkConnectionFormats, const std::vector<bool>& convertionMatrix));
  MOCK_METHOD3(cbAckSetVolumes,
      void(const am_Handle_s handle, const std::vector<am_Volumes_s>& listVolumes, const am_Error_e error));
  MOCK_METHOD2(cbAckSetSinkNotificationConfiguration,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(cbAckSetSourceNotificationConfiguration,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(hookSinkNotificationDataChanged,
      void(const am_sinkID_t sinkID, const am_NotificationPayload_s& payload));
  MOCK_METHOD2(hookSourceNotificationDataChanged,
      void(const am_sourceID_t sourceID, const am_NotificationPayload_s& payload));
  MOCK_METHOD2(hookUserSetMainSinkNotificationConfiguration,
      am_Error_e(const am_sinkID_t sinkID, const am_NotificationConfiguration_s& notificationConfiguration));
  MOCK_METHOD2(hookUserSetMainSourceNotificationConfiguration,
      am_Error_e(const am_sourceID_t sourceID, const am_NotificationConfiguration_s& notificationConfiguration));
  MOCK_METHOD2(hookSystemSingleTimingInformationChanged,
      void(const am_connectionID_t connectionID, const am_timeSync_t time));
  MOCK_METHOD1(removeHandle,
	  am_Error_e(const am_Handle_s handle));       
};


}  // namespace am
#endif /* MOCKCONTROLINTERFACE_H_ */
