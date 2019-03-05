// SPDX-License-Identifier: GPL-2.0+

#include "ppresult.h"
#include <QDebug>
#include <stdexcept>

PPresult::PPresult(unsigned int channelCount) { analyzedData.resize(channelCount); }

const DataChannel *PPresult::data(ChannelID channel) const {
    if (channel >= this->analyzedData.size()) return 0;

    return &this->analyzedData[(size_t)channel];
}

DataChannel *PPresult::modifyData(ChannelID channel) { return &this->analyzedData[(size_t)channel]; }

unsigned int PPresult::sampleCount() const { return (unsigned)analyzedData[0].voltage.sample.size(); }

unsigned int PPresult::channelCount() const { return (unsigned)analyzedData.size(); }

# if 0
double DataChannel::computeAmplitude() const {
    if (voltage.sample.empty()) return 0.0;
    double minimalVoltage, maximalVoltage, averageVoltage = 0.0;
    minimalVoltage = maximalVoltage = voltage.sample[0];

    for (unsigned int position = 1; position < voltage.sample.size(); ++position) {
        averageVoltage += voltage.sample[position];
        if (voltage.sample[position] < minimalVoltage)
            minimalVoltage = voltage.sample[position];
        else if (voltage.sample[position] > maximalVoltage)
            maximalVoltage = voltage.sample[position];
    }
    return averageVoltage /= voltage.sample.size();
    return maximalVoltage - minimalVoltage;
}
#endif
