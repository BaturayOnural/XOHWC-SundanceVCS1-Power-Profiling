#!/bin/bash
echo 0 > /sys/class/fpga_manager/fpga0/flags
cp xohwc_mmult_power.bit.bin /lib/firmware/
echo xohwc_mmult_power.bit.bin > /sys/class/fpga_manager/fpga0/firmware