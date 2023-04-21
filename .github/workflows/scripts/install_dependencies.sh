#!/bin/bash

echo "Update"
sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get install -y libudev-dev libgl-dev libx11-xcb-dev libfontenc-dev libxaw7-dev libxcomposite-dev libxcursor-dev libxdamage-dev libxfixes-dev libxi-dev libxinerama-dev libxmu-dev libxmuu-dev libxpm-dev libxrandr-dev libxres-dev libxss-dev libxtst-dev libxv-dev libxvmc-dev libxxf86vm-dev libxcb-render-util0-dev libxcb-xkb-dev libxcb-icccm4-dev libxcb-image0-dev libxcb-keysyms1-dev libxcb-randr0-dev libxcb-shape0-dev libxcb-sync-dev libxcb-xfixes0-dev libxcb-xinerama0-dev libxcb-dri3-dev

if [ "$1" = "criterion" ]; then
    echo "Install Criterion"
    sudo apt-get install gcovr
    sudo apt-get install meson
    git clone --recursive https://github.com/Snaipe/Criterion Criterion
    cd Criterion
    meson build
    ninja -C build
    sudo ninja -C build install
    sudo ldconfig
    cd ..
fi

echo "Install submodules"
git submodule update --init --recursive
