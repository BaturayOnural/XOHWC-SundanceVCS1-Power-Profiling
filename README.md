# Power Profiling custom application on VCS-1 <br>
**Team Members:** Ivica Matic, Erhan Baturay Onural <br>
**Team Number:** xohw21-149 <br>
**Supervisor:** Pedro Miguel Baptista Machado <br>

Table of Contents
=================

* [Power Profiling custom application on VCS-1 <br>](#power-profiling-custom-application-on-vcs-1-)
* [Introduction](#introduction)
* [Requirements](#requirements)
   * [HW Requirements](#hw-requirements)
   * [SW Requirements](#sw-requirements)
* [Installation &amp; Building](#installation--building)
   * [Lynsyn Installation](#lynsyn-installation)
   * [Create &amp; Build SDx Project](#create--build-sdx-project)
* [Measure the power consumption of the PL + PS](#measure-the-power-consumption-of-the-pl--ps)
* [Power usage of similar edge devices](#power-usage-of-similar-edge-devices)

# Introduction
This repository includes an end-to-end demonstration on how to power profile a custom application on VCS-1 using Lynsyn power profiler. Our example runs on a petalinux operating system running on the ARM processor of the VCS-1. During our power profiling session,  a matrix multiplication application will be running on the both PS and the PL side. The difference of performance  will be given in terms of clock cycles. Finally we will measure the total power usage of PS and PL and compare it to the power consumption of other relevant edge devices.
# Requirements
This repository has several hardware and software requirements. The hardware device and software tools must be installed in order to work with the project properly. The tools and devices are listed below. Make sure SDx and Petalinux versions are matching.
## HW Requirements
Sundance VCS-1
Lynsyn Lite
## SW Requirements
Xilinx SDx 2018.2(or newer)
Petalinux 2018.2(or newer)
# Installation & Building
In order to work with the project, the Lynsyn device should be properly installed. After configuring the installation of the Lynsyn, you can move building the SDx project.
## Lynsyn Installation
The Lynsyn power measurement units perform power profiling of applications running on ARM Cortex A based systems. Although designed for ARM systems, it can be used as a generic power profiling tool.

1. Navigate to the lynsyn-host-software folder
2. Install necessary dependencies
(Ubuntu 18.04 and before:)
```bash
sudo apt install build-essential qt5-default libqt5sql5-sqlite libusb-1.0 git
```
(Ubuntu 20.04)
```bash
sudo apt install build-essential qt5-default libqt5sql5-sqlite libusb-1.0-0-dev git
```
3. Compile
```bash
make
```
4. Install
```bash
sudo make install
```
5. Open lynsyn_viewer (Linux shortcut)
<kbd>Alt</kbd> + <kbd>F2</kbd>
type lynsyn_viewer
 hit  <kbd>Enter</kbd>
 
 The lynsyn_viewer application should be looking like this:

![](https://github.com/BaturayOnural/XOHWC-SundanceVCS1-Power-Profiling/tree/main/pictures_visuals/lynsyn_viewer.png)

> Lynsyn_viewer app.

## Create & Build SDx Project
Creating SDx project is  relatively straightforward with using custom platform. After defining custom platform and including source files the project should be ready to be built.

1. Open Xilinx SDx
2. Create new SDx Project
3. Select Application Project and type a project name
4. Click Add Custom Platform
5. Select folder TE0820_zusys_SDSoC under the platform_and_sources folder
6. Software platform and domain configuration should be made for you, hit next
7. Click Finish

The project should be appearing at the left side of the SDx. The current project includes hardware configuration but lacks the software needed for the SDK. To import necessary source files: 

1. Right click the src folder in the project
2. Select Import Sources
3. Select folder src/mmult_array_partition under the platform_and_sources folder

Now our project includes all our necessary hw and sw sources, we can proceed forward to building the project.

**Make sure you check petalinux installation path is configured properly for SDx in order to produce a petalinux image for our board. You should also mark the Generate SD Image box before building the project.**

You can now build the project by right clicking the project folder and selecting Build Project. After this process ends, our project will be ready to run the VCS-1 Board. Copy the generated SD Card files to an SD card and plug the SD card to the FPGA. (username:root- password:root)

After booting the petalinux on the VCS, our generated .elf file is ready to be executed. Our application computes matrix multiplication on the PL and the PS side, and it measures the running time of itself in terms of clock cycles. 

1. Run the .elf file

Expected output should be looking like this:

![](https://github.com/BaturayOnural/XOHWC-SundanceVCS1-Power-Profiling/tree/main/pictures_visuals/speed_up_mmult.png)

>Speed up comparison of PL and PS.

# Measure the power consumption of the PL + PS
In order to measure the power consumption, we need to run the lynsyn host application in our host PC. Sampling needs to be enabled while the application is running on the board. Simplest method would be running the lynsyn_viewer and to start sampling for a period of time. Make sure that you have plugged your Lynsyn device to your host computer before sampling.

1. Open lynsyn_viewer
2. Click Profile
3. Set an appropriate duration for your application.
4. Click OK.

Lynsyn is now sampling the power consumption, you may run your application in your VCS board.

After lynsyn sampling has finished the output should be looking like this:

![](https://github.com/BaturayOnural/XOHWC-SundanceVCS1-Power-Profiling/tree/main/pictures_visuals/lynsyn_sensor1_power.png)

>Sensor1 Power.

![](https://github.com/BaturayOnural/XOHWC-SundanceVCS1-Power-Profiling/tree/main/pictures_visuals/lynsyn_sensor1_voltage.png)

>Sensor1 Voltage.

![](https://github.com/BaturayOnural/XOHWC-SundanceVCS1-Power-Profiling/tree/main/pictures_visuals/lynsyn_sensor1_current.png)

>Sensor1 Current.

A video demonstration of power consumption sampling is available in our Youtube video.

Note that sensor1 is directly connected to a rail which is feeding the PS and the PL:

![](https://github.com/BaturayOnural/XOHWC-SundanceVCS1-Power-Profiling/tree/main/pictures_visuals/power_dist.png)

>Sensor1 corresponds to VIN in the schematics.

Therefore our application is consuming around ~2.5 W power which is not a bad power number at all!
# Power usage of similar edge devices
Edge devices are popular for their low-power and high throughput capabilities, therefore understanding where our solution fits in the current ecosystem is important. Everyday the applications are getting bigger in data-wise and therefore consuming more power due to requirement of larger computations, data movements etc. 


![](https://github.com/BaturayOnural/XOHWC-SundanceVCS1-Power-Profiling/tree/main/pictures_visuals/power-usage-environment.png)

>Sensor1 corresponds to VIN in the schematics.

Perhaps tracking power usage is much more important these days to enable more power efficient designs in the near future! We hope that this study expresses its motivatitions well and is understandable for everybody. Do not hesitate to reach us if you have any questions or ideas.
















