//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2020, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------

//! @file
//! All headers for MPEG/DVB tables and descriptors.

#pragma once

#include "tsAIT.h"
#include "tsATSCEIT.h"
#include "tsBAT.h"
#include "tsCableEmergencyAlertTable.h"
#include "tsCAT.h"
#include "tsCVCT.h"
#include "tsDCCSCT.h"
#include "tsDCCT.h"
#include "tsDiscontinuityInformationTable.h"
#include "tsDSMCCStreamDescriptorsTable.h"
#include "tsEIT.h"
#include "tsETT.h"
#include "tsINT.h"
#include "tsMGT.h"
#include "tsNIT.h"
#include "tsPAT.h"
#include "tsPMT.h"
#include "tsRRT.h"
#include "tsRST.h"
#include "tsSDT.h"
#include "tsSelectionInformationTable.h"
#include "tsSpliceInformationTable.h"
#include "tsSTT.h"
#include "tsTDT.h"
#include "tsTOT.h"
#include "tsTSDT.h"
#include "tsTVCT.h"
#include "tsUNT.h"

#include "tsAACDescriptor.h"
#include "tsAdaptationFieldDataDescriptor.h"
#include "tsAFExtensionsDescriptor.h"
#include "tsAncillaryDataDescriptor.h"
#include "tsAnnouncementSupportDescriptor.h"
#include "tsApplicationDescriptor.h"
#include "tsApplicationIconsDescriptor.h"
#include "tsApplicationNameDescriptor.h"
#include "tsApplicationRecordingDescriptor.h"
#include "tsApplicationSignallingDescriptor.h"
#include "tsApplicationStorageDescriptor.h"
#include "tsApplicationUsageDescriptor.h"
#include "tsAssociationTagDescriptor.h"
#include "tsATSCAC3AudioStreamDescriptor.h"
#include "tsATSCEAC3AudioDescriptor.h"
#include "tsATSCStuffingDescriptor.h"
#include "tsATSCTimeShiftedServiceDescriptor.h"
#include "tsAudioPreselectionDescriptor.h"
#include "tsAudioStreamDescriptor.h"
#include "tsAVCTimingAndHRDDescriptor.h"
#include "tsAVCVideoDescriptor.h"
#include "tsBouquetNameDescriptor.h"
#include "tsC2BundleDeliverySystemDescriptor.h"
#include "tsC2DeliverySystemDescriptor.h"
#include "tsCableDeliverySystemDescriptor.h"
#include "tsCADescriptor.h"
#include "tsCAIdentifierDescriptor.h"
#include "tsCaptionServiceDescriptor.h"
#include "tsCarouselIdentifierDescriptor.h"
#include "tsCellFrequencyLinkDescriptor.h"
#include "tsCellListDescriptor.h"
#include "tsCIAncillaryDataDescriptor.h"
#include "tsComponentDescriptor.h"
#include "tsComponentNameDescriptor.h"
#include "tsContentAdvisoryDescriptor.h"
#include "tsContentDescriptor.h"
#include "tsCopyrightDescriptor.h"
#include "tsCountryAvailabilityDescriptor.h"
#include "tsCPDescriptor.h"
#include "tsCPIdentifierDescriptor.h"
#include "tsCueIdentifierDescriptor.h"
#include "tsDataBroadcastDescriptor.h"
#include "tsDataBroadcastIdDescriptor.h"
#include "tsDataStreamAlignmentDescriptor.h"
#include "tsDCCArrivingRequestDescriptor.h"
#include "tsDCCDepartingRequestDescriptor.h"
#include "tsDeferredAssociationTagsDescriptor.h"
#include "tsDIILocationDescriptor.h"
#include "tsDSNGDescriptor.h"
#include "tsDTSDescriptor.h"
#include "tsDTSHDDescriptor.h"
#include "tsDTSNeuralDescriptor.h"
#include "tsDVBAC3Descriptor.h"
#include "tsDVBAC4Descriptor.h"
#include "tsDVBEnhancedAC3Descriptor.h"
#include "tsDVBHTMLApplicationBoundaryDescriptor.h"
#include "tsDVBHTMLApplicationDescriptor.h"
#include "tsDVBHTMLApplicationLocationDescriptor.h"
#include "tsDVBJApplicationDescriptor.h"
#include "tsDVBJApplicationLocationDescriptor.h"
#include "tsDVBStuffingDescriptor.h"
#include "tsDVBTimeShiftedServiceDescriptor.h"
#include "tsEacemPreferredNameIdentifierDescriptor.h"
#include "tsEacemPreferredNameListDescriptor.h"
#include "tsEacemStreamIdentifierDescriptor.h"
#include "tsEASAudioFileDescriptor.h"
#include "tsEASInbandDetailsChannelDescriptor.h"
#include "tsEASInbandExceptionChannelsDescriptor.h"
#include "tsEASMetadataDescriptor.h"
#include "tsECMRepetitionRateDescriptor.h"
#include "tsEutelsatChannelNumberDescriptor.h"
#include "tsExtendedChannelNameDescriptor.h"
#include "tsExtendedEventDescriptor.h"
#include "tsExternalApplicationAuthorizationDescriptor.h"
#include "tsExternalESIdDescriptor.h"
#include "tsFlexMuxTimingDescriptor.h"
#include "tsFMCDescriptor.h"
#include "tsFrequencyListDescriptor.h"
#include "tsFTAContentManagementDescriptor.h"
#include "tsGenreDescriptor.h"
#include "tsGraphicsConstraintsDescriptor.h"
#include "tsHDSimulcastLogicalChannelDescriptor.h"
#include "tsHEVCTimingAndHRDDescriptor.h"
#include "tsHEVCVideoDescriptor.h"
#include "tsHierarchyDescriptor.h"
#include "tsIBPDescriptor.h"
#include "tsImageIconDescriptor.h"
#include "tsIPMACGenericStreamLocationDescriptor.h"
#include "tsIPMACPlatformNameDescriptor.h"
#include "tsIPMACPlatformProviderNameDescriptor.h"
#include "tsIPMACStreamLocationDescriptor.h"
#include "tsIPSignallingDescriptor.h"
#include "tsISO639LanguageDescriptor.h"
#include "tsISPAccessModeDescriptor.h"
#include "tsLinkageDescriptor.h"
#include "tsLocalTimeOffsetDescriptor.h"
#include "tsLogicalChannelNumberDescriptor.h"
#include "tsMaximumBitrateDescriptor.h"
#include "tsMessageDescriptor.h"
#include "tsMetadataSTDDescriptor.h"
#include "tsMosaicDescriptor.h"
#include "tsMPEG2AACAudioDescriptor.h"
#include "tsMPEG2StereoscopicVideoFormatDescriptor.h"
#include "tsMPEG4AudioDescriptor.h"
#include "tsMPEG4VideoDescriptor.h"
#include "tsMultilingualBouquetNameDescriptor.h"
#include "tsMultilingualComponentDescriptor.h"
#include "tsMultilingualNetworkNameDescriptor.h"
#include "tsMultilingualServiceNameDescriptor.h"
#include "tsMultiplexBufferDescriptor.h"
#include "tsMultiplexBufferUtilizationDescriptor.h"
#include "tsMVCExtensionDescriptor.h"
#include "tsNetworkChangeNotifyDescriptor.h"
#include "tsNetworkNameDescriptor.h"
#include "tsNorDigLogicalChannelDescriptorV1.h"
#include "tsNorDigLogicalChannelDescriptorV2.h"
#include "tsNPTEndpointDescriptor.h"
#include "tsNPTReferenceDescriptor.h"
#include "tsNVODReferenceDescriptor.h"
#include "tsParentalRatingDescriptor.h"
#include "tsPartialTransportStreamDescriptor.h"
#include "tsPDCDescriptor.h"
#include "tsPrefetchDescriptor.h"
#include "tsPrivateDataIndicatorDescriptor.h"
#include "tsPrivateDataSpecifierDescriptor.h"
#include "tsProtectionMessageDescriptor.h"
#include "tsRedistributionControlDescriptor.h"
#include "tsRegistrationDescriptor.h"
#include "tsS2SatelliteDeliverySystemDescriptor.h"
#include "tsS2XSatelliteDeliverySystemDescriptor.h"
#include "tsSatelliteDeliverySystemDescriptor.h"
#include "tsSchedulingDescriptor.h"
#include "tsScramblingDescriptor.h"
#include "tsServiceAvailabilityDescriptor.h"
#include "tsServiceDescriptor.h"
#include "tsServiceIdentifierDescriptor.h"
#include "tsServiceListDescriptor.h"
#include "tsServiceLocationDescriptor.h"
#include "tsServiceMoveDescriptor.h"
#include "tsServiceRelocatedDescriptor.h"
#include "tsSHDeliverySystemDescriptor.h"
#include "tsShortEventDescriptor.h"
#include "tsShortSmoothingBufferDescriptor.h"
#include "tsSimpleApplicationBoundaryDescriptor.h"
#include "tsSimpleApplicationLocationDescriptor.h"
#include "tsSkyLogicalChannelNumberDescriptor.h"
#include "tsSLDescriptor.h"
#include "tsSmoothingBufferDescriptor.h"
#include "tsSpliceAvailDescriptor.h"
#include "tsSpliceDTMFDescriptor.h"
#include "tsSpliceSegmentationDescriptor.h"
#include "tsSpliceTimeDescriptor.h"
#include "tsSSUDataBroadcastIdDescriptor.h"
#include "tsSSUEnhancedMessageDescriptor.h"
#include "tsSSUEventNameDescriptor.h"
#include "tsSSULinkageDescriptor.h"
#include "tsSSULocationDescriptor.h"
#include "tsSSUMessageDescriptor.h"
#include "tsSSUSubgroupAssociationDescriptor.h"
#include "tsSSUURIDescriptor.h"
#include "tsSTDDescriptor.h"
#include "tsStereoscopicProgramInfoDescriptor.h"
#include "tsStereoscopicVideoInfoDescriptor.h"
#include "tsStreamEventDescriptor.h"
#include "tsStreamIdentifierDescriptor.h"
#include "tsStreamModeDescriptor.h"
#include "tsSubtitlingDescriptor.h"
#include "tsSupplementaryAudioDescriptor.h"
#include "tsSVCExtensionDescriptor.h"
#include "tsSystemClockDescriptor.h"
#include "tsT2DeliverySystemDescriptor.h"
#include "tsT2MIDescriptor.h"
#include "tsTargetBackgroundGridDescriptor.h"
#include "tsTargetIPAddressDescriptor.h"
#include "tsTargetIPSlashDescriptor.h"
#include "tsTargetIPSourceSlashDescriptor.h"
#include "tsTargetIPv6AddressDescriptor.h"
#include "tsTargetIPv6SlashDescriptor.h"
#include "tsTargetIPv6SourceSlashDescriptor.h"
#include "tsTargetMACAddressDescriptor.h"
#include "tsTargetMACAddressRangeDescriptor.h"
#include "tsTargetRegionDescriptor.h"
#include "tsTargetRegionNameDescriptor.h"
#include "tsTargetSerialNumberDescriptor.h"
#include "tsTargetSmartcardDescriptor.h"
#include "tsTelephoneDescriptor.h"
#include "tsTeletextDescriptor.h"
#include "tsTerrestrialDeliverySystemDescriptor.h"
#include "tsTimeShiftedEventDescriptor.h"
#include "tsTimeSliceFECIdentifierDescriptor.h"
#include "tsTransportProfileDescriptor.h"
#include "tsTransportProtocolDescriptor.h"
#include "tsTransportStreamDescriptor.h"
#include "tsUpdateDescriptor.h"
#include "tsURILinkageDescriptor.h"
#include "tsVBIDataDescriptor.h"
#include "tsVBITeletextDescriptor.h"
#include "tsVideoDepthRangeDescriptor.h"
#include "tsVideoStreamDescriptor.h"
#include "tsVideoWindowDescriptor.h"
