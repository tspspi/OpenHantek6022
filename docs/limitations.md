---
layout: default
---
## Valid specs for the 6022BE/BL with [custom firmware by Ho-Ro](https://github.com/Ho-Ro/Hantek6022API).

   - The device has no internal storage (except for a small fifo buffer), all data is streamed as USB bulk transfer.
   - Supports 48, 30, 24, 16, 15, 12, 10, 8, 6, 5, 4, 3, 2, 1 MS/s and 500, 200, 100, 60 kS/s samplerates.
   - Due to the USB bandwith constraints the max usable samplerate is limited:
     Max 30 MS/s for CH1 only and max 16 MS/s for CH1+CH2 and also CH2 only - otherwise data overrun occurs.
   - The scope program works with blocks of 20000 samples.
   - Two analog input channels with 8-bit sample-width, max input voltage range is -5 V � +5 V, values outside this range are clipped (shown as minimum or maximum value).
   - For low effective sampling rates < 1 MS/s a 10X oversampling is used to increase the signal-to-noise ratio by 10 dB and to get a better voltage solution.
   - The first samples are unstable (due to the use of the ADC far outside the specifications) -> take about 2000 additional values and drop the first samples.
   - No AC coupling available, all signals are measured as DC. (Use either a BNC DC-block or the math mode "CHx AC").
   - No HW trigger available, SW trigger seaches for trigger condition and positions the trace window accordingly.
   - Can detect rising or falling edge of the signal, displayed trigger position can be at 0 � 100% of screen width.
