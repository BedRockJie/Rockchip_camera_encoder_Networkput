<!--
 * @Description: 
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2022-03-20 12:00:00
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-03-25 22:56:51
 * @Author: Bedrock
 * @FilePath: /bedrock_encoder/README.md
 * 版权声明
-->
# RK3566编码网络推流软件包
使用rockchip硬件mpp进行编码，使用软件已经封装好的一层rockit接口来调用mpp进行编码。


文件目录说明：
```
├── build 本机build环境，可直接离线编译，所需动态库都已依赖到lib目录，不依赖SDK。
├── buildroot Buildroot编译相关配置，参考其中说明加入buildroot工程进行编译。
├── CMakeLists.txt 项目配置文件，Buidroot调用入口，同时也使用Cmake来进行独立编译。cmake version >= 3.1.0
├── control 控制程序目录
├── encoder 编码程序目录
├── inc 头文件目录(外部依赖，非外部依赖不对外可见)
├── lib 使用软件包(库)目录
├── main.cpp 程序入口
├── README.md
├── rtsp 推流程序入口
└── test 相关测试程序(调试)
```

# 项目生成文件
main - Bedrock_encoder
bedrock_control debug_log_test - libbedrock_lib.so
libbedrock_encoder.a 编码函数生成的动态库文件(test中未直接使用)


# 依赖软件包
注意：因为作者已经将项目软件包包含在项目中了，所以不需要在文件系统中重新编译软件包，软件包更新后可能会导致项目无法执行，作者推荐将本仓库中编译出来的动态库直接拷贝到目标板文件系统中（原因是作者没有在工程中指定安装该动态库到目标板）
- rockit
- libconfig

# 有关test的说明
在后面的测试中因为间隔时间较长，所以不对源码做太多修改，所以使用本地的软件包进行功能测试验证。
```
├── bedrock_cfgf_test.cpp libconfig库的测试test
├── bedrock_mpi.cfg 读取的cfg文件，会被安装在/usr/bin/目录下
├── bedrock_mpi_vi_test.cpp 采集camera并编码推流文件
├── bedrock_test.cpp 读取本地文件并推流
├── CMakeLists.txt
└── debug_log_test.c 创建仓库时的文件
```

v4l2-ctl -d /dev/video0 --set-fmt-video=width=1920,height=1080,pixelformat=NV12  --stream-mmap=3 --stream-skip=3 --stream-to=rk628.yuv --stream-count=1 --stream-poll