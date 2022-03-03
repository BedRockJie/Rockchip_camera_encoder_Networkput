# 在FireflySDK中添加工程编译路径


1. buildroot/package/rockchip 中添加 bedrock_encoder 文件夹 复制文件夹到该位置

添加
```shell
source "package/rockchip/bedrock_encoder/Config.in"
```
到buildroot/package/rockchip/Config.in