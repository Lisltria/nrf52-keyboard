## 写在最前：Mitosis-Pro

由于出差需求，需要便携的分体式键盘，ergodone太大了，mitosis比较符合需求
mitosis 键盘是一个伟大的设计，配合<s>嘉立创免费打样</s>,可以轻松将硬件成本限制在200RMB。但是过于简陋。
本版本的 mitosis 键盘增加了如下特性：

-标配200mAh锂电（当然如果焊一个大容量电池也没问题），代替原设计的2032纽扣电池，不再需要麻烦地换电池；
-带有充放电管理模块，整机工作电流约0.8mA(左手主控), 0.67mA（右手主控）
-使用nrf52832主控，集成tmk键盘固件，支持dfu功能，相比原版mitosis节省了一个接收器
-带有硬件开关，关机更省电
-TYPE-C充电口，支持jlink调试

最后感谢nrf52-keyboard项目的支持，后续内容为相关的编译和配置，本文的项目为 mitosis-pro
![Mitosis-pro](https://github.com/Lisltria/nrf52-mitosis-pro/blob/Mitosis-Pip-Master-dev/mitosis.jpg)

## 概述
这是一个基于nrf52蓝牙键盘的固件，使用了nRF SDK 15.3作为底层硬件驱动，并使用TMK键盘库作为键盘功能的上部实现。

## 目录结构
- application/ 固件相关
  - main/ 主程序
    - src/ 源码
      - ble/ 蓝牙相关代码
      - config/ 硬件配置相关
      - protocol/ 通讯相关
      - driver/ 外置驱动
      - tmk/ tmk桥接相关
    - project/ 工程
  - bootloader/ 
    - src/ 源码
    - project/ 工程
- keyboard/ 各个键盘实现相关
- SDK/ nRF52 SDK
- tmk/ tmk core 相关
- usb/ USB部分代码

## 分支说明

- Master 分支是不稳定的分支，可能存在一些BUG
- Develop 分支是更不稳定的分支，可能会出现无法编译通过的问题

若想要日常使用，建议使用Release版本

## 功能亮点

- 蓝牙/USB双模切换
- USB全键无冲
- 配列下载更新
- 电量上传
- 支持多媒体按键和鼠标键
- 支持按键宏
- 耗电量低至200ua（使用lot60-ble硬件在关闭所有灯光条件下测得，不代表所有条件下的状态）
- 高度自定义的事件系统
- 支持旋钮、WS2812等外设（详见drivers目录）

## 硬件支持

当前支持nrf52810和nrf52832两种主控硬件，此固件支持的键盘列表见Keyboard目录。

## 编译

首先下载 [nRF5 SDK 15.3](https://www.nordicsemi.com/Software-and-Tools/Software/nRF5-SDK/Download#infotabs), 解压并放入SDK文件夹。
然后安装 gcc-arm-none-eabi-7-2018-q2-update，将template目录中对应平台的配置文件模板复制一份，重命名为`Makefile.posix`或`Makefile.windows`，修改里面工具路径为你的安装目录。

然后安装 [SDCC](http://sdcc.sourceforge.net/) 用于编译CH554相关代码。

### Bootloader 的编译
参见[这篇文章](https://devzone.nordicsemi.com/b/blog/posts/getting-started-with-nordics-secure-dfu-bootloader)，先编译uECC库，然后再编译Bootloader

```bash
cd application/bootloader/project
make SOFTDEVICE=S132 NRF_CHIP=nrf52832 NRF52_DISABLE_FPU=yes -j # nrf52832的编译命令
make SOFTDEVICE=S112 NRF_CHIP=nrf52810 -j # nrf52810的编译命令
```
也可以直接参照下面的编译。

### 蓝牙程序和USB控制器的编译
现在蓝牙和USB控制器程序的Makefile都放在一起了。进入对应的硬件目录，直接make即可。

```bash
cd keyboard/lot60-ble
make # 编译主程序和USB控制程序
make bootloader # 编译bootloader
```

### 硬件的烧录

对于nrf52，若要通过JLink直接写入，则需要安装JLink的驱动；若使用DAP-Link写入，则需要安装[pyocd](https://github.com/mbedmicro/pyOCD)；若使用蓝牙DFU进行升级，则需要安装[nrfutil](https://github.com/NordicSemiconductor/pc-nrfutil/)

对于ch554，你可以使用官方的[windows烧写工具](http://www.wch.cn/downloads/WCHISPTool_Setup_exe.html)，或三方的[usbisp](https://github.com/rgwan/librech551)烧写。

请使用`make help`查看所有的烧写和打包指令。

### 详细教程

如果对上面的固件编译流程有问题，可参考Lotlab Wiki上的[这篇文章](https://wiki.lotlab.org/ble/upgrade.html)，或查看`.travis.yml`作为参考。

## 硬件移植
请参考Keyboard目录下的template移植模板，并查看doc目录下的对应说明。

## 捐助

如果你觉得这个工程有帮助到你，为何不请我喝一杯奶茶呢？

![支付宝二维码 donate@lotlab.org](https://raw.githubusercontent.com/Lotlab/mcsgyz/gh-pages/pic/alipay.jpg)
