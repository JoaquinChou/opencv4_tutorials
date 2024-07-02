# 初识openCV
## openCV的发展
openCV由1999年由英特尔公司创建。
- OpenCV 1.0：2006年发布OpenCV 1.0版本，主要通过<b>C语言</b>来编写，存在内存泄漏的问题；
- OpenCV 2.0：2009年发布OpenCV 2.0版本，更新<b>C++接口</b>以及新功能代码；
- OpenCV 3.0：2014年发布OpenCV 3.0版本，大部分方法都<b>使用OpenCL加速</b    >；
- OpenCV 4.0：2018年发布OpenCV 4.0版本，需要支持C++11的编译器才能编译，更新与<b>QR code检测识别和DNN等</b>相关的功能。

# openCV4的安装
## Ubuntu中安装openCV 4.1
### openCV 4.1依赖项的安装
在ubuntu18.04的新机器上进行openCV的安装，其中opencv 4.1需要cmake 3.5.1以上。
```shell
# 更新软件源
sudo apt-get update
# 查看是否有软件需要更新
sudo apt-get upgrade
# build-essential是常用的编译工具
sudo apt-get install build-essential cmake
# 安装openCV依赖项
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev libatlas-base-dev gfortran libgtk2.0-dev libjpeg-dev libpng-dev

```
### openCV 4.1的编译和安装
opencv官方下载地址（包括文档）：https://opencv.org/releases/
```shell
# 下载opencv 4.1版本
wget https://github.com/opencv/opencv/archive/4.1.0.zip
unzip 4.1.0.zip
mv opencv-4.1.0 opencv4.1
cd opencv4.1
mkdir build
cd build

# 源码编译
# CMAKE_BUILD_TYPE:编译的模式参数
# CMAKE_INSTALL_PREFIX:安装路径
# ..:告诉编译器要编译的文件来自上一层文件夹的CMakelists.txt
sudo su
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local ..
# 启动4个线程同时进行编译
sudo make -j4
# 编译完成后进行安装
sudo make install
```

### openCV 4.1的环境变量配置
安装完openCV4.1后需要配置环境变量，告诉系统的安装位置。
```shell
sudo gedit /etc/ld.so.conf.d/opencv.conf
# 在打开文件的末尾添加openCV 4.1的编译路径
/usr/local/lib
# 配置文件生效
sudo ldconfig

# 配置bash
sudo gedit /etc/bash.bashrc
# 设置pkg-config正确地找到opencv4
sudo apt-get install pkg-config
# 在打开文件的末尾添加openCV 4.1的安装路径
PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig
export PKG_CONFIG_PATH
# 更新系统配置环境
source /etc/bash.bashrc
sudo updatedb
```
如果`/usr/local/lib/pkgconfig`不存在，则需要手动创建`pkgconfig`目录和`opencv.pc`文件。如下所示。
```shell
# 判断opencv4是否正确安装
pkg-config --cflags --libs opencv
# 如果没有pkgconfig目录
cd /usr/local/lib
ls pkgconfig     // 如果没有该文件夹，则进行创建(一般都有)
sudo mkdir pkgconfig
cd pkgconfig
sudo vim opencv.pc
```
`opencv.pc`填写以下内容。
```shell
prefix=/usr/local
exec_prefix=${prefix}
includedir=${prefix}/include
libdir=${exec_prefix}/lib

Name: opencv
Description: The opencv library
Version:4.1.0  # 可修改
Cflags: -I${includedir}/opencv4
Libs: -L${libdir} -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann  -lopencv_core
```
在通过以下命令检查是否成功安装opencv4。
```shell
pkg-config --cflags --libs opencv
```

### openCV 4.1扩展模块的安装
许多实用功能(人脸识别，特征点提取等)放到了扩展模块中。通过以下命令安装。
```shell
sudo su
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local OPENCV_EXTRA_MODULES_PATH=../opencv_contrib/modules ..
# 启动4个线程同时进行编译
sudo make -j4
# 编译完成后进行安装
sudo make install
```