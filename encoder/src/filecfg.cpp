/*** 
 * @Description: 文件参数解析
 * @Version: 2.0
 * @Autor: Bedrock
 * @Date: 2022-01-13 11:47:39
 * @LastEditors: Bedrock
 * @LastEditTime: 2022-03-19 10:44:23
 * @Author: Bedrock
 * @FilePath: /bedrock_encoder/encoder/src/filecfg.cpp
 * @版权声明
 */
#include <stdio.h>
#include <stdlib.h>
#include "libconfig.h"
#include "bedrock_enc.h"

#define CFG_CONFIG_TEST_FILE "example.cfg"
#define CFG_DEFAULT_FILE_NAME "/usr/bin/bedrock_mpi.cfg"
int init_argc_for_cfg(Bedrock_VENC_CTX_S *p, const char *cfg_filename)
{
    config_t cfg;
    config_setting_t *setting;
    const char* str;

    config_init(&cfg);
    if (cfg_filename == NULL) {
        RK_PRINT("Input file name is NULL, Using Default file\n");
        cfg_filename = CFG_DEFAULT_FILE_NAME;
    }
    if (!config_read_file(&cfg, cfg_filename)) {
        RK_PRINT("%s:%d - %s\n", config_error_file(&cfg),
                 config_error_line(&cfg), config_error_text(&cfg));
        config_destroy(&cfg);
        return RK_ERR_NULL_PTR;
    }
    if (config_lookup_string(&cfg, "name", &str))
        printf("Store name: %s\n\n", str);
    else
        fprintf(stderr, "No 'name' setting in configuration file.\n");

    setting = config_lookup(&cfg, "mpiarg.test");
    if (setting == NULL) {
        RK_PRINT("Not Find mpiarg -> test\n");
        return RK_FAILURE;
    } else {
        int count = config_setting_length(setting);
        int i;
        for (i = 0; i < count; i++) {
            int u32StreamBufCnt, u32ChNum, u32DstCodec, u32SrcWidth, u32SrcHeight;
            config_setting_t *test = config_setting_get_elem(setting, i);
            if (!(config_setting_lookup_int(test, "s32LoopCount", &p->s32LoopCount) &&
                 config_setting_lookup_int(test, "u32StreamBufCnt", &u32StreamBufCnt) &&
                 config_setting_lookup_int(test, "u32ChNum", &u32ChNum) &&
                 config_setting_lookup_int(test, "u32DstCodec", &u32DstCodec) &&
                 config_setting_lookup_string(test, "srcFileUri", &p->srcFileUri) &&
                 config_setting_lookup_string(test, "dstFilePath", &p->dstFilePath) &&
                 config_setting_lookup_int(test, "u32SrcWidth", &u32SrcWidth) &&
                 config_setting_lookup_int(test, "u32SrcHeight", &u32SrcHeight) ))
            continue;
            p->u32StreamBufCnt = u32StreamBufCnt;
            p->u32ChNum = u32ChNum;
            p->u32DstCodec = u32DstCodec;
            p->u32SrcWidth = u32SrcWidth;
            p->u32SrcHeight = u32SrcHeight;
        }
       
    }
    return RK_SUCCESS;
}

int libconfig_show_test()
{
    config_t cfg;
    config_setting_t* setting;
    const char* str;

    config_init(&cfg);

    if (!config_read_file(&cfg, CFG_CONFIG_TEST_FILE)) {
        RK_PRINT("%s:%d - %s\n", config_error_file(&cfg),
                 config_error_line(&cfg), config_error_text(&cfg));
        config_destroy(&cfg);
        return RK_ERR_NULL_PTR;
    }
    if (config_lookup_string(&cfg, "name", &str))
        printf("Store name: %s\n\n", str);
    else
        fprintf(stderr, "No 'name' setting in configuration file.\n");
    /* Output a list of all books in the inventory. */
    setting = config_lookup(&cfg, "inventory.books");
    if (setting != NULL) {
        int count = config_setting_length(setting);
        int i;

        printf("%-30s  %-30s   %-6s  %s\n", "TITLE", "AUTHOR", "PRICE", "QTY");

        for (i = 0; i < count; ++i) {
            config_setting_t* book = config_setting_get_elem(setting, i);

            /* Only output the record if all of the expected fields are present.
             */
            const char *title, *author;
            double price;
            int qty;

            if (!(config_setting_lookup_string(book, "title", &title) &&
                  config_setting_lookup_string(book, "author", &author) &&
                  config_setting_lookup_float(book, "price", &price) &&
                  config_setting_lookup_int(book, "qty", &qty)))
                continue;

            printf("%-30s  %-30s  $%6.2f  %3d\n", title, author, price, qty);
        }
        putchar('\n');
    }

    /* Output a list of all movies in the inventory. */
    setting = config_lookup(&cfg, "inventory.movies");
    if (setting != NULL) {
        unsigned int count = config_setting_length(setting);
        unsigned int i;

        printf("%-30s  %-10s   %-6s  %s\n", "TITLE", "MEDIA", "PRICE", "QTY");
        for (i = 0; i < count; ++i) {
            config_setting_t* movie = config_setting_get_elem(setting, i);

            /* Only output the record if all of the expected fields are present.
             */
            const char *title, *media;
            double price;
            int qty;

            if (!(config_setting_lookup_string(movie, "title", &title) &&
                  config_setting_lookup_string(movie, "media", &media) &&
                  config_setting_lookup_float(movie, "price", &price) &&
                  config_setting_lookup_int(movie, "qty", &qty)))
                continue;

            printf("%-30s  %-10s  $%6.2f  %3d\n", title, media, price, qty);
        }
        putchar('\n');
    }
    config_destroy(&cfg);
    return RK_SUCCESS;
}