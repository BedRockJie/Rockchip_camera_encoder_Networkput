##################################################
###########
#
### bedrock_encoder
#
##################################################
###########
ifeq ($(BR2_PACKAGE_BEDROCK_ENCODER), y)

        BEDROCK_ENCODER_VERSION:=1.0.0
        BEDROCK_ENCODER_SITE=$(TOPDIR)/../external/bedrock_encoder
        BEDROCK_ENCODER_SITE_METHOD=local
        BEDROCK_ENCODER_INSTALL_STAGING = YES
        UVC_APP_DEPENDENCIES = libdrm mpp
#
# 框架编译时自动执行
#
# define BEDROCK_ENCODER_BUILD_CMDS
#         $(TARGET_MAKE_ENV) $(MAKE) CC=$(TARGET_CC) CXX=$(TARGET_CXX) -C $(@D)
# endef
# #
# # clean时自动执行
# #
# define BEDROCK_ENCODER_CLEAN_CMDS
#         $(TARGET_MAKE_ENV) $(MAKE) -C $(@D) clean
# endef
# #
# # 编译完成安装自动执行
# #
# define BEDROCK_ENCODER_INSTALL_TARGET_CMDS
#         $(TARGET_MAKE_ENV) $(MAKE) -C $(@D) install
# endef

# #
# # buildroot卸载package执行的参数
# #
# define BEDROCK_ENCODER_UNINSTALL_TARGET_CMDS
#         $(TARGET_MAKE_ENV) $(MAKE) -C $(@D) uninstall
# endef

$(eval $(cmake-package))
endif
