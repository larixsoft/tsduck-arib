//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2021, Thierry Lelegard
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
//!
//!  @file
//!  Digital TV tuner physical device.
//!  One version of this class exists for each operating system.
//   ==> Windows implementation.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsTunerBase.h"
#include "tsModulationArgs.h"
#include "tsAbortInterface.h"
#include "tsSafePtr.h"
#include "tsReport.h"
#include "tsTunerGraph.h"

namespace ts {
    //!
    //! Digital TV tuner physical device.
    //! One version of this class exists for each operating system.
    //! @ingroup hardware
    //!
    class TSDUCKDLL TunerDevice: public TunerBase
    {
        TS_NOBUILD_NOCOPY(TunerDevice);
    public:
        //!
        //! Constructor.
        //! @param [in,out] duck TSDuck execution context.
        //!
        TunerDevice(DuckContext& duck);

        //!
        //! Destructor.
        //!
        ~TunerDevice();

        // Implementation of TunerBase.
        virtual bool open(const UString& device_name, bool info_only, Report& report) override;
        virtual bool close(Report& report) override;
        virtual bool isOpen() const override;
        virtual bool infoOnly() const override;
        virtual const DeliverySystemSet& deliverySystems() const override;
        virtual UString deviceName() const override;
        virtual UString deviceInfo() const override;
        virtual UString devicePath() const override;
        virtual bool signalLocked(Report& report) override;
        virtual int signalStrength(Report& report) override;
        virtual int signalQuality(Report& report) override;
        virtual bool tune(ModulationArgs& params, Report& report) override;
        virtual bool start(Report& report) override;
        virtual bool stop(Report& report) override;
        virtual void abort() override;
        virtual size_t receive(TSPacket* buffer, size_t max_packets, const AbortInterface* abort, Report& report) override;
        virtual bool getCurrentTuning(ModulationArgs& params, bool reset_unknown, Report& report) override;
        virtual void setSignalTimeout(MilliSecond t) override;
        virtual void setSignalTimeoutSilent(bool silent) override;
        virtual bool setReceiveTimeout(MilliSecond t, Report& report) override;
        virtual MilliSecond receiveTimeout() const override;
        virtual void setSinkQueueSize(size_t s) override;
        virtual void setReceiverFilterName(const UString& name) override;
        virtual std::ostream& displayStatus(std::ostream& strm, const UString& margin, Report& report, bool extended = false) override;

    private:
        bool              _is_open;
        bool              _info_only;
        UString           _device_name;      // Used to open the tuner
        UString           _device_info;      // Device-specific, can be empty
        UString           _device_path;      // System-specific device path.
        MilliSecond       _signal_timeout;
        bool              _signal_timeout_silent;
        MilliSecond       _receive_timeout;
        DeliverySystemSet _delivery_systems;
        volatile bool     _aborted;          // Reception was aborted
        size_t            _sink_queue_size;  // Media sample queue size
        TunerGraph        _graph;            // The filter graph

        // Get signal strength in mdB.
        // Return true if found, false if not found.
        bool getSignalStrength_mdB(::LONG&);

        // Find one or more tuners. Exactly one of Tuner* or TunerPtrVector* must be non-zero.
        // If Tuner* is non-zero, find the first tuner (matching _device_name if not empty).
        // If _device_name is ":integer", use integer as device index in list of DVB devices.
        // If TunerPtrVector* is non- zero, find all tuners in the system.
        // Return true on success, false on error.
        static bool FindTuners(DuckContext& duck, TunerDevice*, TunerPtrVector*, Report&);

        // And let TunerBase call our FindTuners.
        friend class TunerBase;
    };
}
