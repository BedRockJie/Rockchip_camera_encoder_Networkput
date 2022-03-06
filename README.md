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